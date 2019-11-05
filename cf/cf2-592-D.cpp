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
int value[MAX][4];
ll dp[MAX][4][4];
vector<int> g[MAX];
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
    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < N;j++)
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
    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < 3;j++)
        {
            if(i == j) continue;
            dp[start][i][j] = value[start][j];
        }
    }

    int temp = start;
    start = g[start][1];
    int last = temp;
    
    while(1)
    {
        for(int i = 0;i < 3;i++)
        {
            for(int j = 0;j < 3;j++)
            {
                if(i == j) continue;
                int k;
                if(j == 0)
                {
                    k = i == 1 ? 2 : 1;
                    dp[start][j][k] = min(dp[last][i][j],dp[last][j][i]) + value[start][k];
                }
                else if(j == 1)
                {
                    k = i == 0 ? 2 : 0;
                    dp[start][j][k] = min(dp[last][i][j],dp[last][j][i]) + value[start][k];
                }
                else if(j == 2)
                {
                    k = i == 0 ? 1 : 0;
                    dp[start][j][k] = min(dp[last][i][j],dp[last][j][i]) + value[start][k];
                }
            }
        }
        int temp = start;
        if(g[start].size() == 1) break;
        start = g[start][0] == last ? g[start][1] : g[start][0];
        last = temp;
    }
    ll minans = INF64;
    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < 3;j++)
        {
            if(i == j) break;
            minans = min(dp[start][i][j],minans);
        }
    }
    cout << minans << "\n";
    return 0;
}

