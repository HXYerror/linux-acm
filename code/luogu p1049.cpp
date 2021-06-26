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
const int MAX = 20010;
const int MAX_1 = 40;
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
    cin >> M >> N;
    for(int i = 0;i <= MAX;i++)
    {
        dp[i] = i;
    }
    for(int i =1;i <= N;i++)
    {
        cin >> a[i];
    }
    for(int j = 1;j <= N;j++)
    {
        for(int i = M;i >= 1;i--)
        {
            if(a[j] <= i)
            {
                dp[i] = min(dp[i],dp[i-a[j]]);
                //cout << i << ":" << dp[i-a[j]] << " " << dp[i] <<endl;
            }
        }
    }
    cout << dp[M] << "\n";
    return 0;
}

