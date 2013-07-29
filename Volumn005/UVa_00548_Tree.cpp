//Mon May  3 21:32:23 CDT 2010
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

#define inf	1<<20;
using namespace std;

class Node {
public:
	char data;
	Node *left;
	Node *right;

	Node(char str) {
		data = str;
		left = NULL;
		right = NULL;
	}
};

int mmin;
int leaf;

void reconstruction(Node *&root, vector<int> inorder, vector<int> postorder) {
	int N = inorder.size();
	if (N == 0) {
		root = NULL;
		return;
	}

	int last = N - 1;
	root = new Node(postorder[last]);

	if (N == 1) {
		root->left = NULL;
		root->right = NULL;
		return;
	}
//	size_t found = find(inorder.begin(), inorder.end(), postorder[last-1]);
	int i;
	vector<int> inorderA;
	vector<int> inorderB;
	vector<int> postorderA;
	vector<int> postorderB;
	for (i = 0; inorder[i] != postorder[last]; i++) {
		inorderA.push_back(inorder[i]);
		//		cout << inorder[i];
	}
	//	cout << endl;
	i++;
	for (; i < N; i++) {
		inorderB.push_back(inorder[i]);
		//		cout << inorder[i];
	}
	//	cout << endl;
	for (i = 0; i < N; i++) {
		if (find(inorderA.begin(), inorderA.end(), postorder[i])
				!= inorderA.end()) {
			postorderA.push_back(postorder[i]);
		}
		if (find(inorderB.begin(), inorderB.end(), postorder[i])
				!= inorderB.end()) {
			postorderB.push_back(postorder[i]);
		}
	}
	//	for (int i = 0; i < postorderA.size(); i++)
	//	{
	//		cout << postorderA[i];
	//	}
	//	cout << endl;
	//	for (int i = 0; i < postorderB.size(); i++)
	//	{
	//		cout << postorderB[i];
	//	}
	//	cout << endl;
	reconstruction(root->left, inorderA, postorderA);
	reconstruction(root->right, inorderB, postorderB);
	return;
}

void minLeaf(Node *root, int sum) {
	if (root == NULL)
		return;
	if (root->left == NULL && root->right == NULL) {
		if (mmin > root->data + sum) {
			mmin = root->data + sum;
			leaf = root->data;
		} else if (mmin == root->data + sum) {
			if (leaf == -1 || leaf > root->data)
				leaf = root->data;
		}
		return;
	}
	minLeaf(root->left, sum + root->data);
	minLeaf(root->right, sum + root->data);
}

int main(int argc, char* argv[]) {
	//	freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	string str1, str2;
	while (getline(cin, str1) && getline(cin, str2)) {
		stringstream s1(str1);
		stringstream s2(str2);
		int number;
		vector<int> inorder;
		vector<int> postorder;
		while (s1 >> number) {
			inorder.push_back(number);
		}
		while (s2 >> number) {
			postorder.push_back(number);
		}

		if (inorder.size() == 1) {
			cout << inorder[0] << endl;
			continue;
		}

		Node *root;
		root = NULL;
		reconstruction(root, inorder, postorder);
		//		cout << root->data << endl;
		mmin = inf;
		leaf = -1;
		minLeaf(root, 0);
		cout << leaf << endl;
	}
	//	fclose(stdin);
	//	fclose(stdout);
	return 0;
}

