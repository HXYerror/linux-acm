/*************************************************************************
	> File Name: quicksort.cpp
	> Author: HXYerror
	> Mail: zx841985525@163.com 
	> Created Time: 2019年12月21日 星期六 20时23分29秒
 ************************************************************************/

#include <bits/stdc++.h>
#define ll  long long
using namespace std;
const int MAX = 100010;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;//998244353;

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
int Partition(SqList &L,int low,int high)
{
    L.r[0] = L.r[low];
    while(low < high)
    {
        while(low < high && L.r[high].key >= L.r[0].key) --high;
        L.r[low] = L.r[high];
        while(low < high && L.r[low].key <= L.r[0].key) ++low;
        L.r[high] = L.r[low];
    }
    L.r[low] = L.r[0];
    return low;
}
void Qsort(SqList &L,int low, int high)
{
    if(low < high)
    {
        int pivotloc = Partition(L,low,high);
        Qsort(L,low,pivotloc - 1);
        Qsort(L,pivotloc+1,high);
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
    Qsort(L,1,n);
    cout << "sort complete" << endl;
    for(int i = 1;i <= n;i++)
    {
        cout << L.r[i].key << " ";
    }
    return 0;
}

