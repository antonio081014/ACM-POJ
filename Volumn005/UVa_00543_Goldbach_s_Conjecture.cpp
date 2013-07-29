//Mon Apr  4 13:07:11 CDT 2011
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define maxn    1000001

using namespace std;

bool isPrime[maxn];

void get_prime()
{
    long Prime[maxn], tot;
    for (long i = 1; i < maxn; i++) isPrime[i] = true;
    isPrime[1] = false;
    tot = 0;
    for (long i = 2; i < maxn; i++)
    {
        if (isPrime[i])
        {
            tot++;
            Prime[tot] = i;
        }
        for (long j = 1; j <= tot && i * Prime[j] < maxn; j++)
        {
            isPrime[i * Prime[j]] = false;
            if (i % Prime[j] == 0) break;
        }
    }
}

void solve(int n)
{
    for (int i = 3; i < maxn; i += 2)
    {
        if (isPrime[i] && isPrime[n - i])
        {
            cout << n << " = " << i << " + " << n - i << endl;
            return;
        }
    }
    cout << "Goldbach's conjecture is wrong." << endl;
    return;
}

int main(int argc, char* argv[])
{
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int n;
    get_prime();
    while (cin >> n && n)
    {
        solve(n);
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
