/*************************************************************************
    > File Name: rum_cmd_line_args_and_time_them_8-31.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sun 11 Sep 2016 04:35:08 AM PDT
 ************************************************************************/
#include "apue.h"
#include <sys/times.h>

extern void pr_exit(int);

static void pr_times(clock_t, struct tms *, struct tms *);
static void do_cmd(char *);


int main(int argc, char *argv[])
{
	int i;

	setbuf(stdout, NULL);
	for (i = 1; i < argc; i ++) {
		do_cmd(argv[i]);
	}

	exit(0);
}

static void do_cmd(char *cmd) 
{
	struct tms tmsstart, tmsend;
	clock_t start, end;
	int status;

	printf("\ncommand: %s.\n", cmd);
 
	if ((start = times(&tmsstart)) == -1) {
		/* start values */
		printf("times error.");
	}

	if ((status = system(cmd)) < 0) {
		/* execute command */
		printf("system error.");
	}

	if ((end = times(&tmsend)) == -1) {
		/* ending value */
		printf("times errojr");
	}

	pr_times(end-start, &tmsstart, &tmsend);

	pr_exit(status);
}


static void pr_times(clock_t real, struct tms *tmsstart, struct tms *tmsend) 
{
	static long clktck = 0;

	if (clktck == 0) {
		/* fetch clock ticks per second first time */
		if ((clktck = sysconf(_SC_CLK_TCK)) < 0) {
			printf("sysconf error.");
		}
	}

	printf(" real: %7.2f\n", real / (double)clktck);
	printf(" user: %7.2f\n", (tmsend->tms_utime - tmsstart->tms_utime) / (double)clktck);
	printf("  sys: %7.2f\n", (tmsend->tms_stime - tmsstart->tms_stime) / (double)clktck);
	printf(" child user: %7.2f\n", (tmsend->tms_cutime - tmsstart->tms_cutime) / (double)clktck);
	printf(" child sys: %7.2f\n", (tmsend->tms_cstime - tmsstart->tms_cstime) / (double)clktck);
}
