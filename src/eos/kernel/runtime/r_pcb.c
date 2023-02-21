
/*------------------------------------
 * r_pcb.c
 * Create:  2021-10-16
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

/*================================================================*/
typedef struct{
	uintxx   state;
	uintxx   parent;
	uintxx   timer[4];
}PCB;

/*------------------------------------*/
#define MAX_PCB_NUM	MAX_PAT_NUM
static	PCB	 PCBPool[MAX_PCB_NUM];

/*===========================================================================*/
/*------------------------------------*/
int	get_pcb_state(int pcb);
int	get_pcb_state(int pcb)
{
	int state;
	state=((int)PCBPool[pcb].state)&MAX_UINTXX;
	return(state);
}
/*------------------------------------*/
void	set_pcb_state(int pcb,int ss);
void	set_pcb_state(int pcb,int ss)
{
	PCBPool[pcb].state=(uintxx)ss;
}
/*------------------------------------*/
int	get_pcb_parent(int pcb);
int	get_pcb_parent(int pcb)
{
	int parent;
	parent=((int)PCBPool[pcb].parent)&MAX_UINTXX;
	return(parent);
}
/*------------------------------------*/
void	set_pcb_parent(int pcb,int parent);
void	set_pcb_parent(int pcb,int parent)
{
	PCBPool[pcb].parent=(uintxx)parent;
}
/*------------------------------------*/
int	get_pcb_timer(int pcb,int ptno);
int	get_pcb_timer(int pcb,int ptno)
{
	int timer;
	timer=((int)PCBPool[pcb].timer[ptno])&MAX_UINTXX;
	return(timer);
}
/*------------------------------------*/
void	set_pcb_timer(int pcb,int ptno,int ttno);
void	set_pcb_timer(int pcb,int ptno,int ttno)
{
	PCBPool[pcb].timer[ptno]=(uintxx)ttno;
}


/*------------------------------------*/
void ini_pcb_list(void);
void ini_pcb_list()
{
	int i;
	for(i=0;i<MAX_PCB_NUM;i++)
	{
		PCBPool[i].parent = 0;
		PCBPool[i].state = 0;
	}

}
/*================================================================*/
/* end of r_pcb.c */
