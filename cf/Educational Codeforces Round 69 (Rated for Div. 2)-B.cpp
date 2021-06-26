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
const int MAX = 100020;//100000
const int MAX_1 = 70;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;//998244353;
const double PI = acos(-1);
LL T,N,M;
/*-------------------------------------------------------------------------------------------*/
 
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
    int flag = 1;
    int u,d,x,y;
    cin >> y;
    u = d = 0;
    for(int i = 1 ;i < N;i++)
    {
        cin >> x;
        if(flag)
        {
            if(x > y)//sheng
            {
                if(d)
                {
                    flag = 0;
                    continue;
                }
                if(u == 2)
                {
                    flag = 0;
                    continue;
                }
                u = 1;
            }
            else
            {
                if(u) u = 2;
                if(d == 2)
                {
                    flag = 0;
                    continue;
                }
                d = 1;
            }
            y = x;
        }
        else continue;
    }
    if(flag) cout << "YES" <<endl;
    else cout << "NO" <<endl;
    return 0;
}