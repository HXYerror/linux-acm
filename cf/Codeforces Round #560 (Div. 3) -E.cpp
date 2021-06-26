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
const int MAX = 2000010;
const int MAX_1 = 1000100;
const int INF = 0x3f3f3f3f;//1061109567,1e9;
const double EPS = 0.0000001;
const int MOD = 998244353;
int T,N,M;


/*-------------------------------------------------------------------------------------------*/

int a[MAX];
int b[MAX];
/* ------------------------------------------------------------------------------------------*/



int main()
{
    //std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    cin >> N;
    for(int i = 0;i < N;i++)
    {
        cin >> a[i];
        a[i] = ( a[i]*(N-i)*(i+1) )% MOD;
    }
    for(int i = 0;i < N;i++)
    {
        cin >> b[i];
    }
    sort(a,a+N);
    sort(b,b+N,greater<int>());
    LL ans = 0;
    for(int i =0;i < N;i++)
    {
        ans +=(((LL)a[i]*b[i]) % MOD) % MOD;
        ans %= MOD;
    }
    cout << ans <<endl;
    return 0;
}
