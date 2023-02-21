
/*------------------------------------
 * 1imp.h
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

#ifndef SRC_KERNEL_PROC_GROUP_1IMP_H_
#define SRC_KERNEL_PROC_GROUP_1IMP_H_

#include "../1imp.h"
#include "../basic/pat.h"
#include "../basic/r_pat.h"
#include "../../public/node.h"
#include "../../public/snode.h"
#include "../../util/util.h"
/*================================================================*/
//define type of process
#define	DUM_PROC		0x00		//dummy process, no scheduled,just saved resource
#define IDLE_PROC		0x01		//process is scheduled when CPU is idle(no SLOT, MSG and TIME to run)
#define SLOT_PROC		0x02		//process is scheduled by time slot and no TIME and MSG proc to run in this loop
#define MSG_PROC		0x03		//process is scheduled by message and no TIME proc to run in this loop
#define TIME_PROC		0x04		//process is scheduled every a fixed time, the time length is defined by attr.
#define REAL_PROC		0x05		//Real time process,will be scheduled every main loop
/*================================================================*/

#endif 
/* end of 1imp.h */
