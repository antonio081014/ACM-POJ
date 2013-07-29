//Mon Jul  5 15:51:51 CDT 2010
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
#define MMAX 100000
using namespace std;

int Count;

class TreeNode
{
public:
	bool istring;
	TreeNode *child[10];
};

vector<TreeNode> v(MMAX);

class TrieTree
{
private:
	TreeNode root;
public:
	void init();
	bool insert(string word);
};

void TrieTree::init()
{
	Count = 0;
	root = v[Count++];
	memset(root.child, NULL, sizeof(root.child));
	root.istring = false;
}

bool TrieTree::insert(string word)
{
	TreeNode *start = &root;
	int len = word.size();
	for (int i = 0; i < len; i++)
	{
		if (start->child[word[i] - '0'] == NULL)
		{
			start->child[word[i] - '0'] = &v[Count];
			v[Count].istring = false;
			memset(v[Count].child, NULL, sizeof(v[Count].child));
			Count++;
		}
		else if (start->child[word[i] - '0']->istring == true || i == len - 1)
		{
			start->child[word[i] - '0']->istring = true;
			return false;
		}
		start = start->child[word[i] - '0'];
	}
	start->istring = true;
	return true;
}

int main(int argc, const char* argv[])
{
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	int ncase = 0;
	string str;
	bool flag = true;
	TrieTree x;
	x.init();
	while (cin >> str)
	{
		if (str == "9")
		{
			if (flag == false)
			{
				cout << "Set " << ++ncase << " is not immediately decodable"
						<< endl;
			}
			else
			{
				cout << "Set " << ++ncase << " is immediately decodable"
						<< endl;
			}
			flag = true;
			x.init();
		}
		else if (x.insert(str) == false)
		{
			flag = false;
		}
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
