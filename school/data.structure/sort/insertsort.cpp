/*************************************************************************
	> File Name: insertsort.cpp
	> Author: HXYerror
	> Mail: zx841985525@163.com 
	> Created Time: 2019年12月11日 星期三 08时06分11秒
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
    for(int i = 2;i <= L.length;i++)
    {
        if(L.r[i-1].key > L.r[i].key)
        {
            L.r[0] = L.r[i];
            int j;
            for(j = i-1;L.r[j].key > L.r[0].key;--j)
            {
                L.r[j+1] = L.r[j];
            }
            L.r[j+1] = L.r[0];
        }
    }
    cout << "sort complete" << endl;
    for(int i = 1;i <= n;i++)
    {
        cout << L.r[i].key << " ";
    }
    cout << endl;
    return 0;
}

