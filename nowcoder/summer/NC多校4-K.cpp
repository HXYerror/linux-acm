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
const int MAX = 100010;//100000
const int MAX_1 = 100010;
const int INF = 100000;//0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;//998244353;
const double PI = acos(-1);
LL T,N,M;
/*-------------------------------------------------------------------------------------------*/
 
/* ------------------------------------------------------------------------------------------*/
 
LL add(LL n)
{
    return (n * (n + 1)) / 2;
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    string str;
    cin >> str;
    N = str.size();
    LL dp[3];
    dp[0] = dp[1] = dp[2] = 0;
    LL ans = 0;
    int last = 0;
    int cnt = 0;
    if(str[0] == '0')
    {
        cnt++;
        ans++;
    }
    last = 0;
    for(int i = 1;i < N;i++)
    {
        if((str[i] - '0') % 3 == 1)
        {
            int k = dp[0];
            dp[0] = dp[2];
            dp[2] = dp[1];
            dp[1] = k;
        }
        else if((str[i] - '0') % 3 == 2)
        {
            int k = dp[0];
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = k;
        }
        int n = str[i] + str[last] - '0' - '0';
        dp[n % 3] ++;
        if(str[i] == '0')
        {
            cnt++;
            ans++;
        }
        else cnt = 0;
        if(cnt > 1)
        {
            ans += dp[0];
        }
        last = i;
    }
    cout << ans <<endl;
    return 0;
}