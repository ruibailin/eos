
/*------------------------------------
 * process0.c
 * Create:  2023-02-18
 * Author:  Steve Rui
 *------------------------------------
 * Record:
 * Process 0 is monitor and static process
 *
 *
 *
 *------------------------------------
 */

#include "1imp.h"

/*================================================================*/
long    knl_loop_times=0;
extern long knl_run_ms;

static long this_ms=0;
static int max_ms_loop=0;
void	sys_proc_00(void *in);
void	sys_proc_00(void *in)
{
	long last_ms;
	int loop;
	knl_loop_times++;
	last_ms=this_ms;
	this_ms=knl_run_ms;
	loop=(int)(this_ms-last_ms);
	if(loop>max_ms_loop)
		max_ms_loop=loop;
}


/*================================================================*/

/* end of process0.c */
