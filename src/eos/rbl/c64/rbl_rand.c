
/*------------------------------------
 * rbl_rand.c
 * Create:  2023-02-21
 * Author:  Steve Rui
 *------------------------------------
 * Record:
 *
 *
 *
 *
 *------------------------------------
 */

#include "1imp.h"

/*================================================================*/
#include <time.h>
#include <stdlib.h>
static int flag=0;
int rbl_get_rand(void);
int rbl_get_rand()
{
	int i;
	time_t t;


	/* Intializes random number generator */
	if(flag==0)
	{
		srand((unsigned) time(&t));
		flag=1;
	}

	i = rand();
	return i;
}

/*================================================================*/

/* end of rbl_rand.c */
