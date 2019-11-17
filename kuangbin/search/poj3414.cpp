
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
const int MAX = 110;//100000
const int MAX_1 = 1000100;
const int MAX_2 = 1000010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;//998244353;
const double PI = acos(-1);
//void runtime(){cout << "The run time is:" << (double)clock() /CLOCKS_PER_SEC<< "s" << endl;}
ll T,N,M,K;

/* --------------------------------------------------------------------------------------------------*/
int vis[MAX][MAX];
struct Pre
{
    int f;
    int op;
}pre[MAX*MAX];
struct Node
{
    int f;
    int a,b;
    int cnt;
    Node(int ff,int aa,int bb,int tt): f(ff),a(aa),b(bb),cnt(tt){}
};
vector<int> ansp;
int ans;
/* --------------------------------------------------------------------------------------------------*/

int bfs()
{
    queue<Node> q;
    int cnt = 1;
    q.push(Node(0,N,0,1));
    pre[cnt].f = 0;
    pre[cnt++].op = 1;
    q.push(Node(0,0,M,2));
    pre[cnt].f = 0;
    pre[cnt++].op = 2;
    while(!q.empty())
    {
        Node temp = q.front();
        //cout << temp.f << " " <<temp.a << " " << temp.b << " " <<temp.cnt << "\n";
        if(temp.a == K || temp.b == K)
        {
            return temp.cnt;
        }

        q.pop();
        for(int i = 1;i <= 6;i++)
        {
            switch(i)
            {
                case 1:
                    if(vis[N][temp.b]) break;
                    q.push(Node(temp.cnt,N,temp.b,cnt));
                    vis[N][temp.b] = 1;
                    pre[cnt].f = temp.cnt;
                    pre[cnt++].op = 1;
                    break;
                case 2:
                    if(vis[temp.a][M]) break;
                    q.push(Node(temp.cnt,temp.a,M,cnt));
                    vis[temp.a][M] = 1;
                    pre[cnt].f = temp.cnt;
                    pre[cnt++].op = 2;
                    break;
                case 3:
                    if(vis[0][temp.b]) break;
                    q.push(Node(temp.cnt,0,temp.b,cnt));
                    vis[0][temp.b] = 1;
                    pre[cnt].f = temp.cnt;
                    pre[cnt++].op = 3;
                    break;
                case 4:
                    if(vis[temp.a][0]) break;
                    q.push(Node(temp.cnt,temp.a,0,cnt));
                    vis[temp.a][0] = 1;
                    pre[cnt].f = temp.cnt;
                    pre[cnt++].op = 4;
                    break;
                case 5:
                    int a,b;
                    a = temp.a <= M-temp.b ? 0 : temp.a - (M - temp.b);
                    b = temp.a <= M-temp.b ? temp.b + temp.a : M;
                    if(vis[a][b]) break;
                    q.push(Node(temp.cnt,a,b,cnt));
                    vis[a][b] = 1;
                    pre[cnt].f = temp.cnt;
                    pre[cnt++].op = 5;
                    break;
                case 6:
                    b = temp.b <= N-temp.a ? 0 : temp.b - (N - temp.a);
                    a = temp.b <= N-temp.a ? temp.a + temp.b : N;
                    if(vis[a][b]) break;
                    q.push(Node(temp.cnt,a,b,cnt));
                    vis[a][b] = 1;
                    pre[cnt].f = temp.cnt;
                    pre[cnt++].op = 6;
                    break;
            }
        }
    }
    return -1;
}

void mycout(int flag)
{
    switch(flag)
    {
        case 1:
            cout << "FILL(1)" <<"\n";
            break;
        case 2:
            cout << "FILL(2)" <<"\n";
            break;
        case 3:
            cout << "DROP(1)" <<"\n";
            break;
        case 4:
            cout << "DROP(2)" <<"\n";
            break;
        case 5:
            cout << "POUR(1,2)" <<"\n";
            break;
        case 6:
            cout << "POUR(2,1)" <<"\n";
            break;
    }
}

void find_pre(int x)
{
    if(pre[x].f == x) return;
    else
    {
        ansp.push_back(pre[x].op);
        ans++;
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
    cin >> N >> M >> K;
    pre[0].f = 0;
    int n = bfs();
    if(n != -1)
    {
        find_pre(n);
        cout << ans << "\n";
        for(int i = ansp.size()-1;i >= 0;i--)
        {
            mycout(ansp[i]);
        }
    }
    else cout << "impossible" << "\n";
    return 0;
}
