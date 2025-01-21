#include <stdio.h>

int main(void)
{
	char c, *cp;
	short s, *sp;
	int i, *ip;
	long l, *lp;
	long long ll, *llp;
	float f;
	double df;
	// void v, *vp;
	void *vp;

	printf("sizeof(char):		%lu, \t sizeof(c):		%lu\n",
		sizeof(char), 		sizeof(c));

	printf("sizeof(char *):		%lu, \t sizeof(*cp):	%lu, \t sizeof(cp):	%lu\n",
		sizeof(char *), 	sizeof(*cp), 		sizeof(cp));

	printf("sizeof(short):		%lu, \t sizeof(s):		%lu\n",
		sizeof(short), 		sizeof(s));

	printf("sizeof(short *):	%lu, \t sizeof(*sp):	%lu, \t sizeof(sp):	%lu\n",
		sizeof(short *), 	sizeof(*sp), 		sizeof(sp));

	printf("sizeof(int):		%lu, \t sizeof(i):		%lu\n",
		sizeof(int),		sizeof(i));

	printf("sizeof(int *):		%lu, \t sizeof(*ip):	%lu, \t sizeof(ip):	%lu\n",
		sizeof(int *), 		sizeof(*ip), 		sizeof(ip));

	printf("sizeof(long):		%lu, \t sizeof(l):		%lu\n",
		sizeof(long), 		sizeof(l));

	printf("sizeof(long *):		%lu, \t sizeof(*lp):	%lu, \t sizeof(lp):	%lu\n",
		sizeof(long *), 	sizeof(*lp), 		sizeof(lp));

	printf("sizeof(long long):	%lu, \t sizeof(ll):	%lu\n", sizeof(long long), sizeof(ll));

	printf("sizeof(long long *):	%lu, \t sizeof(*llp):	%lu, \t sizeof(llp):	%lu\n",
		sizeof(long long *), 	sizeof(*llp), 		sizeof(llp));

	printf("sizeof(float):		%lu, \t sizeof(f):	%lu\n", sizeof(float), sizeof(f));
	
	printf("sizeof(double):		%lu, \t sizeof(df):	%lu\n", sizeof(double), sizeof(df));
	
	printf("sizeof(v):		%lu\n", sizeof(void));
	
	printf("sizeof(100):		%lu\n", sizeof(100));
	printf("sizeof(0xFFFFFFFF):	%lu\n", sizeof(0xFFFFFFFF));
	printf("sizeof(0xFFFFFFFFFF):	%lu\n", sizeof(0xFFFFFFFFFF));

	return(0);
}

