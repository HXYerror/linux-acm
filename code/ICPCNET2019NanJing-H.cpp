#include<bits/stdc++.h>
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
#define LL long long
using namespace std;
const int MAX = 1000010;//100000
const LL MAX_1 = 1000010;
const int MAX_2 = 1000010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;//998244353;
const double PI = acos(-1);
LL T,N,M,K;

/*---------------------------------------------------------------------------------------------------*/
//Bellman-Ford
struct Edge
{
    int from;//点
    int to;//点
    int dist;//权值
    Edge(int ff,int tt,int dd) : from(ff),to(tt),dist(dd){}
};
int n,m;//点数边数
vector<Edge> edges;//边列表
vector<int> G[MAX];//每个结点出发的边编号（0开始）
bool inq[MAX];//是否在队列中
int dis[MAX];//s到各个点的距离
int p[MAX];//最短路中上一条弧
int cnt[MAX];//进队次数
/* --------------------------------------------------------------------------------------------------*/

void init(int n)
{
    for(int i = 0;i < n;i++) G[i].clear();
    edges.clear();
}

void AddEdge(int from,int to,int dist)
{
    edges.push_back(Edge(from,to,dist));
    m = edges.size();
    G[from].push_back(m-1);
}

bool BellmanFord(int s)//起点
{
    queue<int> Q;
    memset(inq,0,sizeof(inq));
    memset(cnt,0,sizeof(cnt));
    for(int i = 0;i < n;i++)
    {
        dis[i] = INF;
    }
    dis[s] = 0;
    inq[s] = true;
    Q.push(s);
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        inq[u] = false;
        for(int i = 0;i < G[u].size();i++)
        {
            Edge e = edges[G[u][i]];
            if(dis[u] < INF && dis[e.to] > dis[u] +e.dist)
            {
                dis[e.to] = dis[u] + e.dist;
                p[e.to] = G[u][i];
                if(!inq[e.to])
                {
                    Q.push(e.to);
                    inq[e.to] = true;
                    if(++cnt[e.to] > n) return false;
                }
            }
        }
    }
    return true;
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
        cin >> N >> M;
        int x,y,z;
        init(N);
        n = N;
        for(int i = 0;i < M;i++)
        {
            cin >> x >> y >> z;
            AddEdge(x,y,z);
        }
        for(int i = 0 ;i < 6;i++)
        {
            cin >> x >> y;
            BellmanFord(y);
            cout << -dis[x] <<endl;
            AddEdge(x,y,-dis[x]);
        }
    }
    return 0;
}
