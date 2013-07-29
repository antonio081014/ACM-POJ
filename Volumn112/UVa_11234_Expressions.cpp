/**
 *  Passed. no STL will be good.
 * http://blog.csdn.net/acb0y/article/details/5354340
 */

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct tree
{
    tree* rchild;
    tree* lchild;
    char op;
};

tree * Stack[10000];
tree * Queue[10000];
int front;
int rear;
int top;

tree * CreatTree(char a)
{
    tree * pnode = new tree;
    pnode->rchild = NULL;
    pnode->lchild = NULL;
    pnode->op = a;
    return pnode;
}

tree * CreatTree(char a, tree * pl, tree * pr)
{
    tree * pnode = new tree;
    pnode->rchild = pr;
    pnode->lchild = pl;
    pnode->op = a;
    return pnode;
}

void levelOrder(tree * pF, int n)
{
    char ans[10000];
    //    string s = "";
    int count = 0;
    front = 0;
    rear = -1;

    memset(Queue, 0, sizeof (Queue));
    Queue[front++] = pF;

    while (rear < front)
    {
        tree * pnode = Queue[++rear];
        if (pnode != NULL)
        {
            if (pnode->lchild != NULL)
            {
                Queue[front++] = pnode->lchild;
            }
            if (pnode->rchild != NULL)
            {
                Queue[front++] = pnode->rchild;
            }
            //            s = pnode->op + s;
            ans[count++] = pnode->op;
        }
    }


    for (int i = count - 1; i >= 0; i--)
    {
        cout << ans[i];
    }
    cout << endl;
    //    cout << s << endl;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string str;
        cin >> str;
        int i;
        int len = str.size();
        top = 0;
        for (i = 0; i < len; i++)
        {
            if (islower(str[i]))
            {
                tree * ptree = CreatTree(str[i]);
                Stack[top++] = ptree;
            }
            else
            {
                tree * prtree = Stack[--top];
                tree * pltree = Stack[--top];
                tree * pF = CreatTree(str[i], pltree, prtree);
                Stack[top++] = pF;
            }
        }
        levelOrder(Stack[top - 1], len);
    }
    return 0;
}

