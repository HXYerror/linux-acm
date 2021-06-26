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
const int MAX = 100010;//100000
const int MAX_1 = 100010;
const int INF = 100000;//0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;//998244353;
const double PI = acos(-1);
LL T,N,M;
/*-------------------------------------------------------------------------------------------*/
vector<int> edge[MAX];
int flag[MAX];
LL dp[MAX];
LL ans = INF;
/* ------------------------------------------------------------------------------------------*/
 
LL caculatesize(int n,int v)
{
    dp[n] = 0;
    for(int i = 0;i < edge[n].size();i++)
    {
        if(edge[n][i] == v) continue;
        dp[n] = max(caculatesize(edge[n][i],n),dp[n]);
    }
    if(flag[n] || dp[n]) return dp[n]+1;
    else return dp[n];
}
 
 
void dfs(int n,int v)
{
    ans = min(ans,dp[n]);
    for(int i = 0;i < edge[n].size();i++)//to
    {
        if(edge[n][i] == v) continue;
        int to = edge[n][i];
        LL temp = dp[n];
        if(dp[n] == (dp[to]+1))
        {
            dp[n] = 0;
            for(int j = 0;j < edge[n].size();j++)
            {
                if(edge[n][j] == edge[n][i]) continue;
                dp[n] = max(dp[n],(dp[edge[n][j]] || flag[edge[n][j]]) ? (dp[edge[n][j]]+1) : 0);
                //cout <<edge[n][j] << " " << flag[edge[n][j]]<<" "<<dp[n] << " ";
            }
        }
        else
        {
            if(v != -1) dp[n] = max((dp[v] || flag[v]) ? (dp[v]+1) : 0,dp[n]);
        }
        int temp2 = dp[to];
 
        dp[to] = max(dp[to],dp[n]+1);
 
        dfs(to,n);
 
        dp[n] = temp;
        dp[to] = temp2;
 
    }
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    cin >> N >> T;
    M = N - 1;
    int l,r;
    while(M--)
    {
        cin >> l >> r;
        edge[l].push_back(r);
        edge[r].push_back(l);
    }
    int x;
    while(T--)
    {
        cin >> x;
        flag[x] = 1;
    }
    ans = caculatesize(1,-1);
    dfs(1,-1);
    cout << ans <<endl;
    return 0;
}