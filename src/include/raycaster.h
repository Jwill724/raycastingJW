#pragma once 
#include <stdint.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

typedef float    f32;
typedef double   f64;
typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t   i8;
typedef int16_t  i16;
typedef int32_t  i32;
typedef int64_t  i64;
typedef size_t   usize;
typedef ssize_t  isize;

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define SIGN(a) ((a) < 0 ? -1 : ((a) > 0 ? 1 : 0))
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

// 2D Vector
typedef struct v2_s { f32 x, y; } v2;
typedef struct v2i_s { i32 x, y; } v2i;

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    u32 pixels[SCREEN_WIDTH*SCREEN_HEIGHT];
	bool quit;
	v2 pos, dir, plane;
} State;

void render(State *state);
void rotate(State *state, f32 rotate);