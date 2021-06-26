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
const int MAX = 10;
const int INF = 0xfffffff;//268435455,2e8;
const double EPS = 0.0000001;
const int MOD = 100;
int T,N,M;

//std::ios::sync_with_stdio(false);
/*-------------------------------------------------------------------------------------------*/
int flag[8] = {0,1,2,3,1,3,2,1};
/* ------------------------------------------------------------------------------------------*/

int find_my(int a,int b,int c,int week,int day)
{
    int m;
    if(flag[week] == 1)
    {
        if(a > 0)
        {
            if(week == 7)
            {
                m = find_my(a-1,b,c,1,day+1);
            }
            else
            {
                m = find_my(a-1,b,c,week+1,day+1);
            }
        }
        else return day;
    }
    else if(flag[week] == 2)
    {
        if(b > 0)
        {
            m = find_my(a,b-1,c,week+1,day+1);
        }
        else return day;
    }
    else
    {
        if(c > 0)
        {
            m = find_my(a,b,c-1,week+1,day+1);
        }
        else return day;
    }
     return m;
}


int main()
{
    int ans = 0;
    int a,b,c;
    cin >> a >> b >> c;
    int x,y,z;
    x = a / 3;
    y = b / 2;
    z = c / 2;
    int m;
    m = min(x,y);
    m = min(m,z);
    a -= 3*m;
    b -= 2*m;
    c -= 2*m;
    ans += m*7;
    int mans = 0;
    for(int i = 1;i < 8;i++)
    {
        int temp = find_my(a,b,c,i,0);
        if(temp > mans)
        {
            mans = temp;
        }
    }
    cout << ans + mans;
    return 0;
}