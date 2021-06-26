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
const int MAX = 210;
const int MAX_1 = 500000;
const int INF = 0xfffffff;//268435455,2e8;
const double EPS = 0.0000001;
const int MOD = 10000007;
int T,N,M;

/*-------------------------------------------------------------------------------------------*/

LL a[MAX][MAX];
LL dp[MAX][MAX];
/* ------------------------------------------------------------------------------------------*/


int main()
{
    //std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
/* --------------------------------------------------------------------------------------*/
    cin >> N >> M;
    for(int i = 1;i <= N;i++)
    {
        for(int j = 1;j <= M;j++)
        {
            cin >> a[i][j];
        }
    }
    int k = (M + 1) / 2;
//    for(int i = 0;i < MAX;i++)
//    {
//        fill(dp[i],dp[i]+MAX,-INF);
//    }
    for(int i = 1;i <= M;i++)
    {
        dp[1][i] = a[1][i];
    }
    for(int i = 2;i <= N;i++)
    {
        for(int j = 1;j <= M;j++)
        {
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]);
            dp[i][j] = max(dp[i][j],dp[i-1][j+1]);
            dp[i][j] += a[i][j];
            //cout << i << " " << j << " " << a[i][j] << " " << dp[i-1][j-1] <<" "<< dp[i-1][j] << " " << dp[i-1][j+1] << " "<< dp[i][j]<< endl;
        }
    }
    LL ans = -INF;
    ans = max(dp[N][k],dp[N][k+1]);
    ans = max(ans,dp[N][k-1]);
    cout << ans << "\n";
    return 0;
}