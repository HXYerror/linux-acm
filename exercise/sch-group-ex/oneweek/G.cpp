/*************************************************************************
	> File Name: G.cpp
	> Author: HXYerror
	> Mail: zx841985525@163.com 
	> Created Time: 2020年02月03日 星期一 14时25分07秒
 ************************************************************************/

#include <bits/stdc++.h>
#define ll  long long
using namespace std;
const int MAX = 10;
const int INF = 0x3f3f3f3f;
const ll  MOD = 2147493647;//998244353;

ll T,N,M,K;
/* --------------------------------------------------------------------------------------------------*/
int MAX_1 = 7;
ll a[MAX][MAX];
ll b[MAX][MAX];
ll ax[7][7] = 
{
{0,2,0,0,0,0,0},
{1,1,0,0,0,0,0},
{0,1,1,0,0,0,0},
{0,4,4,1,0,0,0},
{0,6,6,3,1,0,0},
{0,4,4,3,2,1,0},
{0,1,1,1,1,1,1}
};
ll bx[7][7] =
{
1,0,0,0,0,0,0,
0,1,0,0,0,0,0,
0,0,1,0,0,0,0,
0,0,0,1,0,0,0,
0,0,0,0,1,0,0,
0,0,0,0,0,1,0,
0,0,0,0,0,0,1
};
/* --------------------------------------------------------------------------------------------------*/
void calculate(ll a[][MAX],ll b[][MAX])
{
    ll c[MAX][MAX];
    for(int i = 0;i < MAX_1;i++)
    {
        fill(c[i],c[i]+MAX,0);
    }
    for(int i = 0;i < MAX_1;i++)
    {
        for(int j = 0;j < MAX_1;j++)
        {
            for(int k = 0;k < MAX_1;k++)
            {
                c[i][j] += (a[i][k]*b[k][j]) % MOD;
                c[i][j] = c[i][j] % MOD;
            }
        }
    }
    for(int i = 0;i < MAX_1;i++)
    {
        for(int j = 0;j < MAX_1;j++)
        {
            a[i][j] = c[i][j];
        }
    }
}
void Qmod(int n)
{
    while(n)
    {
        if(n & 1)
        {
            calculate(b,a);
        }
        calculate(a,a);
        n >>= 1;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
	//in
	//out
/* --------------------------------------------------------------------------------------------------*/
    cin >> T;
    while(T--)
    {
        ll x,y;
        cin >> N >> x >> y;
        if(N == 1)
        {
            cout << x << endl;
            continue;
        }
        else if(N == 2)
        {
            cout << y << endl;
            continue;
        }
        else
        {
            for(int i = 0;i < 7;i++)
            {
                for(int j = 0;j < 7;j++)
                {
                    a[i][j] = ax[i][j];
                    b[i][j] = bx[i][j];
                }
            }
            Qmod(N-2);
            ll ans = 0;
            ll c[] = {x,y,16,8,4,2,1};
            for(int i = 0;i < 7;i++)
            {
                ans += c[i] * b[i][1];
                ans %= MOD;
            }
            cout << ans << endl;
        }
    }
    return 0;
}

