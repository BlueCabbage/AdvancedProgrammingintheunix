/*************************************************************************
    > File Name: displayAllFiles.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sat 13 Aug 2016 03:19:52 AM PDT
 ************************************************************************/

#include "apue.h"
#include <dirent.h>

int 
main( int argc, char *argv[] )
{
	DIR				*dp;
	struct dirent	*dirp;

	if (argc != 2) {
		//err_sys("Can't open %s", argv[1]);
		printf("usage: ls directory_name");
		exit(1);
	}

	if ((dp = opendir(argv[1])) == NULL) {
		printf("Can't open %s", argv[1]);
		exit(1);
	}

	while( (dirp = readdir(dp)) != NULL ) {
		printf("%s\n", dirp->d_name);
	}

	closedir(dp);

	exit(0);
}
