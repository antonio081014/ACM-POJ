//http://blog.csdn.net/lhshaoren/article/details/7213622
//指针实现，通过
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;

const int kMax=10007;
char ans[kMax];
struct TNode
{
	char op;
	TNode *left,*right;
};

TNode *creatTree(char a=0,TNode *lchild=NULL,TNode *rchild=NULL)
{
	TNode *tree=new TNode;
	tree->left=lchild;
	tree->right=rchild;
	tree->op=a;
	return tree;
}



int main()
{
	/*
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	//*/
	int T;
	scanf("%d",&T);
	while(T--)
	{
		stack<TNode *> s;
		string line;
		cin>>line;
		for(int i=0;i<line.size();i++)
		{
			if(islower(line[i]))
			{
				TNode *tree=creatTree(line[i]);
				s.push(tree);
			}
			else
			{
				TNode *l_child,*r_child;
				r_child=s.top();
				s.pop();
				l_child=s.top();
				s.pop();
				TNode *tree=creatTree(line[i],l_child,r_child);
				s.push(tree);
			}
		}
		TNode *root=s.top();
		queue<TNode *> q;
		q.push(root);
		int u=0;
		memset(ans,0,sizeof(ans));
		while(!q.empty())
		{
			TNode *tree=q.front();
			q.pop();
			ans[u++]=tree->op;
			if(tree->left!=NULL)
				q.push(tree->left);
			if(tree->right!=NULL)
				q.push(tree->right);
		}
		for(int i=u-1;i>=0;i--)
			printf("%c",ans[i]);
		printf("\n");
	}
	return 0;
}
