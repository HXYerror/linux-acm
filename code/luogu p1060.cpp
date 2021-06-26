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
const int MAX = 30010;
const int INF = -0xfffffff;//268435455,2e8;
const double EPS = 0.0000001;
const int MOD = 1000000007;
int T,N,M;


/*-------------------------------------------------------------------------------------------*/
struct BAG
{
    int m;
    int v;
}th[25];
int dp[25][MAX];
/* ------------------------------------------------------------------------------------------*/

int main()
{
    //std::ios::sync_with_stdio(false);
    cin >> M >> N;
    for(int i =1;i <= N;i++)
    {
        cin >> th[i].m >> th[i].v;
    }
    for(int j = 1;j <= N;j++)
    {
        for(int i = 1;i <= M;i++)
        {
            if(th[j].m <= i)
            {
                dp[j][i] = max(dp[j-1][i],dp[j-1][i - th[j].m]+th[j].m*th[j].v);
            }
            else
            {
                dp[j][i] = dp[j-1][i];
            }
        }
    }
    cout << dp[N][M] << "\n";
    return 0;
}

