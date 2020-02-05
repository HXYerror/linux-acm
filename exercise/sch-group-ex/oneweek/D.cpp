/*************************************************************************
	> File Name: D.cpp
	> Author: HXYerror
	> Mail: zx841985525@163.com 
	> Created Time: 2020年02月03日 星期一 15时14分37秒
 ************************************************************************/

#include <bits/stdc++.h>
#define ll  long long
using namespace std;
const int MAX = 200010;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;//998244353;

ll T,N,M,K;
/* --------------------------------------------------------------------------------------------------*/
vector<int> a[MAX];
int dp[MAX];
/* --------------------------------------------------------------------------------------------------*/
int dfs(int fa,int to)
{
    for(int i = 0;i < a[to].size();i++)
    {
        if(a[to][i] == fa) continue;
        else 
        {
            dp[to] += dfs(to,a[to][i]);
        }
    }
    dp[to]++;
    return dp[to];
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
        for(int i = 0;i < N-1;i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        dfs(-1,1);
        int ans = 0;
        for(int i = 2;i <= N;i++)
        {
            if(dp[i] >= K && N - dp[i] >= K) ans++;
        }
        cout << ans << endl;
        fill(dp,dp+MAX,0);
        for(int i = 1;i <=  N;i++)
        {
            a[i].clear();
        }
    }
    return 0;
}

