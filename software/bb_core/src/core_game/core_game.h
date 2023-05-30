#ifndef _CORE_GAME_H
#define _CORE_GAME_H

#include <alt_types.h>
#include "types/types.h"


#define animated
#define SCREEN_WIDTH  (640)
#define SCREEN_HEIGHT (480)
#define BLOCK_WIDTH   (72)
#define BLOCK_HEIGHT  (24)
#define BLOCK_COUNT   (8)
#define BLOCK_ROWS    (9)
#define BALL_RADIUS   (12)
#define TRAY_HEIGHT   (16)
#define MAX_LEVEL     (3)
#define TRAY_Y        (SCREEN_HEIGHT - TRAY_HEIGHT - 4)


// Game config.
typedef enum {
    IDLE, IN_GAME, WIN, LOSE, OVER
} game_state;

extern alt_u8 g_block_data[BLOCK_ROWS];
extern game_state g_game_state;
extern alt_u16 g_tray_pos;
extern alt_u16 g_tray_len;
extern alt_u8 g_score;
extern alt_u8 g_level;
extern float g_ball_x;
extern float g_ball_y;
extern float g_dx;
extern float g_dy;

void cg_handle_button(alt_u32 base);
void cg_trigger_lose();
void cg_trigger_win();
void cg_one_frame();
void cg_init(BOOL reset_score);
void cg_main();

#endif
