
/*------------------------------------
 * rbl_time.c
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

#include "1imp.h"
/*================================================================*/
#include <time.h>
#include <sys/time.h>

int rbl_get_sec(void);
int rbl_get_sec()
{
	struct timeval current_time;
	gettimeofday(&current_time, NULL);
	return (int)(current_time.tv_sec);
}

int rbl_get_usec(void);
int rbl_get_usec()
{
	long int	us;
    struct timeval    tv;
    struct timezone	  tz;
	gettimeofday(&tv, &tz);
	us=(int)(tv.tv_usec);		//max value is 999999
	return(us);
}


int rbl_get_second(void);
int rbl_get_second()
{
	  time_t timep;
	  struct tm *p;
	  time(&timep);
	  p=gmtime(&timep);
	  return(p->tm_sec);
}
int rbl_get_minute(void);
int rbl_get_minute()
{
	  time_t timep;
	  struct tm *p;
	  time(&timep);
	  p=gmtime(&timep);
	  return(p->tm_min);
}

int rbl_get_hour(void);
int rbl_get_hour()
{
	  time_t timep;
	  struct tm *p;
	  time(&timep);
	  p=gmtime(&timep);
	  return(p->tm_hour);
}

int rbl_get_mday(void);
int rbl_get_mday()
{
	  time_t timep;
	  struct tm *p;
	  time(&timep);
	  p=gmtime(&timep);
	  return(p->tm_mday);
}

int rbl_get_month(void);
int rbl_get_month()
{
	  time_t timep;
	  struct tm *p;
	  time(&timep);
	  p=gmtime(&timep);
	  return(p->tm_mon);
}

int rbl_get_year(void);
int rbl_get_year()
{
	  time_t timep;
	  struct tm *p;
	  time(&timep);
	  p=gmtime(&timep);
	  return(p->tm_year);
}

int rbl_get_wday(void);
int rbl_get_wday()
{
	  time_t timep;
	  struct tm *p;
	  time(&timep);
	  p=gmtime(&timep);
	  return(p->tm_wday);
}

/*================================================================*/

/* end of rbl_time.c */
