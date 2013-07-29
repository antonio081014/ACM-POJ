//Tue Mar  9 00:32:16 CST 2010
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

int main(int argc, const char* argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	while (cin >> n && n != -1)
	{
		string a, b;
		cin >> a >> b;
		set<char> va(a.begin(), a.end());	//To take care of the letters would be guessed.
		set<char> vb(b.begin(), b.end());	//To take care of the letters should but has not been guessed.
		set<char>::iterator it;
		int count = 0;				//To count the wrong guesses we have tried.
		bool flag = false;			//To show the status of the game for each time.
		cout << "Round " << n << endl;
		for (int i = 0; i < b.size(); i++)
		{
			it = vb.find(b[i]);
			if (it == vb.end())	//If it has been guessed. just go for the next one.
				continue;
			it = va.find(b[i]);	//Otherwise, this one should be tried.
			if(it != va.end()) va.erase(it);	//When our guess is right.
			else					//When it's wrong.
			{
				count ++;
			}
			if(va.empty() && count < 7)	//
			{
				cout << "You win." << endl;
				flag = true;
				break;
			}
			if(!va.empty() && count >= 7)
			{
				cout << "You lose." << endl;
				flag = true;
				break;
			}
		}
		if(!flag) cout << "You chickened out." << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
