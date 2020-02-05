/*************************************************************************
	> File Name: E.cpp
	> Author: HXYerror
	> Mail: zx841985525@163.com 
	> Created Time: 2020年02月04日 星期二 13时15分59秒
 ************************************************************************/

#include <bits/stdc++.h>
#define ll  long long
using namespace std;
const int MAX = 200010;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;//998244353;

ll T,N,M,K;
/* --------------------------------------------------------------------------------------------------*/
int dp[30][MAX];
/* --------------------------------------------------------------------------------------------------*/

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
	//in
	//out
/* --------------------------------------------------------------------------------------------------*/
    string str;
    cin >> N >> M;
    cin >> str;
    int ans = INF;
    for(int i = 0;i < N;i++)
    {
        int x = str[i] - 'a'; 
        int next = ++dp[x][0];
        dp[x][next] = i;
        if(next >= M)
        {
            cout << ans << endl;
            ans = min(dp[x][next] - dp[x][next - M +1] + 1,ans);
            cout <<dp[x][next] - dp[x][M-next+1] + 1<< endl;
        }
    }
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}

