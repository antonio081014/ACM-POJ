//Thu Apr 14 14:19:42 CDT 2011
#include<stdio.h>
#include <iostream>
using namespace std;
#define MAX 500001
long long MergeSort(long a[], long c[], int left, int right) {
	int i, j, mid, temp, count;
	long long total = 0;
	if (right > left) {
		mid = (left + right) / 2;
		total += MergeSort(a, c, left, mid);
		total += MergeSort(a, c, mid + 1, right);
		count = 0;
		for (i = left, j = mid + 1; i <= mid && j <= right;) {
			if (a[i] > a[j]) {
				total += mid - i + 1;
				c[++count] = a[j++];
			} else
				c[++count] = a[i++];
		}
		while (i <= mid)
			c[++count] = a[i++];
		while (j <= right)
			c[++count] = a[j++];
		for (i = left; i <= right; i++)
			a[i] = c[i - left + 1];
	}
	return total;
}
long a[MAX], c[MAX];
int main(void) {
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	long n;
	int i, j;
	long long total;
	scanf("%ld", &n);
	while (n != 0) {
		for (i = 1; i <= n; i++)
			scanf("%ld", &a[i]);
		total = MergeSort(a, c, 1, n);
		cout << total << endl;
		scanf("%ld", &n);

	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}

