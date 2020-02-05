/*************************************************************************
	> File Name: J.cpp
	> Author: HXYerror
	> Mail: zx841985525@163.com 
	> Created Time: 2020年02月05日 星期三 10时24分23秒
 ************************************************************************/

#include <bits/stdc++.h>
#define ll  long long
using namespace std;
const int MAX = 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;//998244353;

ll mod = MOD - 1;
ll T,N,M,K;
/* --------------------------------------------------------------------------------------------------*/
ll e[MAX][MAX],f[MAX][MAX];
ll p[MAX][MAX],q[MAX][MAX];
/* --------------------------------------------------------------------------------------------------*/
void calculate(ll a[][MAX],ll b[][MAX],int n)
{
    ll c[MAX][MAX];
    for(int i = 0;i < MAX;i++)
    {
        fill(c[i],c[i]+MAX,0);
    }
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            for(int k = 0;k < n;k++)
            {
                c[i][j] += (a[i][k] * b[k][j]) % mod;
                c[i][j] %= mod;
            }
        }
    }
    for(int i = 0;i < n;i++)
    {
        for(int j  = 0;j < n;j++)
        {
            a[i][j] = c[i][j];
        }
    }
}


void qmod(ll n,int m)
{
    while(n)
    {
        if(n&1)
        {
            if(m == 2)
            {
                calculate(f,e,2);
            }
            else calculate(q,p,3);
        }
        if(m == 2) calculate(e,e,2);
        else calculate(p,p,3);
        n>>=1;
    }
}

ll Qmod(ll n,ll b)
{
    ll sum = 1;
    n %= MOD;
    while(b)
    {
       if(b&1) 
       {
           sum *= n;
           sum %= MOD;
       }
       n *= n;
       n %= MOD;
       b >>= 1;
    }
    return sum;
}


int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
	//in
	//out
/* --------------------------------------------------------------------------------------------------*/
    ll x,y,a,b;
    cin >> N >> x >> y >> a >> b;
    if(N == 1) 
    {
        cout << x%MOD << endl;
        return 0;
    }
    if(N == 2) 
    {
        cout << y % MOD << endl;
        return 0;
    }
    if(x % MOD == 0 || y % MOD == 0 || a % MOD == 0) 
    {
        cout << 0 << endl;
        return 0;
    }
    ll k = Qmod(a%MOD,b);
    ll p1,p2,p3;
    //f1,f2;1,0;0,1
    e[0][0] = 0,e[0][1] = 1,e[1][0] = 1,e[1][1] = 1;
    f[0][0] = 1,f[0][1] = 0,f[1][0] = 0,f[1][1] = 1;
    qmod(N-2,2);
    p1 = Qmod(x,f[0][1]);
    p2 = Qmod(y,f[1][1]);
    //f1,f2,a^b;0,0,1
    p[0][0] = 0,p[0][1]=1,p[0][2]=0;
    p[1][0] = 1,p[1][1]=1,p[1][2]=0;
    p[2][0] = 0,p[2][1]=1,p[2][2]=1;
    q[0][0] = 1,q[0][1]=0,q[0][2]=0;
    q[1][0] = 0,q[1][1]=1,q[1][2]=0;
    q[2][0] = 0,q[2][1]=0,q[2][2]=1;
    qmod(N-2,3);
    p3 = Qmod(k,q[2][1]);
    ll ans = 0;
    ans = ((p1 * p2) % MOD) * p3 % MOD;
    cout << ans << endl;
    return 0;
}

