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
const int MAX = 200010;//100000
const int MAX_1 = 2;
const int MAX_2 = 1000010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;//998244353;
const double PI = acos(-1);
ll T,N,M,K;

/*---------------------------------------------------------------------------------------------------*/
//线段树
struct Tree
{
    int l,r;
    ll sum,lazy;
    int mx;
}tree[4*MAX];
int a[MAX];
/* --------------------------------------------------------------------------------------------------*/

void bulid(int pos,int l,int r)//建树
{
    tree[pos].l = l;
    tree[pos].r = r;
    if(l == r)
    {
        tree[pos].mx = a[l];
        return;
    }
    int mid = (l+r)>>1;
    bulid(pos<<1,l,mid);
    bulid(pos<<1|1,mid+1,r);
    tree[pos].mx = max(tree[pos<<1].mx,tree[pos<<1|1].mx);
}

void update(int pos,int v,int x)
{
    if(tree[pos].l == v && tree[pos].r == v)
    {
        tree[pos].mx = max(tree[pos].mx,x);
        return;
    }
    int mid = (tree[pos].l + tree[pos].r) >> 1;
    if(v <= mid) update(pos<<1,v,x);
    if(v > mid) update(pos<<1|1,v,x);
    tree[pos].mx = max(tree[pos<<1].mx,tree[pos<<1|1].mx);
}

int query(int pos,int l,int r)
{
    if(tree[pos].l >= l && tree[pos].r <= r)
    {
        return tree[pos].mx;
    }
    int ans = 0;
    int mid = (tree[pos].l + tree[pos].r) >> 1;
    if(l <= mid) ans =max(query(pos<<1,l,r),ans);
    if(r > mid) ans =max(query(pos<<1|1,l,r),ans);
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
    while(cin >> N >> M)
    {
        for(int i = 1;i <= N;i++)
        {
            cin >> a[i];
        }
        bulid(1,1,N);
        int x,y;
        char c;
        while(M--)
        {
            cin >> c;
            if(c == 'U')
            {
                cin >> x >> y;
                update(1,x,y);
            }
            else
            {
                cin >> x >> y;
                cout << query(1,x,y) <<endl;
            }
        }
    }

    return 0;
}