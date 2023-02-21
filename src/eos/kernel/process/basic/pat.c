
/*------------------------------------
 * pat.c
 * Create:  2023-02-17
 * Author:  Steve Rui
 *------------------------------------
 * Record:
 * User Process register here
 *
 *
 *
 *------------------------------------
 */

#include "1imp.h"
#include "pat.h"
/*================================================================*/
/*------------------------------------*/
static void null_p(void *in)
{

}
/*------------------------------------*/
extern void	sys_proc_00(void *in);
extern void	sys_timer(void *in);
extern void	sys_idler(void *in);
extern void	sys_comer(void *in);

//test
extern void  time_show_date(void *in);
extern void  msg_watch_dog(void *in);
extern void  time_01(void *in);
extern void  time_02(void *in);
extern void  idle_01(void *in);
extern void  idle_02(void *in);
extern void  real_01(void *in);
extern void  real_02(void *in);
extern void  msg_pro1(void *in);
extern void  msg_pro2(void *in);
/*------------------------------------*/
PAT PATPool[MAX_PAT_NUM]={
/*       name      		entry  		type	attr	*/
/*000*/  {"System 00", 	&sys_proc_00,	REAL,		0},
/*001*/  {"Timer Proc", 	&sys_timer,	TIME,		0},
/*002*/  {"Idler Proc", 	&sys_idler,	IDLE,		0},
/*003*/  {"Com outside", 	&sys_comer,	MSG,		0},
/*004*/  {"Null Pro", 	&null_p,	0,		0},
/*005*/  {"Null Pro", 	&null_p,	0,		0},
/*006*/  {"Show Date", 	&time_show_date,	TIME,		0},
/*007*/  {"Watch Dog", 	&msg_watch_dog,	MSG,		0},
/*008*/  {"Time 01", 	&time_01,	TIME,		0},
/*009*/  {"Time 02", 	&time_02,	TIME,		0},
/*010*/  {"Idle 01", 	&idle_01,	IDLE,		0},
/*011*/  {"Idle 02", 	&idle_02,	IDLE,		0},
/*012*/  {"Real 01", 	&real_01,	REAL,		0},
/*013*/  {"Real 02", 	&real_02,	REAL,		0},
/*014*/  {"Null Pro", 	&msg_pro1,	MSG,		0},
/*015*/  {"Null Pro", 	&msg_pro2,	MSG,		0},
/*015*/  {"Null Pro", 	&null_p,	0,		0},
/*017*/  {"Null Pro", 	&null_p,	0,		0},
/*018*/  {"Null Pro", 	&null_p,	0,		0},
/*019*/  {"Null Pro", 	&null_p,	0,		0},
/*020*/  {"Null Pro", 	&null_p,	0,		0},
/*021*/  {"Null Pro", 	&null_p,	0,		0},
/*022*/  {"Null Pro", 	&null_p,	0,		0},
/*023*/  {"Null Pro", 	&null_p,	0,		0},
/*024*/  {"Null Pro", 	&null_p,	0,		0},
/*025*/  {"Null Pro", 	&null_p,	0,		0},
/*025*/  {"Null Pro", 	&null_p,	0,		0},
/*027*/  {"Null Pro", 	&null_p,	0,		0},
/*028*/  {"Null Pro", 	&null_p,	0,		0},
/*029*/  {"Null Pro", 	&null_p,	0,		0},
/*030*/  {"Null Pro", 	&null_p,	0,		0},
/*031*/  {"Null Pro", 	&null_p,	0,		0},
};

/*================================================================*/

/* end of pat.c */
