#include "raycaster.h"
#include "map.h"
#include <math.h>
#include <stdlib.h>

// fills a column through vertical lines
static void verline(State *state, int x, int y0, int y1, u32 color) {
    for (int y = y0; y <= y1; y++) {
        state->pixels[(y * SCREEN_WIDTH) + x] = color;
    }
}

void render(State *state){
	for (int x = 0; x < SCREEN_WIDTH; x++) {
		// x coordinate in space from [-1, 1]
		const f32 xcam = (2 * (x / (f32)(SCREEN_WIDTH))) - 1;

        // calculates direction vector through current screen column
		const v2 dir = {
			state->dir.x + state->plane.x * xcam,
			state->dir.y + state->plane.y * xcam
		};

        // player position in the map and integer grid position
		v2 pos = state->pos;
		v2i ipos = { (int)pos.x, (int)pos.y };

		// normalizes the direction of the vector distance
		const v2 deltaDist = {
			fabsf(dir.x) < 1e-20 ? 1e30 : fabsf(1.0f / dir.x),
			fabsf(dir.y) < 1e-20 ? 1e30 : fabsf(1.0f / dir.y)
		};

        // calculates the distance from the current position to the nearest x/y side based off the vector direction
        v2 sideDist = {
            dir.x < 0 ? (pos.x - ipos.x) * deltaDist.x : (ipos.x + 1 - pos.x) * deltaDist.x,
            dir.y < 0 ? (pos.y - ipos.y) * deltaDist.y : (ipos.y + 1 - pos.y) * deltaDist.y
        };

		// integer step direction for x/y, determing which way is being moved on the grid
        const v2i step = { (int)SIGN(dir.x), (int)SIGN(dir.y) };

        // DDA checks if ray hit wall or not
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
            // sets wall to grid position, and stores values
            if (worldMap[ipos.x][ipos.y] > 0) {
                hit.val = worldMap[ipos.x][ipos.y];
                hit.pos = (v2){(f32)ipos.x, (f32)ipos.y};
            }
        }

        // calculate distance to hit perpendicular wall
        const f32 perpDist = (hit.side == 0)
            ? (ipos.x - pos.x + (1 - step.x) / 2) / dir.x
            : (ipos.y - pos.y + (1 - step.y) / 2) / dir.y;

        // calculate line height relative to screen center
        const int 
            lineHeight = (int)(SCREEN_WIDTH/perpDist),
            drawStart = MAX((SCREEN_HEIGHT / 2) - (lineHeight / 2), 0),
            drawEnd = MIN((SCREEN_HEIGHT / 2) + (lineHeight / 2), SCREEN_HEIGHT - 1);
    
        // clear the column
        verline(state, x, 0, drawStart - 1, 0xFF202020);
        // draw the wall
        verline(state, x, drawStart, drawEnd, 0xFF505050);
        // clear below the wall
        verline(state, x, drawEnd + 1, SCREEN_HEIGHT - 1, 0xFF202020);
        
        u32 color;
        switch(hit.val) {
            case 1:  color = 0xFF0000;  break; // red
            case 2:  color = 0x00FF00;  break; // green
            case 3:  color = 0x0000FF;  break; // blue
            case 4:  color = 0xFFFFFF;  break; // white
            default: color = 0xFFFF00;  break; // yellow
        }

        // if the side hit is a vertical line, then sets a darker shade
        if (hit.side == 1) { color /= 2; }

        verline(state, x, drawStart, drawEnd, color);
	}
    // update the texture with the new pixel data
    SDL_UpdateTexture(state->texture, NULL, state->pixels, SCREEN_WIDTH * sizeof(u32));
    SDL_RenderClear(state->renderer);
    SDL_RenderCopy(state->renderer, state->texture, NULL, NULL);
    SDL_RenderPresent(state->renderer);
}

// rotation matrix
void rotate(State *state, f32 rotate) {
    const v2 d = state->dir, p = state->plane;
    state->dir.x = d.x * cos(rotate) - d.y * sin(rotate);
    state->dir.y = d.x * sin(rotate) + d.y * cos(rotate);
    state->plane.x = p.x * cos(rotate) - p.y * sin(rotate);
    state->plane.y = p.x * sin(rotate) + p.y * cos(rotate);
}