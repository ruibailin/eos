
/*------------------------------------
 * queue.c
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

/*================================================================*/
static 	SNode node_pool[PAT_NODE_NUM];

/*================================================================*/
void 	grp_ini_pro(void);
void 	grp_ini_pro()
{
	int i;
	for(i=0;i<MAX_PAT_NUM;i++)
	{
		QueueSNode(node_pool,i);
	}
}

int 	grp_get_pro(int grp);
int 	grp_get_pro(int grp)
{
	int pno;
	if(grp>PAT_NODE_NUM-1)
		return 0;
	pno=GetNextSNode(node_pool,grp);
	return pno;
}

void 	grp_add_pro(int grp,int pro);
void 	grp_add_pro(int grp,int pro)
{
	if(grp>PAT_NODE_NUM-1)
		return;
	if(pro>PAT_NODE_NUM-1)
		return;
	AppendSNode(node_pool,grp,pro);
}

void 	grp_del_pro(int grp,int pro);
void 	grp_del_pro(int grp,int pro)
{
	if(grp>PAT_NODE_NUM-1)
		return;
	if(pro>PAT_NODE_NUM-1)
		return;
	DeleteSNode(node_pool,pro);
}

/*================================================================*/

/* end of queue.c */
