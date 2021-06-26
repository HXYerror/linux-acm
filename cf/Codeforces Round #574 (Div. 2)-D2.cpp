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
const int MAX = 25;//100000
const int MAX_1 = 100010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;
const double PI = acos(-1);
LL T,N,M;
/*-------------------------------------------------------------------------------------------*/
LL ten[MAX];
LL len[MAX];
LL sum[MAX];
/* ------------------------------------------------------------------------------------------*/
 
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    cin >> N;
    string str;
    LL ans = 0;
    ten[1] = 1;
    for(int i = 2;i <= 24;i++)
    {
        ten[i] = (ten[i-1]*10) % MOD;
    }
    int maxl = 0;
    for(int i = 0;i < N;i++)
    {
        cin >>str;
        int l = str.size();
        maxl = max(maxl,l);
        len[l]++;
        for(int i = l-1,j = 1;i >=0;i--,j++)
        {
            sum[j] += (LL)(str[i] - '0');
        }
    }
    for(int i = maxl;i > 0 ;i--)//位数
    {
        for(int j = maxl;j > 0;j--)
        {
            if(j < i) ans += ((sum[i] * ten[j+i]) % MOD) * len[j] * 2  % MOD;
            else if(j == i || j > i)
            {
                ans += ((sum[i] * ten[2*i]) % MOD) * len[j] % MOD;
                ans += ((sum[i] * ten[2*i-1]) % MOD) * len[j] %MOD;
            }
            //cout << i <<" " << j <<" "<<ans <<endl;
        }
    }
    cout << ans % MOD<<endl;
    return 0;
}