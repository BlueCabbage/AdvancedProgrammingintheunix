/*************************************************************************
    > File Name: recursive_traverse_dir.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sun 04 Sep 2016 02:45:36 AM PDT
 ************************************************************************/

#include "apue.h"
#include <dirent.h>
#include <limits.h>

/* fucntion type that is called for each filename */
typedef int Myfunc(const char*, const struct stat *, int);

static Myfunc myfunc;
static int myftw(char *, Myfunc *);
static int dopath(Myfunc *);
static lont nerg, ndir, nblk, nfifo, nslink, nsock, ntot;

int main(int argc, char *argv[])
{
	int ret;
	if (argc < 2) {
		printf("usage: ftw <starting-pathname>");
		exit(0);
	}

	ret = myftw(argv[1], myfunc);	/* does it all */
}

/*
 *	Descend through the hierarchy, starting at "pathname"
 *	The caller's func() is called for every file.
 */

#define FTW_F	 1		/* file other than directory */
#define FTW_D	 2		/* directory */
#define FTW_DNR	 3		/* directory that can't be read */
#define FTW_NS	 4		/* file that we can't stat */

static char *fullpath;	/* contains full pathname for every file */
static size_t pathlen;

static int myftw(char *pathname, Myfunc *func)
{
	fullpath = path_alloc(&pathlen); /* malloc PATH_MAX + 1 bytes */

	if (pathlen <= strlen(pathname)) {
		pathlen = strlen(pathname) * 2;
		if ((fullpath = realloc(fullpath, pathlen)) == NULL) {
			printf("realloc failed.");
		}
	}

	strcpy(fullpath, pathname);


	return(dopath(func));
}


/*
 * Descend through the hierarchy, starting at "fullpath".
 * If "fullpath" is anything other than a directory, we lstat() it,
 * call func(), and return. For a dierctory, we call ourself 
 * recursively for ecah name in the directory.
 */
 
static int dopath(Myfunc *func) 
{
	struct stat statbuf;
	struct dirent *dirp;
	DIR		*dp;
	int		ret, n;

	if (lstat(fullpath, &statbuf) < 0) /* stat error */
		return (func(fullpath, &statbuf, FTW_NS));
		
	if (S_ISDIR(statbuf.st_mode) == 0) /* not a directory */
		return (func(fullpath, &statbuf, FTW_F));

	/* 
	 * It's a directory. First call func() for the directory,
	 * then process each filename in the directory.
	 */

	if ((ret = func(fullpath, &statbuf, FTW_D)) != 0)
		return (ret);

	n = strlen(fullpath);

	if ( n + NAME_MAX + 2 > pathlenn) { /* expand path buffer */
		pathlen *= 2;
		if ((fullpath == realloc(fullpath, pathlen)) == NULL)
			printf("realloc failed.");
	}

	fullpath[n ++] = '/';
	fullpath[n] = 0;

	
}
