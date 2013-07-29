//Wed Mar  2 13:30:14 CST 2011
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

int check(int n) {
    if (n == 0)return 1;
    if (n == 2)return 3;
    if (n & 1) return 0;
    return 4 * check(n - 2) - check(n - 4);
}

int main(int argc, const char* argv[]) {
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int n;
    while (cin >> n && n != -1) {
        cout << check(n) << endl;
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
