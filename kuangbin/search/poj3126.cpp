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
const int MAX = 100100;//100000
const int MAX_1 = 100010;
const int MAX_2 = 1000010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;//998244353;
const double PI = acos(-1);
//void runtime(){cout << "The run time is:" << (double)clock() /CLOCKS_PER_SEC<< "s" << endl;}
ll T,N,M,K;
/*---------------------------------------------------------------------------------------------------*/
int vis[MAX];
struct Pos
{
    int x;
    int deep;
};
/* --------------------------------------------------------------------------------------------------*/
bool is_prime(int n)
{
    if(n == 2) return true;
    for(int i = 2;i*i <= n;i++)
    {
        if(n % i == 0) return false;
    }
    return true;
}

int bfs(int n)
{
    fill(vis,vis+MAX,0);
    queue<Pos> q;
    Pos x;
    x.x = n;
    x.deep = 0;
    q.push(x);
    vis[n] = 1;
    while(!q.empty())
    {
        Pos temp,now;
        now = q.front();
        //cout << now.x <<endl;
        if(now.x == M) return now.deep;
        temp.deep = now.deep + 1;
        int a = now.x % 10;
        int b = (now.x % 100) / 10;
        int c = (now.x % 1000) / 100;
        for(int i = 0;i <= 9;i++)
        {
            temp.x = now.x - a + i;
            if(!vis[temp.x] && is_prime(temp.x))
            {
                q.push(temp);
                vis[temp.x] = 1;
            }
            temp.x = now.x - b*10 + i*10;
            if(!vis[temp.x] && is_prime(temp.x))
            {
                q.push(temp);
                vis[temp.x] = 1;
            }
            temp.x = now.x - c*100 + i*100;
            if(!vis[temp.x] && is_prime(temp.x))
            {
                q.push(temp);
                vis[temp.x] = 1;
            }
        }
        a =now.x / 1000;
        for(int i = 1;i <= 9;i++)
        {
            temp.x = now.x - a*1000 + i*1000;
            if(!vis[temp.x] && is_prime(temp.x))
            {
                q.push(temp);
                vis[temp.x] = 1;
            }
        }
        q.pop();
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
        cin >> N >> M;
        int ans = bfs(N);
        if(ans != -1) cout << ans <<endl;
        else cout << "Impossible" <<endl;
    }
    return 0;
}
