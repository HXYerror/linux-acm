/*************************************************************************
	> File Name: binary.tree.cpp
	> Author: HXYerror
	> Mail: zx841985525@163.com
	> Created Time: 2019年10月29日 星期二 20时43分55秒
 ************************************************************************/

#include <bits/stdc++.h>
#define ll  long long
#define OK 1
#define ERROR 0
#define FALSE 0
#define TRUE 1
#define _OVERFLOW -2
using namespace std;
const int MAX = 100010;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;//998244353;
const int MAXSIZE = 1000;
/* --------------------------------------------------------------------------------------------------*/
typedef char TElemType;
typedef char TStatus;
typedef struct BiTnode
{
    TElemType data;
    struct BiTnode *lchild,*rchild;
}BitNode,*BiTree;
int N;//记录读取的节点位置
struct mystack
{
    typedef  BiTree  ElemType;
    typedef  int  Status;
    typedef struct
    {
        ElemType *base;
        ElemType  *top;
        int  stackSize;
    } SqStack;
    SqStack Stack;
    #define STACK_INIT_SIZE 10 // 存储空间的初始分配量
    #define STACKINCREMENT 5// 存储空间的分配增量
    //初始化栈
    Status InitStack(SqStack &S)
    {
        S.base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
        if(!S.base) exit (_OVERFLOW);
            S.top = S.base;
        S.stackSize = STACK_INIT_SIZE;
        return OK;
    }

    // 判栈 S 是否为空栈
    Status StackEmpty(SqStack S)
    {
        if (S.top==S.base) return  TRUE;
        else return  FALSE;
    }

    //入栈函数
    Status Push (SqStack &S, ElemType e)
    {
        if(S.top - S.base >= S.stackSize)
        {
            S.base = (ElemType *)realloc(S.base,(S.stackSize + STACKINCREMENT) * sizeof(ElemType));
            if(!S.base) exit(_OVERFLOW);
            S.top = S.base + S.stackSize;
            S.stackSize += STACKINCREMENT;
        }
        *S.top++ = e;
        return OK;
    }

    //出栈函数
    Status Pop (SqStack &S, ElemType &e)
    {
        if(S.top == S.base) return ERROR;
        e = * --S.top;
        return OK;
    }
}S;

struct myqueue
{
    typedef int  QStatus;
    typedef BitNode QElemType;//定义数据类型

    //循环队列的顺序存储结构
    typedef struct{
        QElemType data[MAXSIZE] ;
        int front; //头指针
        int rear;//尾指针，队列非空时，指向队尾元素的下一个位置
    }SqQueue;
    SqQueue Queue;
    //初始化空队列
    QStatus InitQueue(SqQueue *sQ){
        sQ->front =0;
        sQ->rear =0;
        return OK;
    }

    //将队列清空
    QStatus ClearQueue(SqQueue *Q){
        Q->front = Q->rear =0;
        return OK;
    }

    //判断队列是否为null
    QStatus QueueEmpty(SqQueue Q){
        if(Q.front == Q.rear)
            return TRUE;
        else
            return FALSE;
    }

    //返回队头元素
    QStatus GetHead(SqQueue Q, QElemType *e){
        if(Q.front == Q.rear)//是否为空队列
            return ERROR;
        *e = Q.data[Q.front];
        return OK;
    }

    //在队尾插入元素
    QStatus EnQueue(SqQueue *Q, QElemType e){
        if((Q->rear+1)%MAXSIZE == Q->front)//队列已满
            return ERROR;

        Q->data[Q->rear] =e;//插入队尾
        Q->rear = (Q->rear +1)%MAXSIZE;//尾部指针后移，如果到最后则转到头部
        return OK;
    }

    //元素出队
    QStatus DeQueue(SqQueue *Q, QElemType *e){
        if(Q->front == Q->rear)//队列空
            return ERROR;
        *e = Q->data[Q->front];//返回队头元素
        Q->front = (Q->front+1)%MAXSIZE;//队头指针后移，如到最后转到头
        return OK;
    }
};

/* --------------------------------------------------------------------------------------------------*/
//"必做"
bool  CreateBiTree(BiTree &T,string str);//先序输入构造一个二叉树（注意空树）1
//Visit是对节点操作的应用函数（例如输出节点信息）
TStatus PrintElement(TElemType e);//输出节点信息  1
TStatus PreOrderTraverse(BiTree T,TStatus (*Visit)(TElemType e));//先序遍历二叉树1
TStatus InOrderTraverse(BiTree T,TStatus (*Visit)(TElemType e));//中序遍历二叉树1
TStatus PostOrderTraverse(BiTree T,TStatus (*Visit)(TElemType e));//后序遍历二叉树1
//非递归的方法遍历二叉树（借助栈的操作）"三选一"
TStatus PreOrderTraverseStack(BiTree T,TStatus (*Visit)(TElemType e));//先序遍历二叉树
TStatus InOrderTraverseStack(BiTree T,TStatus (*Visit)(TElemType e));//先序遍历二叉树
TStatus PostOrderTraverseStack(BiTree T,TStatus (*Visit)(TElemType e));//先序遍历二叉树
//"选做"
int BiTreeDepth(BiTree T);//求二叉树的高度1
int BiTreeLeaf(BiTree T);//求二叉树的叶子数1
TStatus DeletLeftChild(TElemType,BiTree T);//删除节点e的左子树1
TStatus LevelOrderTraverse(BiTree T,TStatus (*Visit)(TElemType e));//层次遍历二叉树

