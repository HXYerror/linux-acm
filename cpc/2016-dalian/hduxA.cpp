/*************************************************************************
	> File Name: hduxA.cpp
	> Author: HXYerror
	> Mail: zx841985525@163.com 
	> Created Time: 2019年11月22日 星期五 16时41分33秒
 ************************************************************************/

#include <bits/stdc++.h>
#define ll  long long
using namespace std;
const int MAX = 100010;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;//998244353;

ll T,N,M,K;
/* --------------------------------------------------------------------------------------------------*/

/* --------------------------------------------------------------------------------------------------*/
ll gcd(ll a,ll b)
{
    return a % b == 0  ? b : gcd(b,a%b);
}
int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
	//in
	//out
/* --------------------------------------------------------------------------------------------------*/
    while(cin >> N >> M)
    {
        int flag = 0;
        ll x,y;
        for(int i = 1;i < N;i++)
        {
            ll g = gcd(i,N-i);
            ll l = ((N-i) * i) / g;
            if(l == M)
            {
                flag = 1;
                x = i;
                y = N-i;
                break;
            }
        }
        if(flag) cout << x << " " << y << "\n";
        else cout <<"No Solution" << "\n"; 
    }
    return 0;
}

