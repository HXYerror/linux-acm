/*************************************************************************
	> File Name: H.cpp
	> Author: HXYerror
	> Mail: zx841985525@163.com 
	> Created Time: 2020年02月03日 星期一 17时37分11秒
 ************************************************************************/

#include <bits/stdc++.h>
#define ll  long long
using namespace std;
const int MAX = 100010;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;//998244353;
const int MAX_1 = 110;
ll T,N,M,K;
/* --------------------------------------------------------------------------------------------------*/
int edge[MAX_1][MAX_1];
int temp[25];
int ans = 0;
/* --------------------------------------------------------------------------------------------------*/
void dfs(int deep,int x)
{
    if(deep == K+1) 
    {
        ans ++;
        return;
    }
    for(int i = x;i <= N;i++)
    {
        if(N - x + 1 < K - deep + 1) return;
        int flag = 1;
        for(int j = 1;j < deep;j++)
        {
            if(edge[temp[j]][i] == 0)
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            temp[deep] = i;
            dfs(deep+1,i+1);
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
        for(int i = 0;i < MAX_1;i++) fill(edge[i],edge[i]+MAX_1,0);
        int flag[MAX_1];
        fill(flag,flag+MAX_1,0);
        for(int i = 0;i < M;i++)
        {
            int x,y;
            cin >> x >> y;
            flag[x]++;
            flag[y]++;
            edge[x][y] = 1;
            edge[y][x] = 1;
        }
        for(int i = 1;i <= N;i++)
        {
            if(flag[i] < K-1)
            {
                for(int j = 0;j <= N;j++)
                {
                    edge[i][j] = 0;
                    edge[j][i] = 0;
                }
            }
        }
        ans = 0;
        dfs(1,1);
        cout << ans << endl;
    }
    return 0;
}

