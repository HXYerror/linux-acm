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
const int MAX = 1010;//100000
const int MAX_1 = 100010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;
const double PI = acos(-1);
LL T,N,M;
/*-------------------------------------------------------------------------------------------*/
char cell[MAX][MAX];
int up[MAX][MAX],l[MAX][MAX],r[MAX][MAX];
struct juzheng
{
    int xa,ya,xb,yb;
}a[2];
/* ------------------------------------------------------------------------------------------*/
 
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    cin >> N >> M;
    for(int i = 0;i < N;i++)
    {
        cin >> cell[i];
    }
    int ansf = 0;
    int anss = 0;
    for(int i = 0;i < N;i++)
    {
        int lo = -1;
        int ro = M;
        for(int j = 0;j < M;j++)
        {
            if(cell[i][j] == '0')
            {
                up[i][j] = l[i][j] = 0;
                lo = j;
            }
            else
            {
                up[i][j] = i == 0 ? 1 : up[i-1][j] + 1;
                l[i][j] = i == 0 ? lo+1 : max(l[i-1][j],lo+1);
            }
        }
        for(int j = M-1;j >= 0;j--)
        {
            if(cell[i][j] == '0')
            {
                r[i][j] = M;
                ro = j;
            }
            else
            {
                r[i][j] = i == 0 ? ro-1 : min(r[i-1][j],ro-1);
                int k = up[i][j] * (r[i][j] - l[i][j] + 1);
                //cout << k <<endl;
                //cout << a[0].xa << " "<< i - up[i][j] + 1 << " " << a[0].xb  << " " << i  << " "<< a[0].ya << " " << l[i][j] << " " << a[0].yb << " " << r[i][j]<<endl;
                if(!(a[0].xa == i -  up[i][j] + 1 && a[0].xb == i && a[0].ya == l[i][j] && a[0].yb == r[i][j]))
                {
                    if(k > ansf)
                    {
                        anss = ansf;
                        ansf = k;
                        a[0].xa = i - up[i][j] +1;
                        a[0].xb = i;
                        a[0].ya = l[i][j];
                        a[0].yb = r[i][j];
                        int m = (up[i][j] - 1) * (r[i][j] - l[i][j] + 1);
                        anss = max(anss,m);
                        m = (up[i][j]) * (r[i][j] - l[i][j]);
                        anss = max(anss,m);
 
                    }
                    else if(k > anss)
                    {
                        anss = k;
                    }
                }
 
            }
        }
    }
    cout << anss <<endl;
    return 0;
}