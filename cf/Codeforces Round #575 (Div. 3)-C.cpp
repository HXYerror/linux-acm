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
const int MAX = 100010;//100000
const int MAX_1 = 100010;
const int INF = 100000;//0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;//998244353;
const double PI = acos(-1);
LL T,N,M;
/*-------------------------------------------------------------------------------------------*/
 
struct Pos
{
    int x,y;
}pos[MAX];
/* ------------------------------------------------------------------------------------------*/
 
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    cin >> T;
    int cnt;
    Pos temp;
    while(T--)
    {
        cin >> N;
        int x,b,c,d;
        int flag = 0;
        int ansxmax,ansxmin;
        int ansymax,ansymin;
        cin >> temp.x >> temp.y;
        cin >> x >> b >> c >> d;        \
        ansxmax = ansymax = INF;
        ansxmin = ansymin = -INF;
        for(int i = 0;i < N;i++)
        {
            //0,2左右，1,3上下
            pos[i] = temp;
            if(x == 0)
            {
                if(ansxmin == -INF) ansxmin = pos[i].x;
                ansxmin = max(ansxmin,pos[i].x);
            }
            if(b == 0)
            {
                if(ansymax == INF) ansymax = pos[i].y;
                ansymax = min(ansymax,pos[i].y);
            }
            if(c == 0)
            {
                if(ansxmax == INF) ansxmax = pos[i].x;
                ansxmax = min(ansxmax,pos[i].x);
            }
            if(d == 0)
            {
                if(ansymin == -INF) ansymin = pos[i].y;
                ansymin = max(ansymin,pos[i].y);
            }
            if(i != N - 1)
            {
                cin >> temp.x >> temp.y;
                cin >> x >> b >> c >> d;
            }
        }
        if(ansymin > ansymax || ansxmax < ansxmin) flag = 1;
        if(flag)
        {
            cout << "0" <<endl;
        }
        else
        {
            cout << "1 " << (ansxmin + ansxmax) / 2 << " " << (ansymin + ansymax) / 2<<endl;
        }
    }
    return 0;
}