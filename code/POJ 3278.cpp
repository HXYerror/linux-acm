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
const int MAX = 100010;//100000
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


int bfs()
{
    queue<Pos> q;
    Pos x;
    x.x = N;
    x.deep = 0;
    q.push(x);
    while(!q.empty())
    {
        Pos temp,now;
        now = q.front();
        if(now.x == M) return now.deep;
        temp.deep = now.deep+1;

        temp.x = now.x + 1;
        if(temp.x <= 100000 && !vis[temp.x])  q.push(temp);
        vis[temp.x] = 1;
        temp.x = now.x - 1;
        if(temp.x >= 0 && !vis[temp.x]) q.push(temp);
        vis[temp.x] = 1;
        temp.x = now.x*2;
        if(temp.x <= 2*M && temp.x <= 100000 && !vis[temp.x])
        {
            q.push(temp);
            vis[temp.x] = 1;
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
    cin >> N >> M;
    cout << bfs() <<endl;
    return 0;
}



