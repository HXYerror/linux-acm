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
int vis[MAX][MAX][MAX];
struct Node
{
    int a,b,s;
    int cnt;
    Node(int aa,int bb,int ss,int tt):a(aa),b(bb),s(ss),cnt(tt){}
};
int ans;
/* --------------------------------------------------------------------------------------------------*/

int bfs()
{
    queue<Node> q;
    q.push(Node(0,0,K,0));
    vis[0][0][K] = 1;
    while(!q.empty())
    {
        Node temp = q.front();
        //cout << temp.s << " " <<temp.a << " " << temp.b << " " <<temp.cnt << "\n";
        if((temp.a == K/2 && temp.b == K/2)
           || (temp.a == K/2 && temp.s == K/2)
           || (temp.b == K/2 && temp.s == K/2))
        {
            return temp.cnt;
        }
        q.pop();
        for(int i = 1;i <= 6;i++)
        {
            int a,b,s;
            switch(i)
            {
                case 1://12
                    a = temp.a <= M - temp.b ? 0 : temp.a - (M - temp.b);
                    b = temp.a <= M - temp.b ? temp.a + temp.b : M;
                    if(vis[a][b][temp.s]) break;
                    q.push(Node(a,b,temp.s,temp.cnt+1));
                    vis[a][b][temp.s] = 1;
                    break;
                case 2://21
                    b = temp.b <= N - temp.a ? 0 : temp.b - (N - temp.a);
                    a = temp.b <= N - temp.a ? temp.a + temp.b : N;
                    if(vis[a][b][temp.s]) break;
                    q.push(Node(a,b,temp.s,temp.cnt+1));
                    vis[a][b][temp.s] = 1;
                    break;
                case 3://13
                    a = temp.a <= K - temp.s ? 0 : temp.a - (K - temp.s);
                    s = temp.a <= K - temp.s ? temp.a + temp.s : K;
                    if(vis[a][temp.b][s]) break;
                    q.push(Node(a,temp.b,s,temp.cnt+1));
                    vis[a][temp.b][s] = 1;
                    break;
                case 4://31
                    s = temp.s <= N - temp.a ? 0 : temp.s - (N - temp.a);
                    a = temp.s <= N - temp.a ? temp.a + temp.s : N;
                    if(vis[a][temp.b][s]) break;
                    q.push(Node(a,temp.b,s,temp.cnt+1));
                    vis[a][temp.b][s] = 1;
                    break;
                case 5://23
                    b = temp.b <= K - temp.s ? 0 : temp.b - (K - temp.s);
                    s = temp.b <= K - temp.s ? temp.s + temp.b : K;
                    if(vis[temp.a][b][s]) break;
                    q.push(Node(temp.a,b,s,temp.cnt+1));
                    vis[temp.a][b][s] = 1;
                    break;
                case 6://32
                    s = temp.s <= M - temp.b ? 0 : temp.s - (M - temp.b);
                    b = temp.s <= M - temp.b ? temp.b + temp.s : M;
                    if(vis[temp.a][b][s]) break;
                    q.push(Node(temp.a,b,s,temp.cnt+1));
                    vis[temp.a][b][s] = 1;
                    break;
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
    while(cin >> K >> N >> M)
    {
        if(!K && !N && !M) break;
        if(K % 2)
        {
            cout << "NO" << "\n";
            continue;
        }
        memset(vis,0,sizeof(vis));
        int n = bfs();
        if(n != -1)
        {
            cout << n << "\n";
        }
        else cout << "NO" << "\n";
    }
    return 0;
}
