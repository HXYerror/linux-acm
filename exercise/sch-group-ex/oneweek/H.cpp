/*************************************************************************
	> File Name: H.cpp
	> Author: HXYerror
	> Mail: zx841985525@163.com 
	> Created Time: 2020年02月04日 星期二 10时08分02秒
 ************************************************************************/

#include <bits/stdc++.h>
#define ll  long long
using namespace std;
const int MAX = 110;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;//998244353;

ll T,N,M,K;
/* --------------------------------------------------------------------------------------------------*/
int edge[MAX][MAX];
vector<int>G[MAX];
int ans = 0;
int temp[MAX];
/* --------------------------------------------------------------------------------------------------*/
void dfs(int deep,int x)
{
    if(deep == K)
    {
        ans++;
        return;
    }
    if(N - x < K - deep)
    {
        return;
    }
    for(int i =0;i < G[x].size();i++)
    {
        int flag = 1;
        int next = G[x][i];
        for(int j = 0;j < deep;j++)
        {
            if(edge[next][temp[j]]==0)
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            temp[deep] = G[x][i];
            dfs(deep+1,temp[deep]);
        }
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
    cin >> T;
    while(T--)
    {
        cin >> N >> M >> K;
        for(int i = 0;i < M;i++)
        {
            int x,y;
            cin >> x >> y;
            if(x > y) swap(x,y);
            G[x].push_back(y);
            edge[x][y] = edge[y][x] = 1;
        }
        ans = 0;
        fill(temp,temp+MAX,0);
        for(int i = 1;i <= N;i++)
        {
            temp[0] = i;
            dfs(1,i);
        }
        for(int i = 0;i <= N;i++)
        {
            G[i].clear();
            fill(edge[i],edge[i]+MAX,0);
        }
        cout << ans << endl;
    }
    return 0;
}

