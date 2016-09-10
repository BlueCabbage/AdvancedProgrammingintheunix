/*************************************************************************
    > File Name: setjmp_and_longjmp.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sat 10 Sep 2016 01:48:53 AM PDT
 ************************************************************************/
#include "apue.h"
#include <setjmp.h>

static void f1(int, int, int, int);
static void f2(void);

static jmp_buf	jmpbuffer;
static int		globval;

int main(void) 
{
	int				autoval;
	register int	regival;
	volatile int	volaval;
	static	 int	statval;

	globval = 1;
	regival	= 2;
	volaval = 3;
	statval = 4;
	autoval = 5;

	if (setjmp(jmpbuffer) != 0) {
		printf("after longjmp: \n");
		printf("globval = %d, autoval = %d, regibal = %d, volaval = %d, statval = %d\n", globval, autoval, regival, volaval, statval);

		exit(0);
	}

	/*
	 * Change variables after setjmp, buf before longjmp.
	 */
	globval = 95;
	autoval = 96;
	regival = 97;
	volaval = 98;
	statval = 99;

	f1(autoval, regival, statval, volaval); /* never returns */

	
	exit(0);
}


static void f1(int i, int j, int k, int l)
{
	printf("in f1(): \n");
	printf("globval = %d, autoval = %d, regibal = %d, volaval = %d, statval = %d\n", globval, i, j, l, k);

	f2();
}

static void f2(void)
{
	longjmp(jmpbuffer, 1);
}


