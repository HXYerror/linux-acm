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
struct YAO
{
    int t;
    int v;
}a[MAX_1];
int dp[MAX];
/* ------------------------------------------------------------------------------------------*/

int main()
{
    //std::ios::sync_with_stdio(false);
    cin >> M >> N;
    for(int i =1;i <= N;i++)
    {
        cin >> a[i].t >> a[i].v;
    }
    for(int j = 1;j <= N;j++)
    {
        for(int i = M;i >= 1;i--)
        {
            if(a[j].t <= i)
            {
                dp[i] = max(dp[i],dp[i-a[j].t]+a[j].v);
            }
        }
    }
    cout << dp[M] << "\n";
    return 0;
}
