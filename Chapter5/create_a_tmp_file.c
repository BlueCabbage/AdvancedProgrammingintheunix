/*************************************************************************
    > File Name: create_a_tmp_file.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Fri 09 Sep 2016 12:41:15 AM PDT
 ************************************************************************/
#include "apue.h"

int main(void)
{
	char name[L_tmpnam], line[MAXLINE];

	FILE *fp;

	printf("%s.\n", tmpnam(NULL));	/* first temp name */

	tmpnam(name);
	printf("%s.\n", name);			/* second temp name */

	if ((fp = tmpfile()) == NULL) {
		printf("tmpfile error.");
		exit(0);
	}

	fputs("one line of output.\n", fp); /* write to temp file */
	rewind(fp);
	if (fgets(line, sizeof(line), fp) == NULL) {
		printf("fgets error.");
		exit(0);
	}

	fputs(line, stdout);		/* print the line we wrote */


	exit(0);
}
