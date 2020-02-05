/*************************************************************************
	> File Name: H.cpp
	> Author: HXYerror
	> Mail: zx841985525@163.com 
	> Created Time: 2020年02月04日 星期二 16时24分03秒
 ************************************************************************/

#include <bits/stdc++.h>
#define ll  long long
using namespace std;
const int MAX = 100010;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;//998244353;

ll T,N,M,K;
/* --------------------------------------------------------------------------------------------------*/
vector<int> a1;
vector<int> a0;
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
    cin >> N >> M;
    cin >> str;
    for(int i = 0;i < N;i++)
    {
        if(str[i] == '0') a0.push_back(i);
        else a1.push_back(i);
    }
    int ans = 0;
    if(a0.size() <= M || a1.size() <= M) ans = N;
    for(int i = 0;i < a0.size();i++)
    {
        int l,r;
        if(i == 0) l = 0;
        else l = a0[i-1];

        if(i+M >= a0.size()) r = N;
        else r = a0[i+M];
        ans = max(ans,r-l-1);
    }
    for(int i = 0;i < a1.size();i++)
    {
        int l,r;
        if(i == 0) l = 0;
        else l = a1[i-1];

        if(i+M >= a1.size()) r = N;
        else r = a1[i+M];
        ans = max(ans,r-l-1);
    }
    cout << ans << endl;
    return 0;
}

