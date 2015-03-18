/*
 * =====================================================================================
 *
 *       Filename:  test_Main.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  03/18/2015 02:58:26 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Julio Tain Sueiras (), juliosueiras@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include "unity.h"
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

#define SIZE 200

char output[BUFSIZ];

void setUp(void){


}

void tearDown(void){


}

void test_First_test_case(void){


    TEST_ASSERT_EQUAL_STRING("Hello World\n", "Hello World\n");

}
