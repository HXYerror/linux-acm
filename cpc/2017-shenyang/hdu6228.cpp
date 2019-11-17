/*************************************************************************
	> File Name: hdu6228.cpp
	> Author: HXYerror
	> Mail: zx841985525@163.com 
	> Created Time: 2019年11月12日 星期二 19时54分25秒
 ************************************************************************/

#include <bits/stdc++.h>
#define ll  long long
using namespace std;
const int MAX = 200010;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;//998244353;

ll T,N,M,K;
/* --------------------------------------------------------------------------------------------------*/
vector<int> g[MAX];
int dp[MAX];
/* --------------------------------------------------------------------------------------------------*/
int dfs(int f,int root)
{
    int to;
    for(int i = 0;i < g[root].size();i++)
    {
        to = g[root][i];
        if(to == f) continue;
        else dp[root] += dfs(root,to);
    }
    dp[root]++;
    return dp[root];
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
	//in
	//out
/* --------------------------------------------------------------------------------------------------*/
    cin >> T;
    while(T--)
    {
        cin >> N >> K;
        int x,y;
        set<int> flag;
        ll n = N - 1;
        while(n--)
        {
            cin >> x >> y;
            flag.insert(x);
            flag.insert(y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        dfs(-1,1);
        int ans = 0;
        for(auto it = flag.begin();it != flag.end();it++)
        {
            if(dp[*it] >= K && N - dp[*it] >= K) ans++;
        }
        cout << ans << endl;
        for(auto it = flag.begin();it != flag.end();it++)
        {
            g[*it].clear();
            dp[*it] = 0;
        }
    }
    return 0;
}

