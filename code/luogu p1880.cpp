//#include<bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#define LL long long
using namespace std;
const int MAX = 110;
const int MAX_1 = 100;
const int INF = 0xfffffff;//268435455,2e8;
const double EPS = 0.0000001;
const int MOD = 1000000007;
int T,N,M;

/*-------------------------------------------------------*/

int a[2*MAX];
int dpa[2*MAX][2*MAX];
int dpi[2*MAX][2*MAX];
int sum[2*MAX];

/* --------------------------------------------------------------*/



int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
/* --------------------------------------------------------------*/
    cin >> N;
    for(int i = 1;i <= N;i++)
    {
        cin >> a[i];
        a[i+N] = a[i];
    }
    sum[0] = 0;
    for(int i = 0;i <= N;i++)
    {
        fill(dpa[i],dpa[i]+N+1,0);
        fill(dpi[i],dpi[i]+N+1,0);
    }
    for(int i = 1;i <= 2*N;i++)
    {
        sum[i] = sum[i-1] + a[i];
    }
    for(int l = 2;l <= N;l++)
    {
        for(int i = 1;i+l-1 <= 2*N;i++)
        {
            int j = i + l - 1;
            dpi[i][j] = INF;//why?why?why?
            for(int k = i;k < j;k++)
            {
                dpa[i][j] = max(dpa[i][j],dpa[i][k] + dpa[k+1][j] + sum[j] - sum[i-1]);
                dpi[i][j] = min(dpi[i][j],dpi[i][k] + dpi[k+1][j] + sum[j] - sum[i-1]);

                //cout << i << " " << j << " " << k <<endl;
                //cout <<dpa[i][j] << " " << dpi[i][j] <<endl;
            }
        }
    }
    int ma = 0;
    int mi = INF;
    for(int i = 1;i <= N;i++)
    {
        ma = max(ma,dpa[i][i+N-1]);
        mi = min(mi,dpi[i][i+N-1]);
    }
    cout << mi << "\n" << ma << "\n";
    return 0;
}

