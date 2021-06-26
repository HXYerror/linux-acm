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
const int MAX_1 = 2;
const int MAX_2 = 1000010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;//998244353;
const double PI = acos(-1);
ll T,N,M,K;

/*---------------------------------------------------------------------------------------------------*/
//???
struct Tree
{
    int l,r;
    ll sum,lazy;
}tree[4*MAX];
int a[MAX];
/* --------------------------------------------------------------------------------------------------*/

void bulid(int pos,int l,int r)
{
    tree[pos].l = l;
    tree[pos].r = r;
    if(l == r)
    {
        tree[pos].sum = a[l];
        return;
    }
    int mid = (l+r)>>1;
    bulid(pos<<1,l,mid);
    bulid(pos<<1|1,mid+1,r);
    tree[pos].sum = tree[pos<<1].sum + tree[pos<<1|1].sum;
}

void pushdown(int pos)
{
    if(tree[pos].lazy)
    {
        tree[pos<<1].sum += tree[pos].lazy*(tree[pos<<1].r - tree[pos<<1].l + 1);
        tree[pos<<1|1].sum += tree[pos].lazy*(tree[pos<<1|1].r - tree[pos<<1|1].l + 1);
        tree[pos<<1].lazy += tree[pos].lazy;
        tree[pos<<1|1].lazy += tree[pos].lazy;
        tree[pos].lazy = 0;

    }
}

void update(int pos,int l,int r,int x)
{
    if(l <= tree[pos].l && r >= tree[pos].r)
    {
        tree[pos].sum += (ll)x * (tree[pos].r - tree[pos].l + 1);
        tree[pos].lazy += x;
        return;
    }
    pushdown(pos);
    int mid = (tree[pos].l + tree[pos].r) >> 1;
    if(l <= mid) update(pos<<1,l,r,x);
    if(r > mid) update(pos<<1|1,l,r,x);
    tree[pos].sum = tree[pos<<1].sum + tree[pos<<1|1].sum;
}

ll query(int pos,int l,int r)
{
    if(l <= tree[pos].l && r >= tree[pos].r)
    {
        return tree[pos].sum;
    }
    pushdown(pos);
    int mid = (tree[pos].l + tree[pos].r) >> 1;
    ll ans = 0;
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
    cin >> N >> M;
    for(int i = 1;i <= N;i++)
    {
        cin >> a[i];
    }
    bulid(1,1,N);
    int x,y,z;
    while(M--)
    {
        cin >> x;
        if(x == 1)
        {
            cin >> x >> y >> z;
            update(1,x,y,z);
        }
        else
        {
            cin >> x >> y;
            cout << query(1,x,y) <<endl;
        }
    }
    return 0;
}