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
const int MAX = 10010;
const int MAX_1 = 110;
const int INF = 0xfffffff;//268435455,2e8;
const double EPS = 0.0000001;
const int MOD = 1000000007;
int T,N,M;


/*-------------------------------------------------------------------------------------------*/
int a[MAX_1];
int dp[MAX];
/* ------------------------------------------------------------------------------------------*/

int main()
{
    //std::ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 1;i <= MAX;i++)
    {
        dp[i] = INF;
    }
    dp[0] = 1;
    for(int i =1;i <= N;i++)
    {
        cin >> a[i];
    }
    //dp[a[1]] = 1;
    for(int j = 1;j <= N;j++)
    {
        for(int i = M;i >= 1;i--)
        {
            if(a[j] <= i)
            {
                if(dp[i - a[j]] != INF)
                {
                    if(dp[i] == INF)
                    {
                        dp[i] = dp[i - a[j]];
                    }
                    else dp[i] += dp[i - a[j]];

                }
            }
        }
    }
    cout << dp[M] << "\n";
    return 0;
}
//10 5
//1 2 3 4 5 1 1 2 2 3
