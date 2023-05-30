#include "core_io/core_io.h"
#include "core_game/core_game.h"
#include "chrono/chrono.h"
#include "logging/logging.h"

#include <system.h>
#include <stdio.h>


///////////////////////////////
/// Some critical function. ///
///////////////////////////////
// Initialize the core game.

// Level generator.
static void cg_draw_level(alt_u8 level);

static void cg_anim_over();
static void cg_anim_win();
static void cg_anim_lose();


// Game states.
game_state g_game_state;

alt_u16 g_tray_pos;
alt_u16 g_tray_len;
alt_u8 g_score;
alt_u8 g_level;

float g_ball_x;
float g_ball_y;
float g_dx;
float g_dy;

alt_u8 g_block_data[BLOCK_ROWS];


/////////////////////////
/// Block operations. ///
/////////////////////////
inline static void cg_set_block_data(
    alt_u8 row, alt_u8 col, alt_u8 v
) {
    if (v == 0) {
        g_block_data[8-row] &= ~(1U << (7 - col));
    }
    else {
        g_block_data[8-row] |= (1U << (7 - col));
    }
}

inline static alt_u8 cg_get_block_data(alt_u8 row, alt_u8 col) {
    return (g_block_data[8-row] >> (7 - col) & 1);
}

static alt_u8 cg_did_hit_block(alt_u16 x, alt_u16 y, alt_u8* row, alt_u8* col) {
    *row = (y + g_dy * BALL_RADIUS) / BLOCK_HEIGHT;
    *col = (x + g_dx * BALL_RADIUS) / BLOCK_WIDTH;

    if (*row < BLOCK_ROWS && *col < BLOCK_COUNT) {
        return cg_get_block_data(*row, *col);
    }
    else {
        return 0;
    }
}

inline static alt_u8 cg_did_hit_tray(alt_u16 x, alt_u16 y) {
    return (
        (y + 2*BALL_RADIUS >= TRAY_Y)
        && (x >= g_tray_pos)
        && x <= g_tray_pos + g_tray_len
    );
}

inline static alt_u8 cg_did_hit_bottom(alt_u16 y) {
    return (y + 2*BALL_RADIUS >= SCREEN_HEIGHT);
}


static void cg_set_block_as_string(alt_u8 row, char* s, int n) {
    if (n > 8) {
        n = 8;
    }
    for (int i = 0; i < n; ++i) {
        cg_set_block_data(row, i, s[i] == '1' ? 1U : 0U);
    }
}


//////////////////////
/// Button events. ///
//////////////////////
void cg_handle_button(alt_u32 base) {
    if (g_game_state == IN_GAME) {
        if (base == PIO_BUTTON_LEFT_BASE || base == PIO_BUTTON_DOWN_BASE) {
            if (g_tray_pos > 4) {
                g_tray_pos -= 4;
            }
        }
        else if (base == PIO_BUTTON_UP_BASE) {
            if (g_tray_pos < SCREEN_WIDTH - g_tray_len - 4) {
                g_tray_pos += 4;
            }
        }
        else if (base == PIO_BUTTON_RIGHT_BASE) {
            // Cheat function
            ++g_level;

            if (g_level == MAX_LEVEL + 1) {
                cg_anim_over();
                g_game_state = OVER;
            }
            else {
                cg_anim_win();
                g_game_state = WIN;
            }
        }
    }
    else if (g_game_state == WIN) {
        g_game_state = IN_GAME;
        cg_init(FALSE);
    }
    else if (g_game_state == LOSE) {
        g_game_state = IN_GAME;
        cg_init(TRUE);
    }
    else if (g_game_state == IDLE) {
        g_game_state = IN_GAME;
        cg_init(TRUE);
    }
    else if (g_game_state == OVER) {
        g_game_state = IN_GAME;
        cg_init(TRUE);
    }
}


