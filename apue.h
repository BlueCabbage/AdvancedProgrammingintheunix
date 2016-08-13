/*************************************************************************
    > File Name: apue.h
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sat 13 Aug 2016 03:25:35 AM PDT
 ************************************************************************/
/*
 * Our own header, to be included before all standard system headers
 */

#ifndef		__APUE_H_
#define		__APUE_H_
	
#define		_POSIX_C_SOURCE		200809L

#if defined(SOLARIS)	/* Solaris 10 */
#define _XOPEN_SOURCE	600
#else
#define _XOPEN_SOURCE	700
#endif

#include <sys/types.h>			/* some systems still requires this */
#include <sys/stat.h>
#include <sys/termios.h>		/* for winsize */

#if defined(MACOS) || !defined(TIOCGWINSZ)
#include <sys/ioctl.h>
#endif

#include <stdio.h>	  
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#define MAXLINE		4096	/* max line length */


/*
 *	Default file access permissions for new files.
 */
#define FILE_MODE		( S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH )

/*
 *	Default permissions for new directories.
 */
#define	DIR_MODE		( FILE_MODE | S_IXUSR | S_IXGRP | S_IXOTH )

typedef void		Sigfunc(int);		/* for signal handlers */

#define min(a, b)		((a) < (b) ? (a) : (b))
#define max(a, b)		((a) > (b) ? (a) : (b))

/*
 *	Prototypes for our own functions.
 */
char	*path_alloc(size_t *);			/* Figure 2.16 */
long	open_max(void);					/* Figure 2.17 */ 



pid_t	lock_test(int, int, off_t, int, off_t);			/* Figure 14.6 */

#define is_read_lockable(fd, offset, whence, len) \
			(lock_test((fd), F_RDLCK, (offset), (whence), (len)) == 0)

#define is_write_lockable(fd, offset, whence, len) \
			(lock_test((fd), F_WRLCK, (offset), (whence), (len)) == 0)


void	err_msg(const char *, ...);
void	err_dump(const char *, ...) __attribute__((noreturn));
void	err_quit(const char *, ...) __attribute__((noreturn));
void	err_cont(int, const char *, ...);
void	err_exit(int, const char *, ...) __attribute__((noreturn));
void	err_ret(const char *, ...);
void	err_sys(const char *, ...) __attribute__((noreturn));

void	log_msg(const char *, ...);
void	log_open(const char *, int, int);
void	log_quit(const char *, ...) __attribute__((noreturn));
void	log_ret(const char *, ...);
void	log_sys(const char *, ...) __attribute__((noreturn));
void	log_exit(int, const char *, ...) __attribute((noreturn));


#endif
