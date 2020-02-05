/*************************************************************************
    > File Name: F.cpp
    > Author: HXYerror
    > Mail: zx841985525@163.com
    > Created Time: 2020年02月04日 星期二 17时03分58秒
 ************************************************************************/
 
#include <bits/stdc++.h>
#define ll  long long
using namespace std;
const int MAX = 100100;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;//998244353;
 
ll T,N,M,K;
/* --------------------------------------------------------------------------------------------------*/
vector<int> t[MAX];
int flag[MAX];
vector<int> temp;
int cnt[MAX];
int a[MAX];
ll ANS;
/* --------------------------------------------------------------------------------------------------*/
int dfs(int n,int fa)
{
    int cmt = 0;
    vector<int> ans;
    int f = 0;
    for(int i = 0;i < t[n].size();i++)
    {
        int next = t[n][i];
        if(next == fa) continue;
        if(flag[next])
        {
            f = 1;
            continue;
        }
        if(cnt[next])
        {
            ans.push_back(cnt[next]);
            cmt += cnt[next];
            continue;
        }
 
        int m = dfs(next,n);
        cmt += m;
        ans.push_back(m);
        if(n == M)
        {
            for(int i =0;i < temp.size();i++)
            {
                cnt[temp[i]] = m;
            }
            temp.clear();
        }
    }
    if(f) temp.push_back(n);
    if(n == M)
    {
        ll sum = 0;
        if(ans.size() > 0)  a[0] = ans[0];
        for(int i = 1;i < ans.size();i++)
        {
            a[i] = a[i-1] + ans[i];
        }
        int m = ans.size();
        for(int i = 0;i < ans.size();i++)
        {
            sum += (a[m-1] - a[i]) * ans[i];
        }
        ANS += sum;
        ANS += cmt;
    }
    return cmt+1;
 
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
    string str;
    cin >> str;
    int x,y;
    for(int i = 0;i < N- 1;i++)
    {
        cin >> x >> y;
        t[x].push_back(y);
        t[y].push_back(x);
    }
    for(int i = 0;i < N;i++)
    {
        if(str[i] == 'B') flag[i+1] = 1;
    }
    for(int i = 0;i < N;i++)
    {
        if(str[i] == 'B')
        {
            M = i+1;
            dfs(i+1,-1);
        }
    }
    cout << ANS <<endl;
 
    return 0;
}
