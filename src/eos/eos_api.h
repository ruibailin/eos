
/*------------------------------------
 * eos_api.h
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
#ifndef SRC_NO_EOS_EOS_H_
#define SRC_NO_EOS_EOS_H_
/*================================================================*/
extern	int		SELF(void);
extern	int		STATE(void);
extern	void	NEXT(int state);
extern	int		EVENT(void);
extern	int		LENGTH(void);
extern	int		SENDER(void);
extern	void	ASEND(int dest,int event,int len,void *in);
extern	void	SET(int ptno,int len);
extern	void	KILL(int ptno);

/*================================================================*/
#endif

/* end of eos_api.h */
