/*************************************************************************
	> File Name: heapsort.cpp
	> Author: HXYerror
	> Mail: zx841985525@163.com 
	> Created Time: 2019年12月21日 星期六 20时36分30秒
 ************************************************************************/

#include <bits/stdc++.h>
#define ll  long long
using namespace std;
const int MAX = 100010;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;//998244353;

ll T,N,M,K;
/* --------------------------------------------------------------------------------------------------*/
const int MAXSIZE = 100;
typedef int KeyType;
typedef struct 
{
    KeyType key;
}RcdTye;
typedef struct 
{
    RcdTye r[MAXSIZE+1];
    int length;
}SqList;
SqList L;
/* --------------------------------------------------------------------------------------------------*/
void HeapAdjust(SqList &L,int s,int m)
{
    RcdTye rc = L.r[s];
    for(int j = 2*s;j<=m;j*=2)
    {
        if(j < m && (L.r[j].key <= L.r[j+1].key)) ++j;
        if(rc.key > L.r[j].key) break;
        L.r[s] = L.r[j];
        s = j;
    }
    L.r[s] = rc;
}

void HeapSort(SqList &L)
{
    for(int i = L.length/2;i > 0;i--)
    {
        HeapAdjust(L,i,L.length);
    }
    for(int i = L.length;i >1;i--)
    {
        RcdTye temp = L.r[1];
        L.r[1] = L.r[i];
        L.r[i] =temp;
        HeapAdjust(L,1,i-1);
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
	//in
	//out
/* --------------------------------------------------------------------------------------------------*/
    cout << "please input the number of need sort:";
    int n;
    cin >> n;
    L.length = n;
    cout << "please input n numbers:";
    for(int i = 1;i <= n;i++)
    {
        cin >> L.r[i].key;
    }
    HeapSort(L);
    cout << "sort complete" << endl;
    for(int i = 1;i <= n;i++)
    {
        cout << L.r[i].key << " ";
    }
    cout << endl;
    return 0;
}

