
/*------------------------------------
 * real.c
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
static	int real_head=0;

void add_real_grp(int pno);
void add_real_grp(int pno)
{
	if(pno == real_head)
		return;
	if(real_head == 0)
		real_head = pno;			//first process
	grp_add_pro(real_head,pno);
}

void del_real_grp(int pno);
void del_real_grp(int pno)
{
	if(pno == real_head)
	{
		real_head = 0;
		return;
	}
	grp_del_pro(real_head,pno);
}

void ini_real_grp(void);
void ini_real_grp()
{
	int i,j;
	for(i=1;i<MAX_PAT_NUM;i++)
	{
		j=get_pat_tno(i);
		if(j==REAL_PROC)
		{
			if(real_head==0)
				real_head=i;	//first proc
			add_real_grp(i);
		}
	}
}


void	run_real_grp(void);
void	run_real_grp()
{
	int run;
	run_pat_entry(0,0x0L);			//process 0 is system special process`
	if(real_head == 0)
		return;						//no real process
	run = real_head;
	for(;;)							//schedule all real process in every main loop;
	{
		run_pat_entry(run,0x0L);
		run=grp_get_pro(run);
		if(run == real_head)
			return;
	}
}

/*================================================================*/

/* end of real.c */
