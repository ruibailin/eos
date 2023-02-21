
/*------------------------------------
 * dummy.c
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
static	int dum_head=0;

void add_dum_grp(int pno);
void add_dum_grp(int pno)
{
	if(pno == dum_head)
		return;
	grp_add_pro(dum_head,pno);
}

void del_dum_grp(int pno);
void del_dum_grp(int pno)
{
	if(pno == dum_head)
	{
		dum_head=0;
		return;
	}
	grp_del_pro(dum_head,pno);
}

void ini_dum_grp(void);
void ini_dum_grp()
{
	int i,j;
	for(i=1;i<MAX_PAT_NUM;i++)
	{
		j=get_pat_tno(i);
		if(j==DUM_PROC)
		{
			if(dum_head==0)
				dum_head=i;	//first proc
			add_dum_grp(i);
		}
	}
}

int  get_dum_grp(void);
int  get_dum_grp()
{
	int pno;
	if(dum_head == 0)
	{
		knl_print("no pat resource\n");
		knl_panic();
		return 0;
	}
	pno=grp_get_pro(dum_head);
	if(pno == dum_head)
		dum_head=0;			//Only one node, queue is empety

	return pno;
}

/*================================================================*/

/* end of dummy.c */
