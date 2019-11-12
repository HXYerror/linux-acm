/*************************************************************************
	> File Name: hdu6225.cpp
	> Author: HXYerror
	> Mail: zx841985525@163.com 
	> Created Time: 2019年11月12日 星期二 20时08分09秒
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
    cin >> T;
    unsigned long long sum,add;
    sum = 1;
    for(int i = 0;i < 63;i++)
    {
        sum *= 2;
    }
    add = sum -1;
    add += sum;
    sum /= 2;
    while(T--)
    {
        unsigned long long ans,a,b,c,d;
        cin >> a >> b >> c >> d;
        if(a == sum && b == sum && c == sum && d == sum) 
        {
            cout << add / 10 << 6 << endl;
            continue;
        }
        ans = a + b + c + d;
        cout << ans <<"\n";
    }
    return 0;
}
