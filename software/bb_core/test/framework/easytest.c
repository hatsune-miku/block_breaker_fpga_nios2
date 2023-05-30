/**
 * EasyTest is a simple unit testing framework that is designed for the test of this Block Breaker game only.
 * 
 * Author: Zhen Guan (zguan@mun.ca)
 * 
 * Computer Engineering, Memorial University
**/

#include "easytest.h"

#include <stdio.h>
#include <string.h>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[1;34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

#define BLUE_BACK "\033[44m"
#define GREEN_BACK "\033[42m"
#define RED_BACK "\033[41m"


#define MAX_SUBJECT_LENGTH (256)
#define TEST_STATE_LENGTH  (16)


static char g_current_subject[MAX_SUBJECT_LENGTH];
static int g_passed;
static int g_tried;


void et_subject_start(char* subject) {
    int i;

    g_tried = 0;
    g_passed = 0;

    if (subject == NULL) {
        return;
    }

    strncpy(g_current_subject, subject, MAX_SUBJECT_LENGTH-1);

    printf(
        "\n  " BLUE_BACK " TESTING " RESET BLUE " %s" RESET "\n",
        g_current_subject
    );
}

void et_subject_end() {
    if (g_passed == g_tried) {
        printf(
            "  " GREEN_BACK " PASSED " RESET " ("
            GREEN "%d" RESET
            "/"
            GREEN "%d" RESET
            " Passed).\n",
            g_passed, g_tried
        );
    }
    else {
        printf(
            "  " RED_BACK " FAILED " RESET " ("
            RED "%d" RESET
            "/"
            RED "%d" RESET
            " Passed, "
            RED "%d" RESET
            " Failed).\n",
            g_passed, g_tried, g_tried - g_passed
        );
    }
}

void et_assert(int boolean, char* message) {
    char test_state[TEST_STATE_LENGTH];

    if (boolean) {
        sprintf(test_state, GREEN "PASS" RESET);
        g_passed += 1;
    }
    else {
        sprintf(test_state, RED "FAIL" RESET);
    }
    g_tried += 1;

    printf("\t%s - %s\n", test_state, message);
}

