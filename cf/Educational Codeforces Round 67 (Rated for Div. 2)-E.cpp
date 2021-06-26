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
const int MAX = 200010;//100000
const int MAX_1 = 2010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 10;//998244353;
int T,N,M;
/*-------------------------------------------------------------------------------------------*/
vector<int> edge[MAX];
LL tsize[MAX];
LL dp[MAX];
LL ans = 0;
/* ------------------------------------------------------------------------------------------*/
 
LL caculatesize(int n,int v)
{
    tsize[n] = 1;
    for(int i = 0;i < edge[n].size();i++)
    {
        if(edge[n][i] == v) continue;
        tsize[n] += caculatesize(edge[n][i],n);
    }
    return tsize[n];
}
 
LL firstdp(int n,int v)
{
    dp[n] = tsize[n];//mine
    for(int i = 0;i < edge[n].size();i++)//son
    {
        if(edge[n][i] == v) continue;
        dp[n] += firstdp(edge[n][i],n);
    }
    return dp[n];
}
 
void dfs(int n,int v)
{
    ans = max(ans,dp[n]);
    for(int i = 0;i < edge[n].size();i++)//to
    {
        if(edge[n][i] == v) continue;
        int to = edge[n][i];
        dp[n] -= dp[to];
        dp[n] -= tsize[to];
        tsize[n] -= tsize[to];
        tsize[to] += tsize[n];
        dp[to] += dp[n];
        dp[to] += tsize[n];
 
        dfs(to,n);
 
        dp[to] -= tsize[n];
        dp[to] -= dp[n];
        tsize[to] -= tsize[n];
        tsize[n] += tsize[to];
        dp[n] += tsize[to];
        dp[n] += dp[to];
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
    cin >> N;
    M = N - 1;
    int l,r;
    while(M--)
    {
        cin >> l >> r;
        edge[l].push_back(r);
        edge[r].push_back(l);
    }
    caculatesize(1,-1);
    ans = firstdp(1,-1);
    dfs(1,-1);
    cout << ans <<endl;
    return 0;
}