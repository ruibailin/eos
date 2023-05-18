
/*---------------------------
 * msg_proc.c
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
static  unsigned int second=0;
static  unsigned int minute=0;
static  unsigned int hour=0;

void  msg_watch_dog(void *in);
void  msg_watch_dog(void *in)
{
	int ss;
	ss=EOS_STATE();
	switch(ss)
	{
	case 0:
		EOS_SET(1,1000);
	    second=rbl_get_second();
		minute=rbl_get_minute();
		hour=rbl_get_hour();
		EOS_NEXT(1);
		break;
	case 1:
		EOS_SET(1,1000);
		second++;
		if(second == 60)
			  { second=0;minute++;}
		if(minute == 60)
		      { minute=0; hour++;}
		if(hour == 24)
			  hour=0;
		rbl_printf("\nTIME:%2d:%02d:%02d \n",hour,minute,second);
		break;
	default:
		break;
	}
}


/*------------------------------------*/
static int get_ii()
{
	int ii;
	ii=rbl_get_rand();
	ii %= 200;
	ii *= 10;
	ii += 1000;
	return ii;
}

extern int knl_get_rand(int srad);
void msg_pro1(void *ptr);
void msg_pro1(void *ptr)
{
	int ii;
	int  ss,ee,pno;
	ss=EOS_STATE();
	pno=EOS_SELF();
	ee=EOS_EVENT();

	switch(ss)
	{
	case 0:

		ii=get_ii();
		EOS_SET(1,ii);

		ii=get_ii();
		EOS_SET(2,ii);

		EOS_NEXT(1);
		break;
	case 1:
		if(ee==1)
		{
			ii=get_ii();
			EOS_SET(1,ii);

			EOS_KILL(2);
			ii=get_ii();
			EOS_SET(2,ii);

			EOS_ASEND(15,14,4,&second);
			break;
		}
		if(ee==2)
		{
			ii=get_ii();
			EOS_SET(2,ii);

			EOS_KILL(1);
			ii=get_ii();
			EOS_SET(1,ii);
			EOS_ASEND(15,16,4,&minute);
			break;
		}
		break;
	default:
		break;
	}
}



/*================================================================*/
static void test_proc(void *in)
{
	int ss,pno;
	ss=EOS_STATE();
	pno=EOS_SELF();
	if(ss==0)
	{
		printf("\nI'm created,%d",pno);
	}
	ss++;
	if(ss>20)
		ss=0;
	EOS_NEXT(ss);
}
extern int create_pcb(char *name,void (*entry)(void *),int type,int attr);
/*------------------------------------*/
void msg_pro2(void *ptr);
void msg_pro2(void *ptr)
{
	int  ss,ee,pno;
	int ii;
	ss=EOS_STATE();
	pno=EOS_SELF();
	ee=EOS_EVENT();

	switch(ee)
	{
	case 0:
		pno=create_pcb("TIME 2",test_proc,4,100);
		printf("\nCreated TIME,%d",pno);
		pno=create_pcb("TIME 2",test_proc,4,200);
		printf("\nCreated TIME,%d",pno);
		pno=create_pcb("MSG 2",test_proc,3,0);
		printf("\nCreated MSG,%d",pno);
		pno=create_pcb("MSG 2",test_proc,3,0);
		printf("\nCreated MSG,%d",pno);
		break;
	case 14:
		ii=(*(int *)ptr);
		ss=knl_get_rand(2000);
		rbl_printf("REGU %d,%d\n",ii,ss);
		break;
	case 16:
		ii=(*(int *)ptr);
		ss=knl_get_rand(2000);
		rbl_printf("RAND %d,%d\n",ii,ss);
		break;
	default:
		break;
	}
}
/*================================================================*/
/* end of msg_proc.c */
