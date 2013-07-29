//Thu 04 Feb 2010 02:17:42 AM CST 
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

int main(int argc, char* argv[])
{
	int C;
	cin >> C;
	for(int c=0; c<C; c++)
	{
		int N;
		cin >> N;
		vector<int> v(N, 0);
		int sum = 0;
		for(int i=0; i<N; i++)
		{
			cin >> v[i];
			sum += v[i];
		}
		int count = 0;
		for(int i=0; i<N; i++)
		{
			if(v[i]*N > sum)
				count ++;
		}
		printf("%.3f%%\n", 100.0*count / N);
	}
	return 0;
}
