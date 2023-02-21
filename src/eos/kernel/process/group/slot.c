
/*------------------------------------
 * slot.c
 * Create:  2023-02-17
 * Author:  Steve Rui
 *------------------------------------
 * Record:
 * Schedule by time slot, wait to implement in future
 *
 *
 *
 *------------------------------------
 */

#include "1imp.h"
#include "queue.h"
/*================================================================*/
static	int slot_head=0;

void add_slot_grp(int pno);
void add_slot_grp(int pno)
{
	if(pno == slot_head)
		return;
	if(slot_head == 0)
		slot_head = pno;			//first process
	grp_add_pro(slot_head,pno);
}

void del_slot_grp(int pno);
void del_slot_grp(int pno)
{
	if(pno == slot_head)
	{
		slot_head = 0;
		return;
	}
	grp_del_pro(slot_head,pno);
}

void ini_slot_grp(void);
void ini_slot_grp()
{
	int i,j;
	for(i=1;i<MAX_PAT_NUM;i++)
	{
		j=get_pat_tno(i);
		if(j==SLOT_PROC)
		{
			if(slot_head==0)
				slot_head=i;	//first proc
			add_slot_grp(i);
		}
	}
}


int	run_slot_grp(void);
int	run_slot_grp()
{
	int run;
	if(slot_head == 0)
		return 0;						//no time slot process
	run=grp_get_pro(slot_head);
//	run_pat_entry(run,0x0L);
	slot_head=run;				//only schedule in its time slot;
	return 1;
}

/*================================================================*/

/* end of slot.c */
