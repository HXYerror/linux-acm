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
const int MAX = 100010;//100000
const int MAX_1 = 2010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 10;//998244353;
int T,N,M;
/*-------------------------------------------------------------------------------------------*/
struct Edge
{
    int u,v;
    Edge(int uu,int vv):u(uu),v(vv){}
};
vector<int> a[MAX];
vector<Edge> b;
/* ------------------------------------------------------------------------------------------*/
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    cin >> N;
    int x,y;
    for(int i = 1;i < N;i++)
    {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
        b.push_back(Edge(x,y));
    }
    if(N == 2)
    {
        cout << "YES" <<endl;
        return 0;
    }
    int flag = 1;
    for(int i = 0;i < N-1;i++)
    {
        if(a[b[i].u].size() == 1)
        {
            if(a[b[i].v].size() > 2) continue;
            else
            {
                flag = 0;
                break;
            }
        }
        else if(a[b[i].v].size() == 1)
        {
            if(a[b[i].u].size() > 2) continue;
            else
            {
                flag = 0;
                break;
            }
        }
        else
        {
            if(a[b[i].u].size() > 2 && a[b[i].v].size() > 2) continue;
            else
            {
                flag = 0;
                break;
            }
        }
    }
    if(flag) cout << "YES" <<endl;
    else cout << "NO" <<endl;
    return 0;
}