/*************************************************************************
    > File Name: mem_buffer.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Fri 09 Sep 2016 01:06:38 AM PDT
 ************************************************************************/
#include "apue.h"

#define BSZ		48

int main()
{
	FILE *fp;
	char buf[BSZ];

	memset(buf, 'a', BSZ-2);
	buf[BSZ-2] = '\0';
	buf[BSZ-1] = 'X';

	if ((fp = fmemopen(buf, BSZ, "w+")) == NULL) {
		printf("fmemopen failed.");
		exit(0);
	}

	printf("initial buffer contents: %s\n", buf);
	fprintf(fp, "hello world.");

	printf("before flush: %s\n", buf);
	fflush(fp);
	printf("after flush: %s\n", buf);
	printf("len of string in buf = %ld\n", (long)strlen(buf));

	memset(buf, 'b', BSZ-2);
	buf[BSZ-2] = '\0';
	buf[BSZ-1] = 'X';
	fprintf(fp, "hello, world");
	fseek(fp, 0, SEEK_SET);
	printf("after fseek: %s\n", buf);
	printf("len of string in buf = %ld\n", (long)strlen(buf));

	memset(buf, 'c', BSZ-2);
	buf[BSZ-2] = '\0';
	buf[BSZ-1] = 'X';
	fprintf(fp, "hello, world");
	fclose(fp);
	printf("after fclose: %s\n", buf);
	printf("len of string in buf = %ld\n", (long)strlen(buf));


	exit(0);

}
