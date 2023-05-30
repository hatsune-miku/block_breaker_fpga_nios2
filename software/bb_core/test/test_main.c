#include <stdio.h>

#include "framework/easytest.h"
#include "fake_env/system.h"

#include "core_game/core_game.h"
#include "core_io/core_io.h"
#include "logging/logging.h"
#include "chrono/chrono.h"


void test_proc_clear_block_data() {
    int i;

    for (i = 0; i < BLOCK_ROWS; i++) {
        g_block_data[i] = 0;
    }
}

void test_all() {
    et_test("Core Game Logics", {
        cg_init(TRUE);

        et_assert_eq(
            g_ball_x, SCREEN_WIDTH / 2, 
            "Ball X position middle"
        );
        et_assert_eq(
            g_ball_y, SCREEN_HEIGHT - 52, 
            "Ball Y position bottom"
        );
        et_assert_eq(
            g_tray_len, 128, 
            "Init tray length should be 128"
        );
        et_assert_eq(
            g_tray_pos, SCREEN_WIDTH / 2 - g_tray_len / 2, 
            "Init tray X position middle"
        );
        et_assert_eq(
            g_dx, -1.0f, 
            "Init ball X direction left"
        );
        et_assert_eq(
            g_dy, -1.0f, 
            "Init ball Y direction up"
        );
        et_assert_eq(
            g_score, 0, 
            "Init score should be 0"
        );
        et_assert_eq(
            g_level, 1,
            "Init level should be 1"
        );
        et_assert_eq(
            g_game_state, IDLE,
            "Init game state should be IDLE"
        );

        cg_handle_button(PIO_BUTTON_LEFT_BASE);

        et_assert_eq(
            g_game_state, IN_GAME,
            "Game state should be IN_GAME after key press"
        );

        test_proc_clear_block_data();
        cg_one_frame();
        cg_trigger_win();

        et_assert_eq(
            g_game_state, WIN,
            "Game state should be WIN after clear blocks"
        );

    });

    et_test("IO Logics & Util Functions", {
        et_assert_eq(
            seg_from_char(0), 0x7f & ~g_seg_segments[0],
            "Function seg_from_char test (1/3)"
        );
        et_assert_eq(
            seg_from_char('a'), 0x7f & ~g_seg_segments[10],
            "Function seg_from_char test (2/3)"
        );
        et_assert_eq(
            seg_from_char('B'), 0x7f & ~g_seg_segments[11],
            "Function seg_from_char test (3/3)"
        );

        et_assert_eq(
            reverse_bit(0x7fffffffffffU), 0xffffffffffffU,
            "Reverse bit test (1/3)"
        );
        et_assert_eq(
            reverse_bit(0), 0,
            "Reverse bit test (2/3)"
        );
        et_assert_eq(
            reverse_bit(0x1bf52), 0x80004afd8000,
            "Reverse bit test (3/3)"
        );
    });

    et_test("Failure Example", {
        et_assert(1, "This testcase is always pass");
        et_assert(0, "This testcase is always fail");
    });

}

int main(void) {
    log_info("Block Breaker Game Test");
    log_info("======================");
    log_info("Zhen Guan, Jiabao Guo");
    log_info("Memorial University ");

    test_all();
    return 0;
}
