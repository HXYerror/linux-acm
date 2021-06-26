#include<bits/stdc++.h>
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
#include <deque>
#include <utility>
#define LL long long
using namespace std;
const int MAX = 300020;//100000
const int MAX_1 = 15;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;//998244353;
const double PI = acos(-1);
LL T,N,M,K;
/*-------------------------------------------------------------------------------------------*/
LL a[MAX];
LL dp[MAX][MAX_1];
/* ------------------------------------------------------------------------------------------*/
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    cin >> N >> M >> K;
    for(int i = 1;i <= N;i++)
    {
        cin >> a[i];
    }
    for(int i = 0;i < MAX;i++)
    {
        for(int j = 0;j < MAX_1;j++)
        {
            dp[i][j] = -INF;
        }
    }
    LL ans = 0;
    for(int i = 1;i <= N;i++)
    {
        for(int j = 0;j < M;j++)
        {
            if(j == 1 || M == 1)
            {
                dp[i][j] = max(dp[i-1][0] + a[i] - K,a[i] - K);
            }
            else if(j == 0)
            {
                dp[i][j] = dp[i-1][M-1] + a[i];
            }
            else
            {
                dp[i][j] = dp[i-1][j-1] + a[i];
            }
            ans = max(ans,dp[i][j]);
        }
    }
    cout << ans <<endl;
    return 0;
}