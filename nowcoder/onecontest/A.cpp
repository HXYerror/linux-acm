/*************************************************************************
	> File Name: A.cpp
	> Author: HXYerror
	> Mail: zx841985525@163.com 
	> Created Time: 2020年02月04日 星期二 14时26分04秒
 ************************************************************************/

#include <bits/stdc++.h>
#define ll  long long
using namespace std;
const int MAX = 100010;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;//998244353;

ll T,N,M,K;
/* --------------------------------------------------------------------------------------------------*/

/* --------------------------------------------------------------------------------------------------*/

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
	//in
	//out
/* --------------------------------------------------------------------------------------------------*/
    cin >> N >> M;
    ll ans = 0;
    ans += ((((N - 2) * N ) % MOD) * (M - 1) ) % MOD;
    ans += ((((M - 2) * M ) % MOD) * (N - 1) ) % MOD;
    ans += ((((M - 1) * M ) % MOD) * (N - 2) ) % MOD;
    ans += ((((N - 1) * N ) % MOD) * (M - 2) ) % MOD;
    ans *= 2;
    ans %= MOD;

    ll x = 0;
    for(int i = 1;i <= 2;i++)
    {
        for(int j = 1;j <= 2;j++)
        {
            if(i - 2 >= 1)
            {
                if(j - 1 >= 1) x++;
                if(j + 1 <= M) x++;
            }
            if(i + 2 <= N)
            {
                if(j - 1 >= 1) x++;
                if(j + 1 <= M) x++;
            }
            if(j - 2 >= 1)
            {
                if(i - 1 >= 1) x++;
                if(i + 1 <= N) x++;
            }
            if(j + 2 <= M)
            {
                if(i - 1 >= 1) x++;
                if(i + 1 <= N) x++;
            }
        }
    }   
    x *= 4;
    x %= MOD;
    ll y = 10;
    if(N >= 5) x += (y * (N - 4)) * 2 % MOD;
    x %= MOD;
    if(M >= 5) x += (y * (M - 4)) * 2 % MOD;
    ll cnt = N*M - 4*M - (N - 4) * 4;
    cnt %= MOD;
    x = (x + cnt * 8) % MOD;

    if(N <= 4 || M <= 4)
    {
    x = 0;
    for(int i = 1;i <= N;i++)
    {
        for(int j = 1;j <= M;j++)
        {
            if(i - 2 >= 1)
            {
                if(j - 1 >= 1) x++;
                if(j + 1 <= M) x++;
            }
            if(i + 2 <= N)
            {
                if(j - 1 >= 1) x++;
                if(j + 1 <= M) x++;
            }
            if(j - 2 >= 1)
            {
                if(i - 1 >= 1) x++;
                if(i + 1 <= N) x++;
            }
            if(j + 2 <= M)
            {
                if(i - 1 >= 1) x++;
                if(i + 1 <= N) x++;
            }
        }
    }   

    }
    
    ans -= x;
    if(ans < 0) cout << ans + MOD << endl;
    else cout << ans << endl;
    return 0;
}

