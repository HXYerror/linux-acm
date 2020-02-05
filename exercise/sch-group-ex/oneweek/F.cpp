/*************************************************************************
	> File Name: F.cpp
	> Author: HXYerror
	> Mail: zx841985525@163.com 
	> Created Time: 2020年02月03日 星期一 11时35分00秒
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
        int l = str.size();
        int sum = 0;
        for(int i = 0; i < l;i++)
        {
            if(str[i] == 'C') sum += 12;
            if(str[i] == 'O') sum += 16;
            if(str[i] == 'H') sum += 1;
        }
        cout << sum <<endl;
    }
    return 0;
}

