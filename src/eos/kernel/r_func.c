
/*------------------------------------
 * r_func.c
 * Create:  2021-10-17
 * Author:  Steve Rui
 *------------------------------------
 * Record:
 *
 *
 *
 *
 *------------------------------------
 */

#include "0ctr.h"


/*================================================================*/
extern int	knl_this_pno;
/*================================================================*/
#include "./runtime/r_pcb.h"
/*------------------------------------*/
int	SELF(void);
int	SELF()
{
	return(knl_this_pno);
}
/*------------------------------------*/
int	STATE(void);
int	STATE()
{
	int ss;
	ss=get_pcb_state(knl_this_pno);
	return(ss);
}
/*------------------------------------*/
void NEXT(int ss);
void NEXT(int ss)
{
	set_pcb_state(knl_this_pno,ss);
}
/*================================================================*/
extern int knl_this_msg;
extern int knl_this_tim;
#include "./message/r_msg.h"
#include "./timer/r_tcb.h"
/*------------------------------------*/
int	EVENT(void);
int	EVENT()
{
	int event;
	int pno,tno;
	if(knl_this_msg!=0)
	{
		event=get_msg_event(knl_this_msg);
		return(event);
	}
	if(knl_this_tim!=0)
	{
		pno=get_tcb_pno(knl_this_tim);
		if(pno!=knl_this_pno)
			return 0;
		tno=get_tcb_tno(knl_this_tim);
		return(tno);
	}
	return 0;
}
/*------------------------------------*/
int	LENGTH(void);
int	LENGTH()
{
	int length;
	if(knl_this_msg==0)
		return 0;

	length=get_msg_length(knl_this_msg);
	return(length);
}
/*------------------------------------*/
int	SENDER(void);
int	SENDER()
{
	int sour;

	if(knl_this_msg==0)
		return 0;
	sour=get_msg_sour(knl_this_msg);
	return(sour);
}

/*------------------------------------*/
void	ASEND(int dd,int ee,int ll,void *in);
void	ASEND(int dd,int ee,int ll,void *in)
{
	int node;
	node=get_msg_idle(knl_this_pno,ee,ll);
	set_msg_busy(node,dd,in);
}
/*================================================================*/
/*------------------------------------*/
void SET(int tno,int ll);
void SET(int tno,int ll)
{
	int node;
	node=get_pcb_timer(knl_this_pno,tno);
	if(node != 0)							//repeat set timer
		reset_node_tcb(node);

	node=get_node_tcb(tno,knl_this_pno);
	set_pcb_timer(knl_this_pno,tno,node);
	set_node_tcb(node,ll);
}
/*------------------------------------*/
void KILL(int tno);
void KILL(int tno)
{
	int node;
	node=get_pcb_timer(knl_this_pno,tno);
	reset_node_tcb(node);
	set_pcb_timer(knl_this_pno,tno,0);
}

/*================================================================*/

/* end of r_func.c */
