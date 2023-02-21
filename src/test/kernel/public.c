
/*------------------------------------
 * public.c
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

#include "../../eos/kernel/public/node.h"
#include "../../eos/kernel/public/snode.h"
/*================================================================*/
#define	NUDE_NUM	6
SNode	my_sn[NUDE_NUM];

#include <stdio.h>
static void test_sn()
{
	int i;
	for(i=0;i<NUDE_NUM;i++)
		QueueSNode(my_sn,i);
	for(i=0;i<NUDE_NUM;i++)
		AppendSNode(my_sn,0,i);
	DeleteSNode(my_sn,4);
	AppendSNode(my_sn,0,4);
	for(i=0;i<NUDE_NUM;i++)
		DeleteSNode(my_sn,i);
	for(i=0;i<NUDE_NUM-2;i++)
		AppendSNode(my_sn,NUDE_NUM-1,i);
	i=LocateSNode(my_sn,1,2);
	if(i==2)
		printf("2 and 1 is not in same queue \n");
	DeleteSNode(my_sn,1);
	i=LocateSNode(my_sn,1,2);
	if(i!=2)
		printf("2 and 1 is not in same queue \n");
	i=LocateSNode(my_sn,NUDE_NUM-1,3);
	if(i==3)
		printf("3 is in queue\n");
	i=BrowseSNode(my_sn,NUDE_NUM-1);
	printf("queue len is %d\n",i);
	i=BrowseSNode(my_sn,1);
	printf("queue len is %d\n",i);
}

Node	my_n[NUDE_NUM];
static void test_n()
{
	int i;
	for(i=0;i<NUDE_NUM;i++)
		QueueNode(my_n,i);
	for(i=1;i<NUDE_NUM;i++)
		AppendNode(my_n,0,i);
	DeleteNode(my_n,4);
	AppendNode(my_n,0,4);
	for(i=1;i<NUDE_NUM;i++)
		DeleteNode(my_n,i);
	for(i=0;i<NUDE_NUM-1;i++)
		BeforeNode(my_n,NUDE_NUM-1,i);
	for(i=0;i<NUDE_NUM-1;i++)
		DelNextNode(my_n,NUDE_NUM-1);
	for(i=0;i<NUDE_NUM-1;i++)
		BeforeNode(my_n,NUDE_NUM-1,i);
	for(i=0;i<NUDE_NUM-1;i++)
		DelLastNode(my_n,NUDE_NUM-1);
	for(i=1;i<NUDE_NUM;i++)
		AppendNode(my_n,0,i);
	i=LocateNode(my_n,1,2);
	if(i==2)
		printf("2 and 1 is in same queue \n");
	DeleteNode(my_n,1);
	i=LocateNode(my_n,1,2);
	if(i!=2)
		printf("2 and 1 is not in same queue \n");
	i=LocateNode(my_n,NUDE_NUM-1,3);
	if(i==3)
		printf("3 is in queue\n");
	i=BrowseNode(my_n,NUDE_NUM-1);
	printf("queue len is %d\n",i);
	i=BrowseNode(my_n,1);
	printf("queue len is %d\n",i);
}
void test_public(void);
void test_public()
{
	test_sn();
	test_n();
}
/*================================================================*/

/* end of public.c */
