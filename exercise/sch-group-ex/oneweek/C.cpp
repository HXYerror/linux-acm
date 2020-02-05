/*************************************************************************
	> File Name: C.cpp
	> Author: HXYerror
	> Mail: zx841985525@163.com 
	> Created Time: 2020年02月03日 星期一 11时21分27秒
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
        cin >> N;
        int x,y;
        int sum = 0;
        int a,b;
        for(int i = 1;i <= N;i++)
        {
            cin >> x;
            if(i == 1)
            {
                y = x;
                continue;
            }
            sum += x - y - 1;
            if(i == 2) a = x - y -1;
            if(i == N) b = x - y - 1;
            y = x;
        }
        cout << sum - min(a,b) << endl;
    }
    return 0;
}

