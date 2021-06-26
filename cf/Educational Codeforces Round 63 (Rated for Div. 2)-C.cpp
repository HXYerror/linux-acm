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
const int MAX = 300010;
const int MAX_1 = 100;
const int INF = 0xfffffff;//268435455,2e8;
const double EPS = 0.0000001;
const int MOD = 1000000007;
int T,N,M;

/*-------------------------------------------------------------------------------------------*/
LL x[MAX];
LL k[MAX];
LL p[MAX];
/* ------------------------------------------------------------------------------------------*/

LL gcd(LL a,LL b)
{
    return a % b == 0? b : gcd(b,a%b);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
/* --------------------------------------------------------------------------------------*/
    cin >> N >>M;
    int f = 0;
    for(int i = 1;i <= N;i++)
    {
        cin >> x[i];
        k[i] = x[i]-x[i-1];
    }
    LL m;
    if(N > 2)
    {
        m = gcd(k[2],k[3]);
    }
    else m = k[2];
    for(int i= 4;i <= N;i++)
    {
       m = gcd(k[i],m);
    }

    LL ans = 0;
    for(int i = 1;i <= M;i++)
    {
        cin >> p[i];
    }
    int j;
    for(j = 1;j <= M;j++)
    {
        if(m % p[j]  == 0)
        {
            ans = j;
            f = 1;
            break;
        }
    }
    if(j == M+1) f= 0;

    if(f)
    {
        cout <<"YES" <<"\n" ;
        cout << x[1] <<" " << ans;
    }
    else cout << "NO";
    return 0;
}

