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
const int MAX = 100010;//100000
const int MAX_1 = 2010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;
const double PI = acos(-1);
LL T,N,M;
/*-------------------------------------------------------------------------------------------*/
LL a[MAX];
LL b[MAX];
LL sum[2][MAX];
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
    for(int i = 0;i < N;i++)
    {
        cin >> a[i];
    }
    for(int i = 0;i < N;i++)
    {
        cin >> b[i];
    }
    LL s[2];
    s[0] = a[0];
    s[1] = b[0];
    for(int i = 1;i < N;i++)
    {
        LL u,d;
        u = s[0];
        d = s[1];
        s[0] = max(d+a[i],u - a[i-1]+a[i]);
        s[1] = max(u+b[i],d - b[i-1]+b[i]);
    }
    cout << max(s[0],s[1]);
    return 0;
}