
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
const int MAX = 15;//100000
const int MAX_1 = 110;
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
int mark[MAX][MAX];
int sx[MAX_1],sy[MAX_1];
struct Node
{
    int x,y;
    int time;
    Node(int xx,int yy ,int tt):x(xx),y(yy),time(tt){}
};
int to[4][2] = {0,-1,0,1,1,0,-1,0};
/* --------------------------------------------------------------------------------------------------*/

void bfs(int x,int y,int m)
{
    queue<Node> q;
    q.push(Node(x,y,0));
    mark[x][y] = m;
    while(!q.empty())
    {
        Node now = q.front();
//cout << now.x << " " <<now.y << " " << now.cnt <<endl;
        int tempx,tempy;
        q.pop();
        for(int i = 0;i < 4;i++)
        {
            tempx = to[i][0] + now.x;
            tempy = to[i][1] + now.y;
            if(tempx >= 0 && tempy >= 0 && tempx < N && tempy < M && cell[tempx][tempy] == '#' && !mark[tempx][tempy])
            {
                q.push(Node(tempx,tempy,now.time+1));
                mark[tempx][tempy] = m;
            }
        }
    }
}

int bfstime(int x,int y)
{
    queue<Node> q;
    q.push(Node(x,y,0));
    vis[x][y] = 1;
    while(!q.empty())
    {
        Node now = q.front();
//cout << now.x << " " <<now.y << " " << now.cnt <<endl;
        int tempx,tempy;
        q.pop();
        for(int i = 0;i < 4;i++)
        {
            tempx = to[i][0] + now.x;
            tempy = to[i][1] + now.y;
            if(tempx >= 0 && tempy >= 0 && tempx < N && tempy < M && cell[tempx][tempy] == '#' && !vis[tempx][tempy])
            {
                q.push(Node(tempx,tempy,now.time+1));
                vis[tempx][tempy] = 1;
            }
        }
        if(q.empty()) return now.time;
    }
}

int bfstime1(int x1,int y1,int x2,int y2)
{
    queue<Node> q;
    q.push(Node(x2,y2,0));
    q.push(Node(x1,y1,0));
    vis[x2][y2] = 1;
    vis[x1][y1] = 1;
    while(!q.empty())
    {
        Node now = q.front();
//cout << now.x << " " <<now.y << " " << now.cnt <<endl;
        int tempx,tempy;
        q.pop();
        for(int i = 0;i < 4;i++)
        {
            tempx = to[i][0] + now.x;
            tempy = to[i][1] + now.y;
            if(tempx >= 0 && tempy >= 0 && tempx < N && tempy < M && cell[tempx][tempy] == '#' && !vis[tempx][tempy])
            {
                q.push(Node(tempx,tempy,now.time+1));
                vis[tempx][tempy] = 1;
            }
        }
        if(q.empty()) return now.time;
    }
}

//相同一堆里面要选择最小的，不同堆里面要选择最大的
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* -----------------------------------------------------------------------------------------*/
    cin >> T;
    int m = 0;
    while(T--)
    {
        m++;
        cin >> N >> M;
        memset(mark,0,sizeof(mark));
        for(int i = 0;i < N;i++)
        {
            cin >> cell[i];
        }
        int mintime1,mintime2;
        mintime1 = mintime2 = INF;
        int cnt = 1;
        int flag = 0;
        int cntp = 0;
        for(int i = 0;i < N;i++)
        {
            if(flag) break;
            for(int j = 0;j < M;j++)
            {
                if(cell[i][j] == '#')
                {
                    sx[cntp] = i;
                    sy[cntp] = j;
                    cntp++;
                }
                if(cell[i][j] == '#' && !mark[i][j])
                {
                    if(cnt == 3)
                    {
                        flag = 1;
                        break;
                    }
                    bfs(i,j,cnt);
                    cnt++;
                }
            }
        }
        //当只有一块的时候，俩个人可以设计射击不同的草使时间更少
        if(flag)
        {
            cout << "Case " << m << ": " << -1 << "\n";
            continue;
        }
        int ans;
        if(cnt == 3)
        {
            for(int i = 0;i < cntp;i++)
            {
                memset(vis,0,sizeof(vis));
                int n = bfstime(sx[i],sy[i]);
                if(mark[sx[i]][sy[i]] == 1) mintime1 = min(mintime1,n);
                else mintime2 = min(mintime2,n);
            }
            ans = max(mintime1,mintime2);

        }
        else
        {
            ans = INF;
            for(int i = 0;i < cntp;i++)
            {
                for(int j = i;j < cntp;j++)
                {
                    memset(vis,0,sizeof(vis));
                    ans = min(bfstime1(sx[i],sy[i],sx[j],sy[j]),ans);
                }
            }
        }
        cout << "Case " << m << ": " << ans  << "\n";
    }
    return 0;
}
