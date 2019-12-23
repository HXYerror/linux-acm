/*************************************************************************
	> File Name: Gtest.cpp
	> Author: HXYerror
	> Mail: zx841985525@163.com 
	> Created Time: 2019年12月23日 星期一 16时56分10秒
 ************************************************************************/

#include <bits/stdc++.h>
#define ll int
using namespace std;

/* --------------------------------------------------------------------------------------------------*/

/* --------------------------------------------------------------------------------------------------*/
struct t
{
    int l,r;
    ll mx,la;
}tr[10][4*101010];
void build(int x,int p,int l,int r)
{
    tr[x][p].l = l;
    tr[x][p].r = r;
    if(l == r)
    {
        tr[x][p].mx = 0;
        return ;
    }
    int mid = (l+r) >>1;
    build(x,p<<1,l,mid);
    build(x,p<<1|1,mid+1,r);
    
    tr[x][p].mx = max(tr[x][p<<1].mx,tr[x][p<<1|1].mx);//改
}
ll n,i,j,k,l,m,d[11];//改
void pd(int sx,int p)
{
    if(tr[sx][p].la)
    {
        tr[sx][p<<1].la += tr[sx][p].la;
        tr[sx][p<<1|1].la += tr[sx][p].la;

        tr[sx][p<<1].mx += tr[sx][p].la;
        tr[sx][p<<1|1].mx += tr[sx][p].la;
        tr[sx][p].la = 0;
    }
}
void pu(int sx ,int p)
{
    tr[sx][p].mx = max(tr[sx][p<<1].mx,tr[sx][p<<1|1].mx);
}
void up(int sx,int p,int l,int r,int x)
{
    if(l <= tr[sx][p].l && r>=tr[sx][p].r)
    {
        tr[sx][p].mx += x;
        tr[sx][p].la += x;
        return;
    }
    else
    {
        pd(sx,p);
        int mid = (tr[sx][p].l + tr[sx][p].r)/2;
        if(l<=mid) up(sx,p<<1,l,r,x);//改
        if(r > mid) up(sx,p<<1|1,l,r,x);
    }
    pu(sx,p);
}
ll qu(int sx,ll p,ll l,ll r)
{
    ll mid = (tr[sx][p].l + tr[sx][p].r)>>1,ma = 0;
    if(l <= tr[sx][p].l && r >= tr[sx][p].r)
    {
        return tr[sx][p].mx;
    }
    pd(sx,p);//改
    if(l <=mid)
    {
        ma = max(qu(sx,p<<1,l,r),ma);//改
    }
    if(r > mid)
    {
        ma = max(qu(sx,p<<1|1,l,r),ma);
    }
    return ma;
}
int main(void)
{
/* --------------------------------------------------------------------------------------------------*/
    scanf("%d%d",&n,&m);
    build(2,1,1,n);
    build(3,1,1,n);
    build(5,1,1,n);
    build(7,1,1,n);
    while(m--)
    {
        char s[1010];
        scanf("%s",s);
        if(s[1] == 'U')
        {
            int l,r,x;
            for(int i = 1;i <=10;i++)
                d[i]=0;
            scanf("%d%d%d",&l,&r,&x);
            for(int i = 2; i*i <= x;i++)
            {
                if(x % i == 0)
                {
                    while(x  % i == 0)
                    {
                        d[i]++;
                        x /= i;
                    }
                }
            }
            if(x > 1)
            {
                d[x]++;
            }
            for(int i = 1;i <= 10;i++)
            {
                if(d[i])
                {
                    up(i,1,l,r,d[i]);
                }
            }
        }
        else
        {
            int l,r;
            scanf("%d%d",&l,&r);
            printf("ANSWER %d\n",max(max(qu(2,1,l,r),qu(3,1,l,r)),max(qu(5,1,l,r),qu(7,1,l,r))));
        }
    }
    return 0;
}
