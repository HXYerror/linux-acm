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
const int MAX = 100010;
const int INF = -0xfffffff;//268435455,2e8;
const double EPS = 0.0000001;
const int MOD = 1000000007;
int T,N,M;


/*-------------------------------------------------------------------------------------------*/

int a[MAX];
int dp[MAX];
/* ------------------------------------------------------------------------------------------*/

int main()
{
    //std::ios::sync_with_stdio(false);
    cin >> T;
    for(int j = 1;j <= T;j++)
    {
        cin >> N;
        for(int i =1;i <= N;i++)
        {
            cin >> a[i];
        }
        int l,r,ans;
        int nl;
        dp[1] = a[1];
        nl = 1;
        ans = a[1];
        l = 1;
        r = 1;
        for(int i = 2;i <=N;i++)
        {
            if(dp[i-1] >= 0)
            {
                dp[i] = dp[i-1]+a[i];
            }
            else
            {
                dp[i] = a[i];
                nl = i;
            }
            if(dp[i] > ans)
            {
                ans = dp[i];
                l = nl;
                r = i;
            }
        }
        cout << "Case " << j << ":\n";
        cout << ans << " " << l << " " << r << "\n";
        if(j != T) cout << "\n";
    }
    return 0;
}

