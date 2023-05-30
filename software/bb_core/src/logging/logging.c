#include "logging/logging.h"

#include "sys/alt_stdio.h"

void log_error(char* format) {
    alt_printf("[ERROR] %s\n", format);
}

void log_info(char* format) {
    alt_printf("[INFO] %s\n", format);
}

