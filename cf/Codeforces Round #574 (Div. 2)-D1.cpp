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
const int MAX_1 = 2010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;
const double PI = acos(-1);
LL T,N,M;
/*-------------------------------------------------------------------------------------------*/
LL ten[MAX];
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
    cin >> str;
    int l = str.size();
    LL ans = 0;
    ten[1] = 1;
    for(int i = 2;i <= 24;i++)
    {
        ten[i] = (ten[i-1]*10) % MOD;
    }
    for(int i = 0;i < l;i++)
    {
        ans += (((LL)(str[i] - '0') * ten[2*l-2*i]) % MOD)*N %MOD;
        ans += (((LL)(str[i] - '0') * ten[2*l-2*i-1]) % MOD)*N %MOD;
    }
    for(int i = 1;i < N;i++)
    {
        cin >>str;
        for(int i = 0;i < l;i++)
        {
            ans += (((LL)(str[i] - '0') * ten[2*l-2*i]) % MOD) * N %MOD;
            ans += (((LL)(str[i] - '0') * ten[2*l-2*i-1]) % MOD) * N %MOD;
        }
    }
    cout << ans % MOD<<endl;
    return 0;
}