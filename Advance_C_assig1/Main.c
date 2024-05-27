#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>



typedef struct number
{
	unsigned long long num;
	int sum;
} Number;


/* Function declarations */

Number* primeSums(unsigned long long n1, unsigned long long n2, int* p_size);
int isPrime(int num);
int digitSum(unsigned long long num);
//void Ex2();
//void Ex3();

/* Declarations of other functions */

/* ------------------------------- */

int main()
{
	/*int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf("%d", &all_Ex_in_loop) == 1)
		do
		{
			for (i = 1; i <= 7; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-7 : ");
				scanf_s("%d", &select);
			} while ((select < 0) || (select > 7));
			switch (select)
			{
			case 1: Ex1(); break;
			case 2: Ex2(); break;
			case 3: Ex3(); break;
			}
		} while (all_Ex_in_loop && select);
		return 0;*/


	unsigned long long n1 = 100;
	unsigned long long n2 = 120;
	int p_size;

	Number* primes = primeSums(n1, n2, &p_size);

	printf("Prime numbers between %llu and %llu are:\n", n1, n2);
	for (int i = 0; i < p_size; i++) {
		printf("%llu ", primes[i].num);
	}
	printf("\n");
	printf("%d", p_size);

	free(primes);
	return 0;

}


/* Function definitions */

Number* primeSums(unsigned long long n1, unsigned long long n2, int* p_size) {
	*p_size = 0;
	int k = 0;
	unsigned long long size = n2 - n1 + 1; // Including n2
	Number* num_arr = (Number*)calloc(size, sizeof(Number));

	for (unsigned long long i = n1; i <= n2; i++) {
		if (isPrime(digitSum(i))) {
			num_arr[k].num = i;
			k++;
		}
	}

	*p_size = k;
	num_arr = (Number*)realloc(num_arr, *p_size * sizeof(Number));
	return num_arr;
}

int isPrime(int num) {

	if (num <= 2) return 0;
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) {
			return 0;
		}
	}
	return 1;
}

int digitSum(unsigned long long num) {
	int num_sum = 0;
	while (num != 0) {
		num_sum += num % 10;
		num /= 10; // Correct division operation
	}
	return num_sum;
}

/* ------------------- */