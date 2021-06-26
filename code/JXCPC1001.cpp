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
const int MAX = 100020;//100000
const int MAX_1 = 70;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;//998244353;
const double PI = acos(-1);
LL T,N,M;
/*-------------------------------------------------------------------------------------------*/
LL dp1[MAX];
LL dp2[MAX];
int tsize1[MAX];//有多少个子节点
int tsize2[MAX];
vector<int> edge[MAX];
int flag[MAX];
LL ans = 0;
LL tree1,tree2,tmin;
/* ------------------------------------------------------------------------------------------*/
void tempcout(LL a[])
{
    for(int i = 1;i <= N;i++)
    {
        cout << a[i] << " ";
    }
    cout <<endl;
}

void dfsfindroot(int n)
{
    flag[n] = 1;
    for(int i = 0;i < edge[n].size();i++)
    {
        int m = edge[n][i];
        if(flag[m]) continue;
        else
        {
            flag[m] = 1;
            dfsfindroot(m);
        }
    }
}

int casize(int tsize[],int n,int v)
{
    for(int i = 0;i < edge[n].size();i++)
    {
        int m = edge[n][i];
        if(m == v) continue;
        else
        {
            tsize[n] += casize(tsize,m,n);
        }
    }
    return tsize[n] + 1;
}

int dfs_dpfirst(LL dp[],int tsize[],int n,int v)
{
    dp[n] = tsize[n];
    for(int i = 0;i < edge[n].size();i++)
    {
        int to = edge[n][i];
        if(to == v) continue;
        else
        {
            dp[n] += dfs_dpfirst(dp,tsize,to,n);
        }
    }
    return dp[n];
}

void dfs_rerooting(LL dp[],int tsize[],int n,int v)
{
    ans += dp[n];
    tmin = min(tmin,dp[n]);
    for(int i = 0;i < edge[n].size();i ++)
    {
        int to = edge[n][i];
        if(to == v) continue;

        dp[n] -= dp[to];
        dp[n] -= tsize[to];
        tsize[n] -= (tsize[to]+1);
        tsize[to] += (tsize[n]+1);
        dp[to] += dp[n];
        dp[to] += tsize[n];

        dfs_rerooting(dp,tsize,to,n);

        dp[to] -= tsize[n];
        dp[to] -= dp[n];
        tsize[to] -= (tsize[n]+1);
        tsize[n] += (tsize[to]+1);
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
    M = N - 2;
    int u,v;
    LL t1,t2,node1,node2;
    node1 = node2 = 0;
    LL minans = 0;
    while(M--)
    {
        cin >> u  >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfsfindroot(1);

    t1 = 1;
    for(int i = 1;i <= N;i++)
    {
        if(flag[i]) node1++;
        if(!flag[i])
        {
            t2 = i;
        }
    }
    node2 = N - node1;

    casize(tsize1,t1,-1);
//tempcout(tsize1);
    dfs_dpfirst(dp1,tsize1,t1,-1);
//tempcout(dp1);
    tmin = INF;
    ans = 0;
    dfs_rerooting(dp1,tsize1,t1,-1);
    tree1 = tmin;
    minans += ans>>1;
//cout << ans <<endl;

    casize(tsize2,t2,-1);
//tempcout(tsize2);
    dfs_dpfirst(dp2,tsize2,t2,-1);
//tempcout(dp2);
    tmin = INF;
    ans = 0;
    dfs_rerooting(dp2,tsize2,t2,-1);
    tree2 = tmin;
    minans += ans>>1;
//cout << ans <<endl;

    minans += node1 * node2;
    minans += node1 * tree2;
    minans += node2 * tree1;
//cout << node1 << " " << node2 << " " << tree1 << " " << tree2 <<endl;
    cout << minans <<endl;
    return 0;
}