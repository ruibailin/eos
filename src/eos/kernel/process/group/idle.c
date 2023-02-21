
/*------------------------------------
 * idle.c
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
static	int idle_head=0;

void add_idle_grp(int pno);
void add_idle_grp(int pno)
{
	if(pno == idle_head)
		return;
	if(idle_head == 0)
		idle_head = pno;			//first process
	grp_add_pro(idle_head,pno);
}

void del_idle_grp(int pno);
void del_idle_grp(int pno)
{
	if(pno == idle_head)
	{
		idle_head = 0;
		return;
	}
	grp_del_pro(idle_head,pno);
}

void ini_idle_grp(void);
void ini_idle_grp()
{
	int i,j;
	for(i=1;i<MAX_PAT_NUM;i++)
	{
		j=get_pat_tno(i);
		if(j==IDLE_PROC)
		{
			if(idle_head==0)
				idle_head=i;	//first proc
			add_idle_grp(i);
		}
	}
}

static  int run_idle;
void	run_idle_grp(void);
void	run_idle_grp()
{

	if(idle_head == 0)
		return;						//no idle process
	if(run_idle == 0)
		run_idle=idle_head;
	run_pat_entry(run_idle,0x0L);	//every time,only schedule one idle process;
	run_idle=grp_get_pro(run_idle); //get process to run next time
}

/*================================================================*/

/* end of idle.c */
