/*************************************************************************
	> File Name: cf2-592-C.cpp
	> Author: HXYerror
	> Mail: zx841985525@163.com 
	> Created Time: 2019年11月05日 星期二 17时46分28秒
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

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
	//in
	//out
/* --------------------------------------------------------------------------------------------------*/
    ll n,p,m,d;
    cin >> n >> p >> m >> d;
    ll ansx,ansy;
    int i;
    for(i = 0;i < m;i++)
    {
        ll  temp =p - i * d;
        if(temp >= 0 && temp % m == 0)
        {
            ansx = temp / m;
            if(ansx + i <= n)
            {
                ansy = i;
                break;
            }
        }
    }
    if(i != m) cout << ansx << " " << ansy << " " << n - ansx - ansy << endl;
    else cout << "-1" <<endl;

    return 0;
}

