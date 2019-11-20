/*************************************************************************
	> File Name: hdu5949.cpp
	> Author: HXYerror
	> Mail: zx841985525@163.com 
	> Created Time: 2019年11月20日 星期三 20时08分39秒
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
    while(T--)
    {
        string str;
        cin >> str;
        int ans = 0;
        for(int i = 0;i < str.size();i++)
        {
            if(str[i] == 'C') ans += 12;
            else if(str[i] == 'H') ans += 1;
            else ans += 16;
        }
        cout << ans <<endl;
    }
    return 0;
}

