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
const int MAX = 3210;
const int MAX_1 = 100;
const int INF = 0xfffffff;//268435455,2e8;
const double EPS = 0.0000001;
const int MOD = 1000000007;
int T,N,M;


/*-------------------------------------------------------------------------------------------*/
struct YAO
{
    int m;
    int v;
    YAO(int mm,int vv) : m(mm),v(vv){}
};
vector<vector<YAO> > a(MAX_1);
int dp[MAX];
/* ------------------------------------------------------------------------------------------*/

int main()
{
    //std::ios::sync_with_stdio(false);
    cin >> M >> N;
    M /= 10;
    for(int i =1;i <= N;i++)
    {
        int x,y,z;
        cin >>x >>y>>z;
        if(z == 0)
        {
            a[i].push_back(YAO(x/10,y));
        }
        else
        {
            a[z].push_back(YAO(x/10,y));
        }
    }

    for(int i = 1;i <= N;i++)
    {
        if(a[i].size() == 0) continue;
        for(int j = M;j >= 1;j--)
        {
            if(j >= a[i][0].m)
            {
                dp[j] = max(dp[j],dp[j - a[i][0].m]+a[i][0].m*a[i][0].v);
            }
            if(a[i].size() > 1)
            {
                if(j >= a[i][0].m + a[i][1].m)
                {
                    dp[j] = max(dp[j],dp[j - a[i][0].m - a[i][1].m]+a[i][0].m*a[i][0].v+a[i][1].m*a[i][1].v);
                }
                if(a[i].size() > 2)
                {
                    if(j >= a[i][0].m + a[i][2].m)
                    {
                        dp[j] = max(dp[j],dp[j - a[i][0].m - a[i][2].m]+a[i][0].m*a[i][0].v+a[i][2].m*a[i][2].v);
                    }
                    if(j >= a[i][0].m + a[i][1].m +a[i][2].m)
                    {
                        dp[j] = max(dp[j],dp[j - a[i][0].m - a[i][1].m - a[i][2].m]+a[i][0].m*a[i][0].v+a[i][2].m*a[i][2].v + a[i][1].m*a[i][1].v);
                    }
                }
            }
        }
    }
    cout << dp[M]*10 << "\n";
    return 0;
}

