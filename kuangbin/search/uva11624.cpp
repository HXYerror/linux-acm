#include <bits/stdc++.h>
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
#define ll  long long
using namespace std;
const int MAX = 1010;//100000
const int MAX_1 = 1000100;
const int MAX_2 = 1000010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;//998244353;
const double PI = acos(-1);
//void runtime(){cout << "The run time is:" << (double)clock() /CLOCKS_PER_SEC<< "s" << endl;}
ll T,N,M,K;

/* --------------------------------------------------------------------------------------------------*/
char cell[MAX][MAX];
int vis[MAX][MAX];
int ddl[MAX][MAX];
struct Node
{
    int x,y;
    int time;
    int flag;//1fire 0people
    Node(int xx,int yy,int tt,int ff):x(xx),y(yy),time(tt),flag(ff){}
};
int to[4][2] = {0,-1,0,1,1,0,-1,0};
int px,py;
/* --------------------------------------------------------------------------------------------------*/

int bfs()
{
    queue<Node> q;
    for(int i = 0;i < N;i++)
    {
        for(int j = 0;j < M;j++)
        {
            if(cell[i][j] == 'F')
            {
                cell[i][j] = '#';
                q.push(Node(i,j,0,1));
                vis[i][j] = 1;
            }
            if(cell[i][j] == 'J') px = i,py = j,cell[i][j] = '.';
        }
    }
    q.push(Node(px,py,0,0));
    vis[px][py] = 1;
    while(!q.empty())
    {
        Node now = q.front();
        int tempx,tempy;
        q.pop();
        if(now.flag == 0 && (ddl[now.x][now.y] > now.time || ddl[now.x][now.y] == 0) && (now.x == 0 || now.y == 0 ||now.x == N-1 || now.y == M-1))
        {
            return now.time+1;
        }
        for(int i = 0;i < 4;i++)
        {
            tempx = to[i][0] + now.x;
            tempy = to[i][1] + now.y;

            if(tempx >= 0 && tempy >= 0 && tempx < N && tempy < M && cell[tempx][tempy] == '.' && !vis[tempx][tempy])
            {
                if(now.flag) ddl[tempx][tempy] = now.time+1,cell[tempx][tempy] = '#';
                q.push(Node(tempx,tempy,now.time+1,now.flag));
                vis[tempx][tempy] = 1;
            }
        }
    }
    return -1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* -----------------------------------------------------------------------------------------*/
    cin >> T;
    while(T--)
    {
        memset(vis,0,sizeof(vis));
        memset(ddl,0,sizeof(ddl));
        cin >> N >> M;
        for(int i = 0;i < N;i++)
        {
            cin >> cell[i];
        }
        int n = bfs();
        if(n == -1) cout << "IMPOSSIBLE" <<"\n";
        else cout << n << "\n";
    }
    return 0;
}