//简单操作函数
void myprintmenu(BiTree T);//输出菜单选择执行的函数1
TStatus FindElement(BiTree T,TElemType f,BiTree p);//寻找指定的节点e并储存到p中1


//函数编写
void myprintmenu(BiTree T)
{
    int n;
    cout << "if need menu input 1 ,else intput 0: ";
    cin >> n;
    if(n)
    {
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
    }
    cout << "please input your choice:", cin >> n;
    if(n > 10 || n < 1)
    {
        cout << "error! Please try again" << endl;
    }
    switch(n)
    {
        case 1:
            BiTreeDepth(T);
        case 2:
            BiTreeLeaf(T);
        case 3:
            TElemType e;
            cout << "please input the value of node e:";
            cin >> e;
            if(DeletLeftChild(e,T)) cout << "delet OK" <<endl;
            else cout << "delet ERROR" <<endl;
            break;
        case 4:
            PreOrderTraverse(T,PrintElement);
            cout << endl;
            break;
        case 5:
            InOrderTraverse(T,PrintElement);
            cout <<endl;
            break;
        case 6:
            PostOrderTraverse(T,PrintElement);
            cout << endl;
            break;
        case 7:
           // PreOrderTraverseStack();
        case 8:
            InOrderTraverseStack(T,PrintElement);
        case 9:
           // PostOrderTraverseStack();
        case 10:
           // LevelOrderTraverse();
        default:
            break;
    }
}
bool CreateBiTree(BiTree &T,string str)
{
    if(N == (int) str.size()) return ERROR;
    if(str[N] == '^')
    {
        N++;
        T = NULL;
        return OK;
    }
    else
    {
        T = (BitNode *) malloc(sizeof(BitNode));
        T -> data = str[N++];
        if(CreateBiTree(T -> lchild,str))
            if(CreateBiTree(T -> rchild,str)) return OK;
        return ERROR;
    }
}
//abd^^^ceg^^h^^f^i^^
TStatus PrintElement(TElemType e)
{
    cout << e << " ";
    return OK;
}
TStatus PreOrderTraverse(BiTree T,TStatus (*Visit)(TElemType e))//先序遍历二叉树
{
    if(T)
    {
        if(Visit(T->data))
            if(PreOrderTraverse(T->lchild,Visit))
                if(PreOrderTraverse(T->rchild,Visit)) return OK;
        return ERROR;
    }
    else  return OK;
}
TStatus InOrderTraverse(BiTree T,TStatus (*Visit)(TElemType e))//中序遍历二叉树
{
    if(T)
    {
        if(InOrderTraverse(T->lchild,Visit))
            if(Visit(T->data))
                if(InOrderTraverse(T->rchild,Visit)) return OK;
        return ERROR;
    }
    else  return OK;
}
TStatus PostOrderTraverse(BiTree T,TStatus (*Visit)(TElemType e))//后序遍历二叉树
{
    if(T)
    {
        if(PostOrderTraverse(T->lchild,Visit))
            if(PostOrderTraverse(T->rchild,Visit))
                if(Visit(T->data)) return OK;
        return ERROR;
    }
    else  return OK;
}
TStatus FindElement(BiTree T,TElemType f,BiTree p)
{
    if(T)
    {
        if(f == T->data)
        {
            p = T;
            return OK;
        }
        if(FindElement(T->lchild,f,p))
            if(FindElement(T->rchild,f,p)) return OK;
        return ERROR;
    }
    else  return OK;
}
TStatus DeletLeftChild(TElemType e,BiTree T)//删除节点e的左子树
{
    if(T == NULL) return ERROR;
    BiTree P = NULL;
    FindElement(T,e,P);
    if(P== NULL) return ERROR;
    P -> lchild = NULL;
    return OK;
}
int BiTreeLeaf(BiTree T)//求二叉树的叶子数
{
    if(T == NULL) return ERROR;
    if(!T->lchild && !T->rchild) return OK;
    else
    {
        int cntleaf = 0;
        cntleaf += BiTreeLeaf(T);
        cntleaf += BiTreeLeaf(T);
        return cntleaf;
    }
}

int BiTreeDepth(BiTree T)//求二叉树的高度error
{
    if(T == NULL) return ERROR;
    else
    {
        int ldepth = BiTreeDepth(T->lchild);
        int rdepth = BiTreeDepth(T->rchild);
        return max(ldepth,rdepth) + 1;
    }
}
TStatus InOrderTraverseStack(BiTree T,TStatus (*Visit)(TElemType e))//先序遍历二叉树
{
    BiTree p;
    p = T;
    S.InitStack(S.Stack);
    do
    {
        if(p!=NULL)
        {
            S.Push(S.Stack,p);
            p = p->lchild;
        }
        else
        {
            S.Pop(S.Stack,p);
            Visit(p->data);
            p = p->rchild;
        }
    }while(!(p==NULL)&& S.StackEmpty(S.Stack));
    return OK;
}
int main()
{
    std::ios::sync_with_stdio(false);
/* --------------------------------------------------------------------------------------------------*/
    cout << "Please input a binarytree-char,use '^' replace viod tree" <<endl;
    string tree;
    cin >> tree;
    N = 0;
    BiTree mytree;
    while(!CreateBiTree(mytree,tree))
    {
        cout << "input ERROR,please input binarytree-char again: ";
        cin >> tree;
        free(mytree);
        N = 0;
    }
    while(1)
    {
        cout << "please input 0 continue,input -1 exit " <<endl;
        int x;
        cin >> x;
        if(x == -1)
            break;
        else myprintmenu(mytree);
    }
    return 0;
}

