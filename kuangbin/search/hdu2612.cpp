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
#define ll  long long
using namespace std;
const int MAX = 210;//100000
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
struct Node
{
    int x,y;
    int time;
    Node(int xx,int yy,int tt):x(xx),y(yy),time(tt){}
};
int to[4][2] = {0,-1,0,1,1,0,-1,0};
int sx,sy,ex,ey;
/* --------------------------------------------------------------------------------------------------*/

void bfs(int time[][MAX],int flag)
{
    queue<Node> q;
    if(flag)  q.push(Node(sx,sy,0)),vis[sx][sy] = 1;
    else    q.push(Node(ex,ey,0)),vis[ex][ey] = 1;
    while(!q.empty())
    {
        Node now = q.front();
        int tempx,tempy;
        q.pop();
        if(cell[now.x][now.y] == '@')
        {
            time[now.x][now.y] = now.time;
            //continue;
        }
        for(int i = 0;i < 4;i++)
        {
            tempx = to[i][0] + now.x;
            tempy = to[i][1] + now.y;

            if(tempx >= 0 && tempy >= 0 && tempx < N && tempy < M && cell[tempx][tempy] != '#' && !vis[tempx][tempy])
            {
                q.push(Node(tempx,tempy,now.time+1));
                vis[tempx][tempy] = 1;
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* -----------------------------------------------------------------------------------------*/
    while(cin >> N >> M)
    {
        for(int i = 0;i < N;i++)
        {
            for(int j = 0;j < M;j++)
            {
                cin >> cell[i][j];
                if(cell[i][j] == 'Y') sx = i,sy = j,cell[i][j] = '.';
                if(cell[i][j] == 'M') ex = i,ey = j,cell[i][j] = '.';
            }
        }
        int timea[MAX][MAX],timeb[MAX][MAX];
        memset(timea,0,sizeof(timea));
        memset(timeb,0,sizeof(timeb));
        memset(vis,0,sizeof(vis));
        bfs(timea,1);
        memset(vis,0,sizeof(vis));
        bfs(timeb,0);
        int minans = INF;
        for(int i = 0;i < N;i++)
        {
            for(int j = 0;j < M;j++)
            {
                if(cell[i][j] == '@' && timea[i][j] && timeb[i][j] )
                {
                    minans = min(minans,timea[i][j]+timeb[i][j]);
                }
            }
        }
        cout << minans*11 <<"\n";
    }
    return 0;
}
