#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <stdlib.h>

// Sum of quare of positive integer
long sum_square (int *a, int X);

// Split input string which you have entered
void split_string( char *s, int *a);

// loop per number of testcase
void loop_test (int N);


int main ()
{
	int N;

	printf("\n Enter number of test cases. N =");
	fflush( stdout );
	scanf("%d", &N);

	loop_test(N);

	return 0;

}

long sum_square (int *a, int X){
	if (!X) return 0;
	if (*a>=0)
		return (*a * *a + sum_square(a+1, X-1));
	else
		return (sum_square(a+1, X-1));
}

void split_string( char *s, int *a){
	char *p;
	int shift;
	p = strtok(s, " ");
	if (p!=NULL){

		//covert char to integer
		*a = atoi(p);

		// Check number of character of each integer
		if ((*a>=-127) && (*a<=-100)) shift = 4;
		if ((*a>=-99) && (*a<=-10)) shift = 3;
		if ((*a>=-9) && (*a<=-1)) shift = 2;
		if ((*a>=0) && (*a<=9)) shift = 1;
		if ((*a>=10) && (*a<=99)) shift = 2;
		if (*a ==100) shift = 3;

		// shift
		s = s+ shift +1 ;

		split_string(s, a+1);
	}
}

void loop_test (int N){
	int i =0;
	int  X;
	int a[100];
	char s[600];
	long SUM = 0;
	if (i < N){

		printf("\n Number you want to calculate. X = ");
		fflush( stdout );
		scanf("%d", &X);
		fflush( stdin );

		printf("\n Enter your string : ");
		fflush(stdout);
		fgets(s,sizeof(s),stdin);
		s[strlen(s)-1] = '\0';

		//split input string
		split_string(s, a);

		//sum of square of positive number
		SUM = sum_square(a,X);
		printf("\n Sum of square of positive integer = %.2ld", SUM);

		i++;
		loop_test(N-i);
	}


}




