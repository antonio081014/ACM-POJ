//Mon Apr  4 01:15:58 CDT 2011
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

using namespace std;

const long maxn = 65007;
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

long modN(long a, long m, long n)
{
    if (m == 1)
        return a % n;
    if (m % 2 == 0)
    {
        long tmp = modN(a, m / 2, n) % n;
        return (tmp * tmp) % n;
    }
    else
    {
        long tmp = modN(a, (m - 1) / 2, n) % n;
        tmp = (tmp * tmp) % n;
        return a * tmp % n;
    }
}

bool isCarmichael(long n)
{
    for (long i = 2; i < n; i++)
    {
        if (modN(i, n, n) != i)
            return false;
    }
    return true;
}

int main(int argc, char* argv[])
{
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    long n;
    get_prime();
    while (cin >> n && n)
    {
        if (!isPrime[n] && isCarmichael(n))
            cout << "The number " << n << " is a Carmichael number." << endl;
        else
            cout << n << " is normal." << endl;
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
