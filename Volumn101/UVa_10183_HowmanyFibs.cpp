#include<stdio.h>
#include<string.h>

int fib[500][101] =
{ 0 };
char start[102], end[102];
int start_num[101], end_num[101];
int count;

void Add(int A[101], int B[101], int C[101])
{
	int length, i;
	for (length = 100; length >= 0 && B[length] == 0; length--)
		;
	for (i = 0; i <= length; i++)
		C[i] = A[i] + B[i];
	for (i = 0; i <= length; i++)
	{
		C[i + 1] += C[i] / 10;
		C[i] = C[i] % 10;
	}
}

int Cmp(int A[101], int B[101])
{
	int i;
	for (i = 100; i >= 0 && A[i] == B[i]; i--)
		;
	if (i == -1)
		return 0; //Equal;
	else if (A[i] > B[i])
		return 1;
	else
		return -1;
}

void init_fib()
{
	int i;
	fib[0][0] = 1;
	fib[1][0] = 2;
	for (i = 2; i < 500; i++)
		Add(fib[i - 2], fib[i - 1], fib[i]);
}

void init()
{
	int i;
	int len1 = strlen(start);
	int len2 = strlen(end);
	for (i = 0; i < 101; i++)
		start_num[i] = end_num[i] = 0;
	for (i = 0; i < len1; i++)
		start_num[i] = start[len1 - i - 1] - '0';
	for (i = 0; i < len2; i++)
		end_num[i] = end[len2 - i - 1] - '0';
}

void CalPrint()
{
	int i, j;
	count = 0;
	for (i = 0; i < 500 && Cmp(fib[i], start_num) == -1; i++)
		;
	if (Cmp(fib[i], start_num) == 0)
	{
		count++;
		j = i + 1;
	}
	else
		j = i;
	for (; j < 500 && Cmp(fib[j], end_num) <= 0; j++, count++)
		;
	printf("%d\n", count);
}

int main()
{
	init_fib();
	scanf("%s %s", start, end);
	while (strcmp(start, "0") || strcmp(end, "0"))
	{
		init();
		CalPrint();
		scanf("%s %s", start, end);
	}
	return 0;
}
