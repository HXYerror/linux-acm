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
const int MAX = 110;
const int MAX_1 = 100;
const int INF = 0xfffffff;//268435455,2e8;
const double EPS = 0.0000001;
const int MOD = 1000000007;
int T,N,M;

/*-------------------------------------------------------*/

int a[MAX];
int dp[MAX];

/* --------------------------------------------------------------*/



int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
/* --------------------------------------------------------------*/
    cin >>N;
    for(int i = 1;i <= N;i++)
    {
        cin >> a[i];
    }
    int mi = INF;
    for(int k = 1;k <= N;k++)
    {
        fill(dp,dp+MAX,0);
        int ans =0;
        dp[0] = a[k];
        for(int i = k-1;i >= 1;i--)
        {
            for(int j = k-1;j >= 1;j--)
            {
                if(dp[j-1] > a[i])
                {
                    dp[j] = max(a[i],dp[j]);
                }
                if(dp[j] != 0 && j > ans) ans = j;
            }
        }
        int x = k - 1 - ans;

        fill(dp,dp+MAX,0);
        dp[0] = a[k];
        ans = 0;
        for(int i = k+1;i <= N;i++)
        {
            for(int j = N-k;j >= 1;j--)
            {
                if(dp[j-1] > a[i])
                {
                    dp[j] = max(a[i],dp[j]);
                }
                if(dp[j] != 0 && j > ans) ans = j;
            }
        }
        int y = N - k - ans;

        if(mi > x + y)
        {
            mi = x + y;
        }
    }
    cout << mi;
    return 0;
}

