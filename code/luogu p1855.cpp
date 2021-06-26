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
const int MAX = 210;
const int MAX_1 = 1000010;
const int INF = 0xfffffff;//268435455,2e8;
const double EPS = 0.0000001;
const int MOD = 10000007;
int T,N,M;


/*-------------------------------------------------------------------------------------------*/
int dp[MAX][MAX];
struct Timemoney
{
    int m,t;
}dream[MAX];
/* ------------------------------------------------------------------------------------------*/


int main()
{
    //std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    cin >> N >> M >> T;
    for(int i = 0;i < N;i++)
    {
        cin >>dream[i].m >> dream[i].t;
    }
    for(int i = 0;i < N;i++)
    {
        for(int j = M;j >= 1;j--)
        {
            for(int k = T;k >= 1;k--)
            {
                if(j >= dream[i].m && k >= dream[i].t)
                {
                    dp[j][k] = max(dp[j][k],dp[j-dream[i].m][k - dream[i].t]+1);
                }
                else dp[j][k] = max(dp[j][k],max(dp[j-1][k],dp[j][k-1]));
            }
        }
    }
    cout << dp[M][T] <<"\n";
}

