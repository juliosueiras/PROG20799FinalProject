/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  03/18/2015 02:57:05 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Julio Tain Sueiras (), juliosueiras@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#ifdef TEST
#else
  //The target will need a main.
  //Our test runner will provide it's own and call AppMain()
  int main(void)
  {
    return AppMain();
  }
#endif // TEST

int AppMain(void){
    printf("Hello World");
    return 0;
}
