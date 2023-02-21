/*
 ============================================================================
 Name        : test.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

extern void	eos_main(void);
int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	eos_main();
	return EXIT_SUCCESS;
}