///////////////////
/// Animations. ///
///////////////////
static void cg_anim_lose() {    
    animated {
        ci_set_string(0, "Lose", 1);
        msleep(700);
        ci_set_string(0, "", 1);
        msleep(200);
        ci_set_string(0, "Lose", 1);
        msleep(200);
        ci_set_string(0, "", 1);
        msleep(200);
        ci_set_string(0, "Lose", 1);
    }
}

static void cg_anim_win() {  
    animated {
        ci_set_string(0, "Good", 1);
        msleep(400);
        ci_set_string(0, "", 1);
        msleep(150);
        ci_set_string(0, "Job", 1);
        msleep(400);

        ci_set_string(0, "", 1);
        msleep(150);

        ci_set_string(0, "Good", 1);
        msleep(400);
        ci_set_string(0, "", 1);
        msleep(150);
        ci_set_string(0, "Job", 1);
        msleep(400);
    }
}

static void cg_anim_over() {
        animated {
        ci_set_string(0, "Game", 1);
        msleep(400);
        ci_set_string(0, "", 1);
        msleep(150);
        ci_set_string(0, "Clear", 1);
        msleep(400);

        ci_set_string(0, "", 1);
        msleep(150);

        ci_set_string(0, "Game", 1);
        msleep(400);
        ci_set_string(0, "", 1);
        msleep(150);
        ci_set_string(0, "Clear", 1);
        msleep(400);
    }
}


///////////////////
/// Procedures. ///
///////////////////
static BOOL cg_is_win() {
    int i;
    for (i = 0; i < BLOCK_ROWS; ++i) {
        if (g_block_data[i] != 0) {
            return FALSE;
        }
    }
    return TRUE;
}

void cg_trigger_lose() {
    log_info("You Lose!");
    cg_anim_lose();
    g_game_state = LOSE;
}

void cg_trigger_win() {
    log_info("You Win!");
    ++g_level;

    if (g_level == MAX_LEVEL + 1) {
        cg_anim_over();
        g_game_state = OVER;
    }
    else {
        cg_anim_win();
        g_game_state = WIN;
    }
}

void cg_one_frame() {
    alt_u8 row_old = g_ball_y / BLOCK_HEIGHT;
    alt_u8 col_old = g_ball_x / BLOCK_WIDTH;
    alt_u8 row = 0;
    alt_u8 col = 0;

    // Move.
    g_ball_x += g_dx;
    g_ball_y += g_dy;

    // Hit bottom?
    if (cg_did_hit_bottom(g_ball_y)) {
        cg_trigger_lose();
        return;
    }
    else if (cg_did_hit_tray(g_ball_x, g_ball_y)) {
        // Hit tray.
        g_dy = -g_dy;
    }
    else if (cg_did_hit_block(g_ball_x, g_ball_y, &row, &col)) {
        // Hit block.
        ++g_score;
        cg_set_block_data(row, col, 0);

        // Win?
        if (cg_is_win()) {
            cg_trigger_win();
            return;
        }

        // Update direction.
        if (row != row_old) {
            g_dy = -g_dy;
        }
        if (col != col_old) {
            g_dx = -g_dx;
        }
    }

    // Bounce back on edge.
    if (g_ball_x <= BALL_RADIUS || g_ball_x >= SCREEN_WIDTH - BALL_RADIUS) {
        g_dx = -g_dx;
    }
    if (g_ball_y <= BALL_RADIUS || g_ball_y >= SCREEN_HEIGHT - BALL_RADIUS) {
        g_dy = -g_dy;
    }
}

static void cg_draw_level(alt_u8 level) {
    int i;

    if (level == 1) {
        for (i = 0; i < BLOCK_ROWS; ++i) {
            if (i % 2 == 0) {
                cg_set_block_as_string(i, "00101010", 8);
            }
            else {
                cg_set_block_as_string(i, "01010101", 8);
            }
        }
    }
    else if (level == 2) {
        cg_set_block_as_string(0, "01111111", 8);
        for (i = 1; i < BLOCK_ROWS - 1; ++i) {
            cg_set_block_as_string(i, "01000001", 8);
        }
        cg_set_block_as_string(BLOCK_ROWS-1, "01111111", 8);
    }
    else {
        for (i = 0; i < BLOCK_ROWS; ++i) {
            if (i % 2 == 0) {
                cg_set_block_as_string(i, "01111111", 8);
            }
            else {
                cg_set_block_as_string(i, "01010101", 8);
            }
        }
    }
}

