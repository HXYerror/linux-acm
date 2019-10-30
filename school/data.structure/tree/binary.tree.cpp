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
typedef int ElemType;
typedef int Status;
typedef struct BiTnode
{
    ElemType data;
    struct BiTnode *lchild,*rchild;
}BitNode,*BiTree;
/* --------------------------------------------------------------------------------------------------*/
//"必做"
Status CreateBiTree(BiTree &T);//先序输入构造一个二叉树（注意空树）
//Visit是对节点操作的应用函数（例如输出节点信息）
Status PrintElement(ElemType e);
Status PreOrderTraverse(BiTree T,Status (*Visit)(ElemType e));//先序遍历二叉树
Status InOrderTraverse(BiTree T,Status (*Visit)(ElemType e));//中序遍历二叉树
Status PostOrderTraverse(BiTree T,Status (*Visit)(ElemType e));//后序遍历二叉树
//非递归的方法遍历二叉树（借助栈的操作）"三选一"
Status PreOrderTraverseStack(BiTree T,Status (*Visit)(ElemType e));//先序遍历二叉树
Status InOrderTraverseStack(BiTree T,Status (*Visit)(ElemType e));//先序遍历二叉树
Status PostOrderTraverseStack(BiTree T,Status (*Visit)(ElemType e));//先序遍历二叉树
//"选做"
Status BiTreeDepth(BiTree T);//求二叉树的高度
Status BITreeLeaf(BiTree T);//求二叉树的叶子数
Status DeletLeftChild(ElemType,BiTree T);//删除节点e的左子树
Status LevelOrderTraverse(BiTree T,Status (*Visit)(ElemType e));//层次遍历二叉树

//简单操作函数


Status CreateBiTree(BiTree &T)
{

}
int main()
{
    std::ios::sync_with_stdio(false);
/* --------------------------------------------------------------------------------------------------*/
        
    return 0;
}

