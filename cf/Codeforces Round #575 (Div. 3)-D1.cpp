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
const int MAX = 200010;//100000
const int MAX_1 = 100010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;//998244353;
const double PI = acos(-1);
LL T,N,M;
/*-------------------------------------------------------------------------------------------*/
int dp[3][MAX];
string rgb = "RGB";
/* ------------------------------------------------------------------------------------------*/
 
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    cin >> T;
    string str;
    while(T--)
    {
        cin >> N >> M;
        cin >> str;
        int ans = INF;
        dp[0][0] = (str[0] != rgb[0] ? 1 : 0) ;
        dp[1][0] = (str[0] != rgb[1] ? 1 : 0) ;
        dp[2][0] = (str[0] != rgb[2] ? 1 : 0) ;
        for(int i = 1;i < M;i++)
        {
            dp[0][i] = (str[i] != rgb[i % 3]     ? 1 : 0 ) + dp[0][i-1];
            dp[1][i] = (str[i] != rgb[(i+1) % 3] ? 1 : 0 ) + dp[1][i-1];
            dp[2][i] = (str[i] != rgb[(i+2) % 3] ? 1 : 0 ) + dp[2][i-1];
        }
        for(int i = 0;i < 3;i++)
        {
            ans = min(ans,dp[i][M-1]);
            if(ans == 0) break;
        }
        for(int i = M;i < N;i++)
        {
            dp[0][i] = dp[0][i-1] - (str[i - M] != rgb[(i - M) % 3] ? 1 : 0)  + (str[i] != rgb[i % 3]? 1 : 0);
            dp[1][i] = dp[1][i-1] - (str[i - M] != rgb[(i - M+1) % 3]? 1 : 0) + (str[i] != rgb[(i+1) % 3]? 1 : 0);
            dp[2][i] = dp[2][i-1] - (str[i - M] != rgb[(i - M+2) % 3]? 1 : 0) + (str[i] != rgb[(i+2) % 3]? 1 : 0);
            for(int j = 0;j < 3;j++)
            {
                ans = min(ans,dp[j][i]);
            }
            if(ans == 0) break;
        }
        cout << ans <<endl;
    }
    return 0;
}