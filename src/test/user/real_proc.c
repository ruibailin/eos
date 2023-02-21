
/*---------------------------
 * real_proc.c
 *  Created on: 2023?2?19?
 *      Author: Steve Rui
  *---------------------------
 *
 *
 *
 *
 *
 *---------------------------
 */

#include "1imp.h"
/*================================================================*/
static  int mmss=0;
void  real_01(void *in);
void  real_01(void *in)
{
	mmss++;
	if(mmss<500000)
		return;
	mmss=0;
}


static  int mmss1=0;
void  real_02(void *in);
void  real_02(void *in)
{
	mmss1++;
	if(mmss1<500000)
		return;
	mmss1=0;
}
/*================================================================*/
/* end of real_proc.c */
