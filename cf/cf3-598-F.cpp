/*************************************************************************
	> File Name: cf3-598-F.cpp
	> Author: HXYerror
	> Mail: zx841985525@163.com 
	> Created Time: 2019年11月07日 星期四 21时41分02秒
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
    //如果是字母数量不相同就不行
    //如果是有一个字母重复那必然可以，俩个俩个交换
    //如果是没有相同的字母，那么字符串长度不会超过26,就需要判断逆序数（这里还需要再看）
    cin >> T;
    while(T--)
    {
        cin >> N;
        string s,t;
        cin >> s >> t;
        int a[30],b[30];
        fill(a,a+30,0);
        fill(b,b+30,0);
        for(int i = 0;i < N;i++)
        {
            a[(int)(s[i] - 'a')]++;
            b[(int)(t[i] - 'a')]++;
        }
        bool flag = 1;
        bool good = 0;
        for(int i = 0;i < 26;i++)
        {
            if(a[i] != b[i]) 
            {
                flag = 0;
                break;
            }
            if(a[i] > 1) good = 1;
        }
        if(!flag)
        {
            cout << "NO" << "\n";
            continue;
        }
        if(good)
        {
            cout << "YES" << "\n";
            continue;
        }
        int cnt1,cnt2;
        cnt1 = cnt2 = 0;
        for(int i = 0;i < N;i++)
        {
            for(int j = i+1;j < N;j++)
            {
                if(s[i] > s[j]) cnt1++;
                if(t[i] > t[j]) cnt2++;
            }
        }
        if(cnt1 % 2 == cnt2 % 2)
        {
            cout << "YES" << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}