void cg_init(BOOL reset_score) {
    int i;

    g_ball_x = SCREEN_WIDTH / 2;
    g_ball_y = SCREEN_HEIGHT - 52;

    // Init tray length.
    g_tray_len = 128;
    g_tray_pos = SCREEN_WIDTH / 2 - g_tray_len / 2;

    // Init direction.
    g_dx = -1.0f;
    g_dy = -1.0f;

    // Clear the screen.
    for (i = 0; i < BLOCK_ROWS; ++i) {
        g_block_data[i] = 0;
    }

    // Init score and level.
    if (reset_score) {
        g_level = 1;
        g_score = 0;
    }

    // Display level.
    ci_set_character(0, 'L', 0);
    ci_set_character(1, g_level, 0);
    ci_set_character(2, ' ', 0);
    ci_set_character(3, ' ', 0);

    // Draw level.
    cg_draw_level(g_level);
}

static void cg_event_lose() {
    static int i = 0, j = 0, k = 0;

    time_warp(i, 100/2, { 
        ci_set_string(0, "Better", 0);
    });

    time_warp(j, 200/2, { 
        ci_set_string(1, "Next", 0);
    });

    time_warp(k, 300/2, {
        ci_set_string(1, "Time", 0); 
        i = j = 0;
    });
}

static void cg_event_win() {
    static int i = 0, j = 0, k = 0;

    time_warp(i, 100/2, {
        ci_set_string(0, "Press", 0);
    });

    time_warp(j, 200/2, {
        ci_set_string(1, "Any", 0);
    });

    time_warp(k, 300/2, {
        ci_set_string(1, "Key", 0);
        i = j = 0;
    });
}

static void cg_event_over() {
    static int i = 0, j = 0;

    time_warp(i, 100/2, {
        ci_set_string(0, "Game", 0);
    });

    time_warp(j, 200/2, {
        ci_set_string(1, "Over", 0);
        i = 0;
    });
}

static void cg_event_in_game() {
    static int j = 0;

    ci_set_ball_position(
        (alt_u16)g_ball_x, 
        (alt_u16)g_ball_y
    );
    ci_set_tray_position(g_tray_pos, g_tray_len);
    ci_set_block_data(g_block_data);

    ci_set_number(2, g_score, 0);

    time_warp(j, 0.075, {
        cg_one_frame();
    });
}

static void cg_event_idle() {
    static int i = 0, j = 0, k = 0;
    time_warp(i, 100/2, { 
        ci_set_string(0, "Press", 0);
    });

    time_warp(j, 200/2, {
        ci_set_string(1, "Any", 0);
    });

    time_warp(k, 300/2, {
        ci_set_string(1, "Key", 0);
        i = j = 0;
    });
}

static void cg_state_dispatch() {
    switch (g_game_state) {
    case IN_GAME:
        cg_event_in_game();
        break;
        
    case LOSE:
        cg_event_lose();
        break;

    case WIN:
        cg_event_win();
        break;
        
    case IDLE:
        cg_event_idle();
        break;

    case OVER:
        cg_event_over();
        break;
    }
}

void cg_main() {
    cg_init(TRUE);
    g_game_state = IDLE;

    for (;;) {
        cg_state_dispatch();
        
        ci_on_button_left_down(cg_handle_button);
        ci_on_button_down_down(cg_handle_button);
        ci_on_button_up_down(cg_handle_button);
        ci_on_button_right_down(cg_handle_button);

        ci_segs_event();
    }
}
