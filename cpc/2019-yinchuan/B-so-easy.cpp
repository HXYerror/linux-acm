/*************************************************************************
	> File Name: B-so-easy.cpp
	> Author: HXYerror
	> Mail: zx841985525@163.com 
	> Created Time: 2019年12月23日 星期一 22时06分52秒
 ************************************************************************/

#include <bits/stdc++.h>
#define ll  long long
using namespace std;
const int MAX = 1010;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;//998244353;

ll T,N,M,K;
/* --------------------------------------------------------------------------------------------------*/
int a[MAX][MAX];
int x,y;
/* --------------------------------------------------------------------------------------------------*/

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
	//in
	//out
/* --------------------------------------------------------------------------------------------------*/
    cin >> N;
    for(int i = 0;i < N;i++)
    {
        for(int j = 0;j < N;j++)
        {
            cin >> a[i][j];
            if(a[i][j] == -1)
            {
                x = i;
                y = j;
            }
        }
    }
    int c,d;
    int n,m;
    int minx = INF;
    for(int i = 0;i < N;i++)
    {
        if(i == y) continue;
        if(a[x][i] < minx)
        {
            minx = a[x][i];
            n = i;
        }
    }
    c = minx;
    minx = INF;
    for(int i = 0;i < N;i++)
    {
        if(i == x) continue;
        if(a[i][y] < minx)
        {
            minx = a[i][y];
            m = i;
        }
    }
    d = minx;
    cout << c + d - a[m][n] << endl;
    return 0;
}

