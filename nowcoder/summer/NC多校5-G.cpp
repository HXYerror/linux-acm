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
const int MAX = 3010;//100000
const int MAX_1 = 2;
const int MAX_2 = 1000010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;//998244353;
const double PI = acos(-1);
LL T,N,M,K;
/*-------------------------------------------------------------------------------------------*/
LL C[MAX][MAX];
LL dp[MAX][MAX];
/* ------------------------------------------------------------------------------------------*/
 
int main()
{
    //std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* -----------------------------------------------------------------------------------------*/
    for(int i = 0;i < MAX;i++)//组合数
    {
        C[i][0] = 1;
        for(int j = 1;j <= i;j++)
        {
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
        }
    }
    cin >> T;
    string s,t;
    while(T--)
    {
        cin >> N >> M;
        cin >> s >> t;
        LL ans = 0;
        for(int i = 0;i < N;i++)//长度大于M的部分
        {
            if(s[i] == '0') continue;
            int n = N - i - 1;
            for(int j = M;j <= n;j++)
            {
                ans = (ans + C[n][j]) % MOD;
            }
        }
//cout << ans <<endl;
        dp[0][0] = 0;
        if(s[0] == t[0]) dp[0][0] = 1;
        if(s[0] > t[0]) ans = (ans + C[N-1][M-1]) % MOD;
        for(int i = 1;i < N;i++)
        {
            if(s[i] == t[0]) dp[i][0] = dp[i-1][0]+1;
            else dp[i][0] = dp[i-1][0];
            if(s[i] > t[0]) ans = (ans + C[N-i-1][M-1]) % MOD;
//cout << i << " " <<ans <<endl;
        }
 
        for(int i = 1;i < N;i++)
        {
            for(int j = 1;j < min(M,(LL)i+1);j++)
            {
                if(s[i] == t[j]) dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % MOD;
                else dp[i][j] = dp[i-1][j];
                if(s[i] > t[j]) ans = (ans + (C[N-i-1][M-j-1] * dp[i-1][j-1]) % MOD ) % MOD;
//cout << s[i] << " " << j << " "<<ans <<endl;
            }
        }
        cout << ans <<endl;
    }
    return 0;
}