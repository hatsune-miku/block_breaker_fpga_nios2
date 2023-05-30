#ifndef _CORE_IO_H
#define _CORE_IO_H

#include "types/types.h"

#include <alt_types.h>


typedef void (*handler)(alt_u32);
extern alt_u8 g_seg_segments[];


void ci_set_leds(BOOL* leds, alt_u8 n);

BOOL ci_is_button_down(alt_u32 base);
void ci_on_button_left_down(handler h);
void ci_on_button_right_down(handler h);
void ci_on_button_up_down(handler h);
void ci_on_button_down_down(handler h);

void ci_set_character(alt_u8 index, alt_u8 ch, alt_u8 refresh_now);
void ci_set_number(alt_u8 section, alt_u8 number, alt_u8 refresh_now);
void ci_set_string(alt_u8 from_index, char* str, alt_u8 refresh_now);

void ci_segs_event();
void ci_segs_event_all();

void ci_set_block_data(alt_u8* data);
void ci_set_ball_position(alt_u16 x, alt_u16 y);
void ci_set_tray_position(alt_u16 pos, alt_u16 len);

alt_u8 ci_rand(alt_u8 min, alt_u8 max);
alt_u8 seg_from_char(alt_u8 ch);
alt_u32 reverse_bit(alt_u32 a);

#endif
