//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#define ll long long
using namespace std;
const int MAX = 40;//100000
const int MAX_1 = 100010;
const int MAX_2 = 1000010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;//998244353;
const double PI = acos(-1);
//void runtime(){cout << "The run time is:" << (double)clock() /CLOCKS_PER_SEC<< "s" << endl;}
ll T,N,M,K;
/*---------------------------------------------------------------------------------------------------*/
struct Pos
{
    int x,y,z;
    int deep;
};
char g[MAX][MAX][MAX];
int vis[MAX][MAX][MAX];
int ans;
Pos to[6] = {{0,0,1,0},{0,0,-1,0},{1,0,0,0},{-1,0,0,0},{0,1,0,0},{0,-1,0,0}};
/* --------------------------------------------------------------------------------------------------*/

void read(int h,int n,int m,Pos &s)
{
    for(int i = 0;i < h;i++)
    {
        for(int j = 0;j < n;j++)
        {
            for(int k = 0;k < m;k++)
            {
                vis[i][j][k] = 0;
                cin >> g[i][j][k];
                if(g[i][j][k] == 'S')
                {
                    s.z = i;
                    s.x = j;
                    s.y = k;
                    s.deep = 0;
                }
            }
        }
    }
}

void mycout(int flag)
{
    if(flag) cout << "Escaped in " << ans << " minute(s)."<<endl;
    else cout << "Trapped!" <<endl;
}

bool bfs(Pos s)
{
    queue<Pos> q;
    q.push(s);
    vis[s.z][s.x][s.y] = 1;
    while(!q.empty())
    {
        Pos temp,now;
        now = q.front();
        if(g[now.z][now.x][now.y] == 'E')
        {
            ans = now.deep;
            return true;
        }
        for(int i = 0;i < 6;i++)
        {
            temp.x = now.x + to[i].x;
            temp.y = now.y + to[i].y;
            temp.z = now.z + to[i].z;
            temp.deep = now.deep + 1;
            if((temp.x >= 0 && temp.x < N) && (temp.y >= 0 && temp.y < M) && (temp.z >= 0 && temp.z < K)
               && g[temp.z][temp.x][temp.y] != '#' && !vis[temp.z][temp.x][temp.y])
            {
                q.push(temp);
                vis[temp.z][temp.x][temp.y] = 1;
            }
        }
        q.pop();
    }
    return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* -----------------------------------------------------------------------------------------*/
    while(cin >> K >> N >> M)
    {
        if(!K && !N && !M) break;
        Pos s;
        read(K,N,M,s);
        mycout(bfs(s));
    }
    return 0;
}



