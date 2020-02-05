/*************************************************************************
	> File Name: E.cpp
	> Author: HXYerror
	> Mail: zx841985525@163.com 
	> Created Time: 2020年02月04日 星期二 13时43分42秒
 ************************************************************************/

#include <bits/stdc++.h>
#define ll  long long
using namespace std;
const int MAX = 1000010;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;//998244353;

ll T,N,M;
/* --------------------------------------------------------------------------------------------------*/
int prime[MAX];
int visit[MAX];
int flag[MAX];
/* --------------------------------------------------------------------------------------------------*/
void Prime(int n)
{
    for(ll i = 2;i <= n;i++)
    {
        if(!visit[i])
        {
            prime[++prime[0]] = i;
            flag[i] = 1;
        }
        for(int j = 1;j <= prime[0] && i*prime[j] <= n;j++)
        {
            visit[i*prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}

int sum(ll k)
{
    map<ll,int> cnt;
    while(k != 1)
    {
        for(int i = 1;i < prime[0];i++)
        {
            while(k % prime[i] == 0)
            {
                cnt[prime[i]]++;
                k /= prime[i];
            }
            if(k == 1) break;
        }
        if(k != 1)
        {
            cnt[k]++;
            k = 1;
        }
    }
    map<ll,int>::iterator it;
    int cntx = 1;
    for(it = cnt.begin();it != cnt.end();it++)
    {
        cntx *= (it -> second + 1);
    }
    return cntx;
}
int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
	//in
	//out
/* --------------------------------------------------------------------------------------------------*/
    Prime(1000000);
    cin >> N;
    M = sum(N);
    ll ans = 0;
    ans++;
    while(M != 2)
    {
        N = M;
        M = sum(N);
        ans++;
    }
    cout << ans << endl;
    return 0;
}

