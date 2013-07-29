//Tue Mar  1 23:11:01 CST 2011
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

#define SIZE 1000000

vector<unsigned int> v;

unsigned int Generate(unsigned long index) {
    if (index <= SIZE && v[index] != 0)
        return v[index];
    if (index & 1) {
        if (index < SIZE) {
            return v[index] = 2 + Generate((3 * index + 1) >> 1);
        } else
            return 2 + Generate((3 * index + 1) >> 1);
    } else {
        if (index < SIZE) {
            return v[index] = 1 + Generate(index >> 1);
        } else
            return 1 + Generate(index >> 1);
    }
}

int main(int argc, char* argv[]) {
//    freopen("input.in", "r", stdin);
//    freopen("output.out", "w", stdout);
    unsigned long a;
    unsigned long b;
    for (int i = 0; i < SIZE; i++)
        v.push_back(0);
    v[1] = 1;
    while (cin >> a >> b) {
        int ret = 0;
        if (a < b) {
            for (int i = a; i <= b; i++) {
                int temp = Generate(i);
                ret = ret < temp ? temp : ret;
            }
        } else {
            for (int i = b; i <= a; i++) {
                int temp = Generate(i);
                ret = ret < temp ? temp : ret;
            }
        }
        cout << a << " " << b << " " << ret << endl;
    }
//    fclose(stdin);
//    fclose(stdout);
    return 0;
}
