/*************************************************************************
	> File Name: cf3-598-E.cpp
	> Author: HXYerror
	> Mail: zx841985525@163.com 
	> Created Time: 2019年11月06日 星期三 19时54分45秒
 ************************************************************************/

#include <bits/stdc++.h>
#define ll  long long
using namespace std;
const int MAX = 200010;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;//998244353;

ll T,N,M,K;
/* --------------------------------------------------------------------------------------------------*/
struct Pos
{
    int p;
    int v;
};
bool cmp(Pos a,Pos b)
{
    return a.v < b.v;
}
int dp[MAX];
int pre[MAX];
int ans[MAX];
vector <int> pos;
/* --------------------------------------------------------------------------------------------------*/

void find_pre(int x)
{
    pos.push_back(x);
    if(pre[x] == x) return ;
    else
    {
        find_pre(pre[x]);     
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
	//in
	//out
/* --------------------------------------------------------------------------------------------------*/
    cin >> N;               
    int x;
    vector<Pos> a;
    Pos temp;
    for(int i = 0;i < N;i++)
    {
        cin >> x;
        temp.v = x;
        temp.p = i;
        a.push_back(temp);
    }
    fill(dp,dp+N+1,INF);
    dp[0] = 0;
    pre[0] = 0;
    sort(a.begin(),a.end(),cmp);
    for(int i = 0;i < N;i++)
    {
        if(dp[i+3]  > dp[i] + a[i+2].v - a[i].v)
        {
            dp[i+3] = dp[i] + a[i+2].v - a[i].v;
            pre[i+3] = i;
        }
        if(dp[i+4]  > dp[i] + a[i+3].v - a[i].v)
        {
            dp[i+4] = dp[i] + a[i+3].v - a[i].v;
            pre[i+4] = i;
        }
        if(dp[i+5]  > dp[i] + a[i+4].v - a[i].v)
        {
            dp[i+5] = dp[i] + a[i+4].v - a[i].v;
            pre[i+5] = i;
        }
    }
    find_pre(pre[N]);
    int cnt = 1;
    int l,r;
    l = N;
    for(int i = 0;i < pos.size();i++)
    {
        r = pos[i];
        for(int j = r;j < l;j++)
        {
            ans[a[j].p] = cnt;
        }
        cnt++;
        l = r;
    }
    cout << dp[N] << " " << pos.size() << "\n";
    for(int i = 0;i < N;i++)
    {
        cout << ans[i];
        if(i < N-1) cout << " ";
        else cout << "\n";
    }

    return 0; 
}
