/**
 * EasyTest is a simple unit testing framework that is designed for the test of this Block Breaker game only.
 * 
 * Author: Zhen Guan (zguan@mun.ca)
 * 
 * Computer Engineering, Memorial University
**/

#ifndef _EASYTEXT_H
#define _EASYTEXT_H

/**
 * Switch the tesing subject.
**/
void et_subject_start(char* subject);
void et_subject_end();
#define et_test(subject, proc) {\
    et_subject_start(subject);\
    proc;\
    et_subject_end();\
};

/**
 * Assertions.
**/
void et_assert(int boolean, char* message);
#define et_assert_eq(x, y, msg) et_assert(((x) == (y)), msg)

#endif
