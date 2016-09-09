/*************************************************************************
    > File Name: create_a_tmp_file_with_mkstemp.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Fri 09 Sep 2016 12:48:47 AM PDT
 ************************************************************************/
#include "apue.h"
#include <errno.h>


void make_temp(char *template);

int main(void) 
{
	char good_template[] = "/tmp/dirXXXXXX"; /* right way */
	char *bad_template = "/tmp/dirXXXXXX";   /*wrong way  */

	printf("trying to create first temp file ...\n");
	make_temp(good_template);
	printf("trying to create second temp file ...\n");
	make_temp(bad_template);


	exit(0);

}

void make_temp(char *template)
{
	int fd;
	struct stat sbuf;

	if ((fd = mkstemp(template)) < 0) {
		printf("can't create temp file");
		exit(0);
	}

	printf("temp name = %s.\n", template);

	close(fd);
	if (stat(template, &sbuf) < 0) {
		if (errno == ENOENT) {
			printf("file doesn't exist.\n");
		}
		else {
			printf("stat failed.\n");
			exit(0);
		}
	}
	else {
		printf("file exists.\n");
		unlink(template);
	}
}
