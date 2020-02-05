*************************************************************************
	> File Name: B.cpp
	> Author: HXYerror
	> Mail: zx841985525@163.com 
	> Created Time: 2020年02月03日 星期一 10时22分04秒
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
    //unsigned ll x;
    //x = 1;
    //for(int i = 0;i < 63;i++)
    //{
        //x *= 2;
    //}
    //cout << x-1+x <<endl;
    cin >> T;
    string str = "18446744073709551616";
    while(T--)
    {
        unsigned ll a,b,c,d;
        cin >> a >> b >> c >> d;
        if(a+b+c+d || !a) cout << a+b+c+d << endl;
        else cout << str << endl;
    }
    return 0;
}

