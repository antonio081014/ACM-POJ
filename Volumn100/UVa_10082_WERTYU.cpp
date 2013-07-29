//Wed Mar 16 15:52:43 CDT 2011
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

char convert(char x)
{
    if (x == '1') return '`';
    if (x == '2') return '1';
    if (x == '3') return '2';
    if (x == '4') return '3';
    if (x == '5') return '4';
    if (x == '6') return '5';
    if (x == '7') return '6';
    if (x == '8') return '7';
    if (x == '9') return '8';
    if (x == '0') return '9';
    if (x == '-') return '0';
    if (x == '=') return '-';
    if (x == 'W') return 'Q';
    if (x == 'E') return 'W';
    if (x == 'R') return 'E';
    if (x == 'T') return 'R';
    if (x == 'Y') return 'T';
    if (x == 'U') return 'Y';
    if (x == 'I') return 'U';
    if (x == 'O') return 'I';
    if (x == 'P') return 'O';
    if (x == '[') return 'P';
    if (x == ']') return '[';
    if (x == '\\') return ']';
    if (x == 'S') return 'A';
    if (x == 'D') return 'S';
    if (x == 'F') return 'D';
    if (x == 'G') return 'F';
    if (x == 'H') return 'G';
    if (x == 'J') return 'H';
    if (x == 'K') return 'J';
    if (x == 'L') return 'K';
    if (x == ';') return 'L';
    if (x == '\'') return ';';
    if (x == 'X') return 'Z';
    if (x == 'C') return 'X';
    if (x == 'V') return 'C';
    if (x == 'B') return 'V';
    if (x == 'N') return 'B';
    if (x == 'M') return 'N';
    if (x == ',') return 'M';
    if (x == '.') return ',';
    if (x == '/') return '.';
    if (x == ' ') return ' ';
}

int main(int argc, char* argv[])
{
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    string str;
    while (getline(cin, str))
    {
        for (int i = 0; i < str.size(); i++)
        {
            cout << convert(str[i]);
        }
        cout << endl;
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
