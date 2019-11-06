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
int value[4][MAX];
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
        for(int j = 1;j <= N;j++)
        {
            cin >> value[i][j];
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
    for(int i =0;i < N;i++)
    {

    }
    cout << minans << "\n";
    for(int i = N-1;i >= 0;i--)
    {
        cout << ans[i]+1;
        if(i != 0) cout << " ";
        else cout << "\n";
    }
    return 0;
}

