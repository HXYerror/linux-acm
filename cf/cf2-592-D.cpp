/*************************************************************************
	> File Name: cf2-592-D.cpp
	> Author: HXYerror
	> Mail: zx841985525@163.com 
	> Created Time: 2019年11月05日 星期二 19时40分17秒
 ************************************************************************/

#include <bits/stdc++.h>
#define ll  long long
using namespace std;
const int MAX = 100010;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;//998244353;
const ll INF64 = 1e18;

ll T,N,M,K;
/* --------------------------------------------------------------------------------------------------*/
int value[MAX][5];
vector<int> g[MAX];
ll dp[10];
int ans[MAX][10];
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
    for(int i = 1;i < 4;i++)
    {
        for(int j = 1;j <= N;j++)
        {
            cin >> value[j][i];
        }
    }
    int x,y;
    for(int i = 0;i < N-1;i++)
    {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bool flag = true;
    int start = 1;
    for(int i = 1;i <= N;i++)
    {
        if(g[i].size() > 2)
        {
            flag = false;
            break;
        }
        if(g[i].size() == 1) start = i;
    }
    if(!flag) 
    {
        cout << "-1" << endl;
        return 0;
    }
    //12,13,21,23,31,32
    int last = -1;
    int cnt = 0;
    dp[0] = dp[1] = value[start][1];
    dp[2] = dp[3] = value[start][2];
    dp[4] = dp[5] = value[start][3];
    ans[start][0] = ans[start][1] = 1;
    ans[start][2] = ans[start][3] = 2;
    ans[start][4] = ans[start][5] = 3;
    cnt++;
    last = start;
    start = g[start][0];
    while(1)
    {
        int m = cnt % 3;
        if(m == 2)
        {
            dp[0] += value[start][3];
            dp[1] += value[start][2];
            dp[2] += value[start][3];
            dp[3] += value[start][1];
            dp[4] += value[start][2];
            dp[5] += value[start][1];
            ans[start][0] = 3;
            ans[start][1] = 2;
            ans[start][2] = 3;
            ans[start][3] = 1;
            ans[start][4] = 2;
            ans[start][5] = 1;
        }
        else if(m == 1)
        {
            dp[0] += value[start][2];
            dp[1] += value[start][3];
            dp[2] += value[start][1];
            dp[3] += value[start][3];
            dp[4] += value[start][1];
            dp[5] += value[start][2];
            ans[start][0] = 2;
            ans[start][1] = 3;
            ans[start][2] = 1;
            ans[start][3] = 3;
            ans[start][4] = 1;
            ans[start][5] = 2;
        }
        else if(m == 0)
        {
            dp[0] += value[start][1];
            dp[1] += value[start][1];
            dp[2] += value[start][2];
            dp[3] += value[start][2];
            dp[4] += value[start][3];
            dp[5] += value[start][3];
            ans[start][0] = 1;
            ans[start][1] = 1;
            ans[start][2] = 2;
            ans[start][3] = 2;
            ans[start][4] = 3;
            ans[start][5] = 3;
        }
        if(g[start].size() == 1) break;
        int temp = start;
        start = g[start][0] == last ? g[start][1] : g[start][0];
        last = temp;
        cnt++;
    }
    ll minans = INF64;
    int temp = -1;
    for(int i = 0;i < 6;i++)
    {
        if(minans > dp[i])
        {
            minans = dp[i];
            temp = i;
        }
    }
    cout << minans << "\n";
    for(int i = 1;i <= N ;i++)
    {
        cout << ans[i][temp];
        if(i != N) cout << " ";
        else cout << "\n";
    }
    return 0;
}

