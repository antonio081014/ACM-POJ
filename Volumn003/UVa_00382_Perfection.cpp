//Thu Mar 10 16:48:31 CST 2011
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

string check(int N)
{
    int sum = 0;
    for (int i = 1; i <= (int) sqrt(1.0 * N); i++)
    {
        if (N % i == 0)
        {
            if (i != N)
                sum += i;
            int a = N / i;
            if (a != N)
                sum += a;
        }
    }
    if (sum == N)
        return "PERFECT";
    if (sum < N)
        return "DEFICIENT";
    else return "ABUNDANT";
}

int main(int argc, const char* argv[])
{
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    cout << "PERFECTION OUTPUT" << endl;
    int N;
    while (cin >> N && N != 0)
    {
        cout << setw(5);
        cout << N << "  " << check(N) << endl;
    }
    cout << "END OF OUTPUT" << endl;
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
