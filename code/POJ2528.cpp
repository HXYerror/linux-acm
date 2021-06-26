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
const int MAX = 1000100;//100000
const int MAX_1 = 100010;
const int MAX_2 = 1000010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;//998244353;
const double PI = acos(-1);
ll T,N,M,K;

/*---------------------------------------------------------------------------------------------------*/
struct Tree
{
    int l,r;
    ll lazy;
}t[MAX*4];
int point[MAX];
int vis[MAX_1];
int Lp[MAX_1],Rp[MAX_1];
/* --------------------------------------------------------------------------------------------------*/

void build(int pos,int l,int r)
{
    t[pos].r = r;
    t[pos].l = l;
    t[pos].lazy = -1;
    if(l == r)
    {
        return ;
    }
    int mid = (l + r) >> 1;
    build(pos<<1,l,mid);
    build(pos<<1|1,mid+1,r);
}

void pushdown(int pos)
{
    t[pos<<1].lazy = t[pos].lazy;
    t[pos<<1|1].lazy = t[pos].lazy;
    t[pos].lazy = -1;
}

void update(int pos,int l,int r, int x)
{
    if(t[pos].l >= l&& t[pos].r <= r)
    {
        t[pos].lazy = x;
        return;
    }
    if(t[pos].lazy != -1) pushdown(pos);
    int mid = (t[pos].l + t[pos].r) >> 1;
    if(l <= mid) update(pos<<1,l,r,x);
    if(r > mid) update(pos<<1|1,l,r,x);
}


int query(int pos,int l,int r)
{
    int ans = 0;
    if(t[pos].lazy != -1)
    {
        if(vis[t[pos].lazy] != 1)
        {
            vis[t[pos].lazy] = 1;
            ans++;
        }
        return ans;
    }
    if(t[pos].l == t[pos].r) return 0;
    if(t[pos].lazy != -1) pushdown(pos);
    int mid = (t[pos].l + t[pos].r) >> 1;
    if(l <= mid) ans += query(pos<<1,l,r);
    if(r > mid) ans += query(pos<<1|1,l,r);
    return ans;
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
        cin >> N;
        fill(vis,vis+MAX_1,0);
        int cnt = 0;
        for(int i = 1;i <= N;i++)
        {
            cin >> Lp[i] >> Rp[i];
            point[cnt++] = Lp[i];
            point[cnt++] = Rp[i];
        }
        sort(point,point+cnt);
        int m = unique(point,point+cnt) - point;
        cnt = m;
        for(int i = 1;i < m;i++)
        {
            if(point[i] - point[i-1] > 1) point[cnt++] = point[i];
        }
        sort(point,point+cnt);
        build(1,0,cnt);
        for(int i = 1;i <= N;i++)
        {
            int l = lower_bound(point,point+cnt,Lp[i]) - point;
            int r = lower_bound(point,point+cnt,Rp[i]) - point;
            update(1,l,r,i);
        }
        cout << query(1,0,cnt) << endl;
    }
    return 0;
}

