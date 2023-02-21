
/*------------------------------------
 * time.c
 * Create:  2023-02-17
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
#include "queue.h"
/*================================================================*/
static	int time_head=0;

void add_time_grp(int pno);
void add_time_grp(int pno)
{
	if(pno == time_head)
		return;
	if(time_head == 0)
		time_head = pno;			//first process
	grp_add_pro(time_head,pno);
}

void del_time_grp(int pno);
void del_time_grp(int pno)
{
	if(pno == time_head)
	{
		time_head = 0;
		return;
	}
	grp_del_pro(time_head,pno);
}

/*================================================================*/
#define SCHEDULE_TIME	1000

static int time_delta;
static int this_us,last_us;
extern int rbl_get_usec(void);

void ini_time_grp(void);
void ini_time_grp()
{
	int i,j;
	for(i=1;i<MAX_PAT_NUM;i++)
	{
		j=get_pat_tno(i);
		if(j==TIME_PROC)
		{
			if(time_head==0)
				time_head=i;	//first proc
			add_time_grp(i);
		}
	}
	time_delta=SCHEDULE_TIME;
	this_us=rbl_get_usec();
	last_us=this_us;
}


static	int is_time_run();
static	int is_time_run()
{
	int pass_us,error;

	this_us = rbl_get_usec();
	if(this_us<last_us)
		pass_us =(int)(this_us+1000000-last_us);
	else
		pass_us =(int)(this_us-last_us);

	if(pass_us<time_delta)
		return 0;
	last_us=this_us;
	error=pass_us-SCHEDULE_TIME;
	time_delta = time_delta -error;
	return 1;
}

long int knl_run_ms=0;
int	run_time_grp(void);
int	run_time_grp()
{
	int run;

	run=is_time_run();
	if(run==0)
		return 0;
	knl_run_ms++;
	if(time_head == 0)
		return 1;				//no real process
	run = time_head;
	for(;;)						//schedule all time process in every time arrived;
	{
		run_pat_entry(run,0x0L);
		run=grp_get_pro(run);
		if(run == time_head)
			return 1;
	}
	return 1;
}
/*================================================================*/
int knl_get_rand(int srad);
int knl_get_rand(int srad)
{
	if(srad == 0)
		return 0;
	return(this_us%srad);
}
/*================================================================*/

/* end of time.c */
