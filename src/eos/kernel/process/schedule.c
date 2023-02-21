
/*------------------------------------
 * proc.c
 * Create:  2023-02-18
 * Author:  Steve Rui
 *------------------------------------
 * Record:
 *
 *
 *
 *
 *------------------------------------
 */

#include "./group/2exp.h"

/*================================================================*/
void knl_ini_pro(void);
void knl_ini_pro()
{
	grp_ini_pro();

	ini_dum_grp();
	ini_idle_grp();
	ini_msg_grp();
	ini_slot_grp();
	ini_time_grp();
	ini_real_grp();

	run_msg_grp();
}

void knl_run_real_p(void);
void knl_run_real_p()
{
	run_real_grp();
}

int knl_run_time_p(void);
int knl_run_time_p()
{
	int res;
	res=run_time_grp();
	return res;
}

void knl_run_idle_p(void);
void knl_run_idle_p()
{
	run_idle_grp();
}

/*================================================================*/

/* end of proc.c */
