
/*---------------------------
 * time_proc.c
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
#include "../../rbl/rbl_api.h"
/*================================================================*/
static  unsigned int second=0;
static  unsigned int minute=0;
static  unsigned int hour=0;
static	unsigned int msec=0;
void  time_show_date(void *in);
void  time_show_date(void *in)
{
	msec++;
	if(msec<1000)
		return;
	msec=0;

    second++;
	if(second == 60)
		  { second=0;minute++;}
	if(minute == 60)
	      { minute=0; hour++;}
	if(hour == 24)
		  hour=0;
	rbl_printf("PROC:%2d:%02d:%02d  ",hour,minute,second);
}

/*---------------------------------------*/
static  int mmss=0;
void  time_01(void *in);
void  time_01(void *in)
{
	mmss++;
	if(mmss<5003)
		return;
	mmss=0;


}

/*---------------------------------------*/
static  int mmss1=0;
void  time_02(void *in);
void  time_02(void *in)
{
	mmss1++;
	if(mmss1<10005)
		return;
	mmss1=0;


}

/*================================================================*/
/* end of time_proc.c */
