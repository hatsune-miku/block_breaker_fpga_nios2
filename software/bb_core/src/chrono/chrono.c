#include "chrono/chrono.h"

#include <unistd.h>

void msleep(alt_u16 msec) {
    usleep(msec * 1000);
}
