
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
const int MAX = 3010;//100000
const int MAX_1 = 100010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;
const double PI = acos(-1);
LL T,N,M;
/*-------------------------------------------------------------------------------------------*/
int hgt[MAX][MAX];
 
/* ------------------------------------------------------------------------------------------*/
 
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    int a,b;
    cin >> N >> M >> a >> b;
    LL g,x,y,z;
    cin >> g >>x>>y>>z;
    int k;
    for(int i = 1;i <= N;i++)
    {
        deque<pair<int,int>> q;
        k = 1;
        for(int j = 1;j <= M;++j)
        {
            while(q.size() && q.back().first >= g) q.pop_back();
            while(q.size() && q.front().second < j-b+1) q.pop_front();
            q.push_back({g,j});
            if(j >= b)
            {
                hgt[i][k++] = q.front().first;
            }
            g = (g*x + y) % z;
        }
    }
 
    LL ans = 0;
    for(int j = 1;j <= M;j++)
    {
        deque<pair<int,int>> q;
        for(int i = 1;i <= N;++i)
        {
            while(q.size() && q.back().first >= hgt[i][j]) q.pop_back();
            while(q.size() && q.front().second < i - a+1) q.pop_front();
            q.push_back({hgt[i][j],i});
            if(i >= a)
            {
                ans += (LL)q.front().first;
            }
        }
    }
    cout << ans;
    return 0;
}