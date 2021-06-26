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
const int MAX_1 = 1000010;
const int INF = 0xfffffff;//268435455,2e8;
const double EPS = 0.0000001;
const int MOD = 10000007;
int T,N,M;


/*-------------------------------------------------------------------------------------------*/
struct noname
{
    int h,l;
}dp[MAX][MAX];
int dpp[MAX][MAX];
int graph[MAX][MAX];
/* ------------------------------------------------------------------------------------------*/


int main()
{
    //std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    cin >> N >>M;
    for(int i = 1;i <= N;i++)
    {
        for(int j = 1;j <= M;j++)
        {
            cin >> graph[i][j];
            if(graph[i][j] == 0) dp[i][j].h = dp[i][j].l = 0;
            else
            {
                dp[i][j].h = dp[i-1][j].h+ 1;
                dp[i][j].l = dp[i][j-1].l+ 1;
            }
        }

    }
    int ans = 0;
    for(int i = 1;i <= N;i++)
    {
        for(int j = 1;j <= M;j++)
        {
            if(min(dp[i][j].h,dp[i][j].l) >= dpp[i-1][j-1]+1)
            {
                dpp[i][j] = dpp[i-1][j-1] + 1;
            }
            else dpp[i][j] = min(dp[i][j].h,dp[i][j].l);
            ans = max(dpp[i][j],ans);
        }
    }
    cout << ans << "\n";
}