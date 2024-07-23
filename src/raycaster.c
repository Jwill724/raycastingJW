#include "raycaster.h"
#include "map.h"
#include <math.h>
#include <stdlib.h>

static void verline(State *state, int x, int y0, int y1, u32 color) {
    for (int y = y0; y <= y1; y++) {
        state->pixels[(y * SCREEN_WIDTH) + x] = color;
    }
}

void render(State *state){
	for (int x = 0; x < SCREEN_WIDTH; x++) {
		// x coordinate in space from [-1, 1]
		const f32 xcam = (2 * (x / (f32)(SCREEN_WIDTH))) - 1;

		const v2 dir = {
			state->dir.x + state->plane.x * xcam,
			state->dir.y + state->plane.y * xcam
		};

		v2 pos = state->pos;
		v2i ipos = { (int)pos.x, (int)pos.y };

		// distance ray must travel from one x/y side to the next
		const v2 deltaDist = {
			fabsf(dir.x) < 1e-20 ? 1e30 : fabsf(1.0f / dir.x),
			fabsf(dir.y) < 1e-20 ? 1e30 : fabsf(1.0f / dir.y)
		};

        // Distance from start position to first x/y side
        v2 sideDist = {
            dir.x < 0 ? (pos.x - ipos.x) * deltaDist.x : (ipos.x + 1 - pos.x) * deltaDist.x,
            dir.y < 0 ? (pos.y - ipos.y) * deltaDist.y : (ipos.y + 1 - pos.y) * deltaDist.y
        };

		// integer step direction for x/y, calculated from overall diff
        const v2i step = { (int)sign(dir.x), (int)sign(dir.y) };

        // DDA hit
        struct { int val, side; v2 pos; } hit = { 0, 0, { 0.0f, 0.0f } };

        while(!hit.val) {
            // jump to the next map square
            if(sideDist.x < sideDist.y){
                sideDist.x += deltaDist.x;
                ipos.x += step.x;
                hit.side = 0;
            }
            else {
                sideDist.y += deltaDist.y;
                ipos.y += step.y;
                hit.side = 1;
            }
            if (worldMap[ipos.x][ipos.y] > 0) {
                hit.val = worldMap[ipos.x][ipos.y];
                hit.pos = (v2){(f32)ipos.x, (f32)ipos.y};
            }
        }

        // Calculate distance to hit perpendicular wall
        const f32 perpDist = (hit.side == 0)
            ? (ipos.x - pos.x + (1 - step.x) / 2) / dir.x
            : (ipos.y - pos.y + (1 - step.y) / 2) / dir.y;

        // calculate line height relative to screen center
        const int lineHeight = (int)(SCREEN_WIDTH/perpDist);
        const int drawStart = max((SCREEN_HEIGHT / 2) - (lineHeight / 2), 0);
        const int drawEnd = min((SCREEN_HEIGHT / 2) + (lineHeight / 2), SCREEN_HEIGHT - 1);
    
        // Clear the column
        verline(state, x, 0, drawStart - 1, 0xFF202020);
        // Draw the wall
        verline(state, x, drawStart, drawEnd, 0xFF505050);
        // Clear below the wall
        verline(state, x, drawEnd + 1, SCREEN_HEIGHT - 1, 0xFF202020);
        
        u32 color;
        switch(hit.val) {
            case 1:  color = 0xFF0000;  break; // Red
            case 2:  color = 0x00FF00;  break; // Green
            case 3:  color = 0x0000FF;  break; // Blue
            case 4:  color = 0xFFFFFF;  break; // White
            default: color = 0xFFFF00;  break; // Yellow
        }

        if (hit.side == 1) { color /= 2; }

        verline(state, x, drawStart, drawEnd, color);
	}
    // update the texture with the new pixel data
    SDL_UpdateTexture(state->texture, NULL, state->pixels, SCREEN_WIDTH * sizeof(u32));
    SDL_RenderClear(state->renderer);
    SDL_RenderCopy(state->renderer, state->texture, NULL, NULL);
    SDL_RenderPresent(state->renderer);
}

void rotate(State *state, f32 rot) {
    const v2 d = state->dir, p = state->plane;
    state->dir.x = d.x * cos(rot) - d.y * sin(rot);
    state->dir.y = d.x * sin(rot) + d.y * cos(rot);
    state->plane.x = p.x * cos(rot) - p.y * sin(rot);
    state->plane.y = p.x * sin(rot) + p.y * cos(rot);
}