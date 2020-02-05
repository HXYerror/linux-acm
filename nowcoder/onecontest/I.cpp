/*************************************************************************
	> File Name: I.cpp
	> Author: HXYerror
	> Mail: zx841985525@163.com 
	> Created Time: 2020年02月05日 星期三 14时28分12秒
 ************************************************************************/

#include <bits/stdc++.h>
#define ll  long long
using namespace std;
const int MAX = 300010;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;//998244353;

ll T,N,M,K;
/* --------------------------------------------------------------------------------------------------*/
vector<char> ch;
ll dp[MAX];
/* --------------------------------------------------------------------------------------------------*/

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
	//in
	//out
/* --------------------------------------------------------------------------------------------------*/
    string str;
    ll a,b,c;
    cin >> N >> a >> b >> c;
    getline(cin,str);
    getline(cin,str);
    for(int i = 1;i < N;i+=2)
    {
        if(str[i] == 'i' && str[i-1] == 'n') ch.push_back('a');
        if(str[i] == 'o' && str[i-1] == 'c') ch.push_back('b');
    }
    int l = ch.size();
    for(int i = 1;i <= l;i++)
    {
        int j = i-1;
        if(ch[j] == 'b')
        {
            dp[i] = dp[i-1];
            if(j  > 0) 
            {
                if(ch[j-1] == 'a') dp[i] = max(dp[i-2]+a,dp[i]);
            }
        }
        if(ch[j] == 'a')
        {
            dp[i] = dp[i-1];
            if(j > 1)
            {
                if(ch[j-1] == 'b' && ch[j-2] == 'a') 
                {
                    dp[i] = max(dp[i-3]+b,dp[i]);
                    if(j > 3)
                        if(ch[j-3] == 'b' && ch[j - 4] == 'a')
                            dp[i] = max(dp[i-5]+c,dp[i]);
                }
            }
        }
    }
    cout << dp[l] <<endl;

    return 0;
}

