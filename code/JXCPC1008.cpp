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
const int MAX = 1000100;//100000
const int MAX_1 = 100010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 1e9+7;//998244353;
const double PI = acos(-1);
LL T,N,M;
/*-------------------------------------------------------------------------------------------*/

/* ------------------------------------------------------------------------------------------*/

LL MODE(LL a,LL b ,LL mod)
{
    LL sum = 1;
    a %= mod;
    while(b)
    {
        if(b&1) sum = (sum*a) % mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return sum;
}


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/

    while(cin >> N)
    {
        cout << ( ((N + 1) % MOD) * MODE(2*N,MOD-2,MOD)) % MOD <<endl;
    }
    return 0;
}