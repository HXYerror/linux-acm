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
int cell[MAX][MAX];
int vis[MAX][MAX];
struct Node
{
    int x,y;
    int cnt;
    Node(int xx,int yy,int tt):x(xx),y(yy),cnt(tt){}
};
struct Pos
{
    int x,y;
    Pos(int xx,int yy):x(xx),y(yy){}
};
struct Pre
{
    int f;
    int x,y;
}pre[MAX*MAX];
int to[4][2] = {0,-1,0,1,1,0,-1,0};
vector<Pos> ans;
/* --------------------------------------------------------------------------------------------------*/

int bfs()
{
    queue<Node> q;
    int cnt = 0;
    q.push(Node(0,0,++cnt));
    pre[cnt].f = 0;
    pre[cnt].x = pre[cnt].y = 0;
    vis[0][0] = 1;
    while(!q.empty())
    {
        Node now = q.front();
//cout << now.x << " " <<now.y << " " << now.cnt <<endl;
        int tempx,tempy;
        q.pop();
        if(now.x == N-1 && now.y == M-1)
        {
            return now.cnt;
        }
        for(int i = 0;i < 4;i++)
        {
            tempx = to[i][0] + now.x;
            tempy = to[i][1] + now.y;
            if(tempx >= 0 && tempy >= 0 && tempx < N && tempy < M && cell[tempx][tempy] == 0 && !vis[tempx][tempy])
            {
                q.push(Node(tempx,tempy,++cnt));
                pre[cnt].f = now.cnt;
                pre[cnt].x = tempx;
                pre[cnt].y = tempy;
                vis[tempx][tempy] = 1;
            }
        }
    }
    return -1;
}

void find_pre(int x)
{
    if(pre[x].f == x) return;
    else
    {
        ans.push_back(Pos(pre[x].x,pre[x].y));
        find_pre(pre[x].f);
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
    N = M = 5;
    for(int i = 0;i < N;i++)
    {
        for(int j = 0;j < M;j++)
        {
            cin >> cell[i][j];
        }
    }
    pre[0].f = 0;
    int n = bfs();
    find_pre(n);
    for(int i = ans.size()-1;i >=0;i--)
    {
        cout << "(" << ans[i].x << ", " << ans[i].y << ")" << "\n";
    }
    return 0;
}
