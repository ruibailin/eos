
/*------------------------------------
 * pat.h
 * Create:  2023-02-17
 * Author:  Steve Rui
 *------------------------------------
 * Record:
 * Define Process Attribute Table
 *
 *
 *
 *------------------------------------
 */

#ifndef SRC_KERNEL_PROC_PAT_H_
#define SRC_KERNEL_PROC_PAT_H_

#include "1imp.h"
#define	 PAT_NODE_NUM	MAX_PAT_NUM
/*================================================================*/
typedef struct{
	char *name;
    void (*entry)(void *);
    uintxx type;
    uintxx attr;
}PAT;

extern PAT PATPool[PAT_NODE_NUM];
/*================================================================*/

#endif 
/* end of pat.h */
