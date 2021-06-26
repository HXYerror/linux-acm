//#include<bits/stdc++.h>
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
#define LL long long
using namespace std;
const int MAX = 200100;
const int MAX_1 = 505;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;
int T,N,M;
/*-------------------------------------------------------------------------------------------*/
int a[MAX];
int c[MAX];
/* ------------------------------------------------------------------------------------------*/

int lowbit(int x)
{
    return x & (-x);
}

int query(int x ,int y)
{
	int ans = 0;
	while (y >= x)
	{
		ans = max(a[y], ans);
		y --;
		for (; y-lowbit(y) >= x; y -= lowbit(y))
			ans = max(c[y], ans);
	}
	return ans;
}

void update(int x)
{
    int lx;
    while(x <= N)
    {
        c[x] = a[x];
        lx = lowbit(x);
        for(int i = 1;i < lx ;i <<= 1)
        {
            c[x] = max(c[x],c[x-i]);
        }
        x+=lowbit(x);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    while(cin >> N >> M)
    {
        fill(c,c+MAX,0);
        for(int i = 1;i <= N;i++)
        {
            cin >> a[i];
            update(i);
        }
        char c;
        int x,y;
        for(int i = 0;i < M;i++)
        {
            cin >> c;
            cin >> x >> y;
            if(c == 'Q')
            {
                cout << query(x,y) <<endl;
            }
            else
            {
                a[x] = y;
                update(x);
            }
        }

    }
    return 0;
}
//	if(x < y - lowbit(y)) return max(c[y],query(x,y-lowbit(y)));
//	else return max(a[y],query(x,y-1));