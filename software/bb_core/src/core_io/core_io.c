#include "core_io/core_io.h"
#include "chrono/chrono.h"

#include <alt_types.h>
#include <system.h>
#include <altera_avalon_pio_regs.h>

#include <stdio.h>
#include <unistd.h>
#include <string.h>


// ================
// === Variable ===
// ================

alt_u8 g_seg_segments[] = {
	// 0~9
	0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,    

	// a~z
	0x77,0x7c,0x39,0x5e,0x79,0x71,0x3d,0x76,0x0f,0x0e,
	0x75,0x38,0x37,0x54,0x5c,0x73,0x67,0x50,0x6d,0x78,
	0x1c,0x1c,0x7e,0x64,0x6e,0x59
};


static alt_u32 g_seg_bases[] = {
	PIO_HEX5_BASE, 
	PIO_HEX4_BASE, 
	PIO_HEX3_BASE, 
	PIO_HEX2_BASE, 
	PIO_HEX1_BASE, 
	PIO_HEX0_BASE
};

static alt_u8 g_numbers[] = {~0,~0,~0,~0,~0,~0};

// ================
// === Function ===
// ================
// leds

void ci_set_leds(BOOL* leds, alt_u8 n) {
	alt_u16 v = 0;
	alt_u8 i;

	for (i = 0; i < n; ++i) {
		v |= leds[i] << (n - i - 1);
	}

	IOWR_ALTERA_AVALON_PIO_DATA(PIO_LEDS_BASE, v);
}

BOOL ci_is_button_down(alt_u32 base) {
	return !IORD_ALTERA_AVALON_PIO_DATA(base);
}

#define DEFINE_BUTTON_DOWN_FUNCTION(button_name, base) \
	void ci_on_button_##button_name##_down(handler h) { \
		static alt_u32 cnt = 0; \
		if (ci_is_button_down(base)) { \
			time_warp(cnt, 0.15, { \
				h(base); \
			}); \
		} \
		else { \
			cnt = 0; \
		} \
	}

DEFINE_BUTTON_DOWN_FUNCTION(left, PIO_BUTTON_LEFT_BASE);
DEFINE_BUTTON_DOWN_FUNCTION(right, PIO_BUTTON_RIGHT_BASE);
DEFINE_BUTTON_DOWN_FUNCTION(up, PIO_BUTTON_UP_BASE);
DEFINE_BUTTON_DOWN_FUNCTION(down, PIO_BUTTON_DOWN_BASE);



// ================
// === Function ===
// ================
// segs

alt_u8 seg_from_char(alt_u8 ch) {
	alt_u8 ret = 0;
	if (0 <= ch && ch <= 9) {
		ret = g_seg_segments[ch];
	}
	else if ('0' <= ch && ch <= '9') {
		ret = g_seg_segments[ch - '0' + 10];
	}
	else if ('A' <= ch && ch <= 'Z') {
		ret = g_seg_segments[ch - 'A' + 10];
	}
	else if ('a' <= ch && ch <= 'z') {
		ret = g_seg_segments[ch - 'a' + 10];
	}
	else if (ch == ' ') {
		ret = 0;
	}
	return 0x7f & ~ret;
}

void ci_set_character(alt_u8 index, alt_u8 ch, alt_u8 refresh_now) {
	if (index < 0 || index > 5) {
		return;
	}
	g_numbers[index] = seg_from_char(ch);
	
	if (refresh_now) {
		ci_segs_event_all();
	}
}

void ci_set_number(alt_u8 section, alt_u8 number, alt_u8 refresh_now) {
	alt_u8 high = number / 10;
	alt_u8 low = number % 10;

	/*
	Equivalent to:

	if (section == 0) {
		ci_set_character(0, high);
		ci_set_character(1, low);
	}
	else if (section == 1) {
		ci_set_character(2, high);
		ci_set_character(3, low);
	}
	else if (section == 2) {
		ci_set_character(4, high);
		ci_set_character(5, low);
	}
	*/
	ci_set_character(section*2, high, 0);
	ci_set_character(section*2+1, low, 0);

	if (refresh_now) {
		ci_segs_event_all();
	}
}

void ci_set_string(
	alt_u8 from_index, 
	char* str, 
	alt_u8 refresh_now
) {
	alt_u8 len = strlen(str), i;

	if (from_index < 0) {
		return;
	}

	len = len < 6 ? len : 6;
	for (i = 0; i < 6; ++i) {
		if (i < from_index || i >= from_index+len) {
			ci_set_character(i, ' ', 0);
		}
		else {
			ci_set_character(i, *(str++), 0);
		}
	}

	if (refresh_now) {
		ci_segs_event_all();
	}
}

void ci_segs_event() {
	static alt_u8 i = 0;
	IOWR_ALTERA_AVALON_PIO_DATA(g_seg_bases[i], g_numbers[i]);
	if (++i > 5) {
		i = 0;
	}
}

void ci_segs_event_all() {
	int i;
	for (i = 0; i < 6; ++i) {
		IOWR_ALTERA_AVALON_PIO_DATA(g_seg_bases[i], g_numbers[i]);
	}
}


// ================
// === Function ===
// ================
// rand

alt_u8 ci_rand(alt_u8 min, alt_u8 max) {
	// 0~255
	alt_u8 r = IORD_ALTERA_AVALON_PIO_DATA(PIO_RANDOM_BASE);
	return r % (max - min) + min;
}


// ================
// === Function ===
// ================
// bb

alt_u32 reverse_bit(alt_u32 a) {
	a = ((a >> 1) & 0x55555555) | ((a & 0x55555555) << 1);
	a = ((a >> 2) & 0x33333333) | ((a & 0x33333333) << 2);
	a = ((a >> 4) & 0x0F0F0F0F) | ((a & 0x0F0F0F0F) << 4);
	a = ((a >> 8) & 0x00FF00FF) | ((a & 0x00FF00FF) << 8);
	a = ( a >> 16             ) | ( a               << 16);
	return a;
}

alt_u8 reverse_8bit(alt_u8 a) {
	a = ((a >> 1) & 0x55) | ((a & 0x55) << 1);
	a = ((a >> 2) & 0x33) | ((a & 0x33) << 2);
	a = ((a >> 4) & 0x0F) | ((a & 0x0F) << 4);
	return a;
}

void ci_set_block_data(alt_u8* data /*[9]*/) {
	alt_u32* gp_block_data_high = (alt_u32*)(data + 0);
	alt_u32* gp_block_data_mid = (alt_u32*)(data + 4);
	alt_u8* gp_block_data_low = (alt_u8*)(data + 8);
	
	IOWR_ALTERA_AVALON_PIO_DATA(
		PIO_BLOCK_DATA_HIGH_BASE, 
		reverse_bit(*gp_block_data_high)
	);

	IOWR_ALTERA_AVALON_PIO_DATA(
		PIO_BLOCK_DATA_MID_BASE,
		reverse_bit(*gp_block_data_mid)
	);
	
	IOWR_ALTERA_AVALON_PIO_DATA(
		PIO_BLOCK_DATA_LOW_BASE,
		reverse_8bit(*gp_block_data_low)
	);
}

void ci_set_ball_position(alt_u16 x, alt_u16 y) {
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_BALL_X_BASE, x);
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_BALL_Y_BASE, y);
}

void ci_set_tray_position(alt_u16 pos, alt_u16 len) {
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_TRAY_POS_BASE, pos);
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_TRAY_LEN_BASE, len);
}
