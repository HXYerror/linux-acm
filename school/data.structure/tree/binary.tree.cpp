/*************************************************************************
	> File Name: binary.tree.cpp
	> Author: HXYerror
	> Mail: zx841985525@163.com 
	> Created Time: 2019年10月29日 星期二 20时43分55秒
 ************************************************************************/

#include <bits/stdc++.h>
#define ll  long long
#define Ok 1
#define ERROR 0
#define FALSE 0
#define TRUE 1
#define OVERFLOW -2
using namespace std;
const int MAX = 100010;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;//998244353;

/* --------------------------------------------------------------------------------------------------*/
typedef char TElemType;
typedef char Status;
typedef struct BiTnode
{
    TElemType data;
    struct BiTnode *lchild,*rchild;
}BitNode,*BiTree;
int N;
/* --------------------------------------------------------------------------------------------------*/
//"必做"
Status CreateBiTree(BiTree &T);//先序输入构造一个二叉树（注意空树）
//Visit是对节点操作的应用函数（例如输出节点信息）
Status PrintElement(TElemType e);
Status PreOrderTraverse(BiTree T,Status (*Visit)(TElemType e));//先序遍历二叉树
Status InOrderTraverse(BiTree T,Status (*Visit)(TElemType e));//中序遍历二叉树
Status PostOrderTraverse(BiTree T,Status (*Visit)(TElemType e));//后序遍历二叉树
//非递归的方法遍历二叉树（借助栈的操作）"三选一"
Status PreOrderTraverseStack(BiTree T,Status (*Visit)(TElemType e));//先序遍历二叉树
Status InOrderTraverseStack(BiTree T,Status (*Visit)(TElemType e));//先序遍历二叉树
Status PostOrderTraverseStack(BiTree T,Status (*Visit)(TElemType e));//先序遍历二叉树
//"选做"
Status BiTreeDepth(BiTree T);//求二叉树的高度
Status BiTreeLeaf(BiTree T);//求二叉树的叶子数
Status DeletLeftChild(TElemType,BiTree T);//删除节点e的左子树
Status LevelOrderTraverse(BiTree T,Status (*Visit)(TElemType e));//层次遍历二叉树

//简单操作函数
void myprintmenu()
{
    int n;
    cout << "input 1 to run BiTreeDepth" << endl; 
    cout << "input 2 to run BiTreeLeaf" << endl; 
    cout << "input 3 to run DeletLeftChild" << endl; 
    cout << "input 4 to run PreOrderTraverse" << endl; 
    cout << "input 5 to run InOrderTraverse" << endl; 
    cout << "input 6 to run PostOrderTraverse" << endl; 
    cout << "input 7 to run PreOrderTraverseStack" << endl; 
    cout << "input 8 to run InOrderTraverseStack" << endl; 
    cout << "input 9 to run PostOrderTraverseStack" << endl; 
    cout << "input 10 to run LevelOrderTraverse" << endl; 
    cout << "please input n:", cin >> n;
    if(n > 10 || n < 1)
    {
        cout << "error! Please try again" << endl;
    }
    switch(n)
    {
        case 1:
           // BiTreeDepth();
        case 2:
           // BiTreeLeaf();
        case 3:
           // DeletLeftChild();
        case 4:
           // PreOrderTraverse();
        case 5:
           // InOrderTraverse();
        case 6:
           // PostOrderTraverse();
        case 7:
           // PreOrderTraverseStack();
        case 8:
           // InOrderTraverseStack();
        case 9:
           // PostOrderTraverseStack();
        case 10:
           // LevelOrderTraverse();
        default:
            break;
    }
}
Status CreateBiTree(BiTree &T)
{
    if()
    return 0;
}
int main()
{
    std::ios::sync_with_stdio(false);
/* --------------------------------------------------------------------------------------------------*/
    cout << "Please input a binarytree,use '^' replace viod tree" <<endl;
    string tree;
    cin >> tree;
    N = 0;
    CreateBiTree();
    while(1)
    {
        cout << "please input 0 printf menu,input -1 exit " <<endl;
        int x;
        cin >> x;
        if(x == -1) 
            break;
        else myprintmenu();
    }
    return 0;
}

