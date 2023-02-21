
/*------------------------------------
 * schedule.c
 * Create:  2023-02-21
 * Author:  Steve Rui
 *------------------------------------
 * Record:
 *
 *
 *
 *
 *------------------------------------
 */


/*================================================================*/
extern void knl_ini_msg(void);
extern void knl_ini_tim(void);
extern void	knl_ini_pcb(void);
extern void knl_ini_pro(void);

void knl_ini_all(void);
void knl_ini_all()
{
	knl_ini_msg();
	knl_ini_tim();
	knl_ini_pcb();
	knl_ini_pro();
}

void knl_run_real_p(void);
int knl_run_time_p(void);
int	knl_run_tim(void);
int	knl_run_msg(void);
void knl_run_idle_p(void);

void knl_run_all()
{
	int res;
	knl_run_real_p();
	res=knl_run_time_p();
	if(res)
		return;
	res=knl_run_tim();
	if(res)
		return;
	res=knl_run_msg();
	if(res)
		return;
	knl_run_idle_p();
}

/*================================================================*/

/* end of schedule.c */
