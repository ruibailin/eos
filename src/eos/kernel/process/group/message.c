
/*------------------------------------
 * message.c
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
static	int msg_head=0;

void add_msg_grp(int pno);
void add_msg_grp(int pno)
{
	if(pno == msg_head)
		return;
	if(msg_head == 0)
		msg_head = pno;			//first process
	grp_add_pro(msg_head,pno);
}

void del_msg_grp(int pno);
void del_msg_grp(int pno)
{
	if(pno == msg_head)
	{
		msg_head = 0;
		return;
	}
	grp_del_pro(msg_head,pno);
}

void ini_msg_grp(void);
void ini_msg_grp()
{
	int i,j;
	for(i=1;i<MAX_PAT_NUM;i++)
	{
		j=get_pat_tno(i);
		if(j==MSG_PROC)
		{
			if(msg_head==0)
				msg_head=i;	//first proc
			add_msg_grp(i);
		}
	}
}

void run_msg_grp(void);	//only run one time
void run_msg_grp()
{
	int run;
	if(msg_head == 0)
		return;						//no message-driven process
	run = msg_head;
	for(;;)							//run all message-driven process for initialization;
	{
		run_pat_entry(run,0x0L);
		run=grp_get_pro(run);
		if(run == msg_head)
			return;
	}
}
/*================================================================*/

/* end of message.c */
