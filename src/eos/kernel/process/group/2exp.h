
/*------------------------------------
 * 2exp.h
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

#ifndef KERNEL_PROC_GROUP_2EXP_H_
#define KERNEL_PROC_GROUP_2EXP_H_


/*================================================================*/
extern void 	grp_ini_pro(void);

extern void add_dum_grp(int pno);
extern void del_dum_grp(int pno);
extern void ini_dum_grp(void);
extern int  get_dum_grp(void);


extern void add_idle_grp(int pno);
extern void del_idle_grp(int pno);
extern void ini_idle_grp(void);
extern void	run_idle_grp(void);

extern void add_msg_grp(int pno);
extern void del_msg_grp(int pno);
extern void ini_msg_grp(void);
extern int	run_msg_grp(void);

extern void add_slot_grp(int pno);
extern void del_slot_grp(int pno);
extern void ini_slot_grp(void);
extern int	run_slot_grp(void);

extern void add_time_grp(int pno);
extern void del_time_grp(int pno);
extern void ini_time_grp(void);
extern int	run_time_grp(void);

extern void add_real_grp(int pno);
extern void del_real_grp(int pno);
extern void ini_real_grp(void);
extern void	run_real_grp(void);

/*================================================================*/

#endif 
/* end of 2exp.h */
