#ifndef _CHRONO_H
#define _CHRONO_H

#include <alt_types.h>

#define time_warp(variable, kiloperiod, proc) \
    if ((++(variable)) >= 1000*(kiloperiod)) { variable=0; proc; }

#define INTERVAL_BUTTON (25)

void msleep(alt_u16 msec);

#endif
