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
const int MAX = 50010;
const int MAX_1 = 505;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;
int T,N,M;
/*-------------------------------------------------------------------------------------------*/
int a[MAX];
int c[MAX];
int b[MAX];
/* ------------------------------------------------------------------------------------------*/

int lowbit(int x)
{
    return x & (-x);
}

int sum(int x)
{
    int s = 0;
    for(int i = x;i >= 1;i -= lowbit(i))
    {
        s += c[i];
    }
    return s;
}
void addz(int v,int x)
{
    for(int i = v;i <= N;i+=lowbit(i))
    {
        c[i] += x;
    }
}
void addf(int v,int x)
{
    for(int i = v;i <= N;i+=lowbit(i))
    {
        c[i] -= x;
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
    cin >> T;
    for(int k = 1;k <= T;k++)
    {
        cin >> N;
        b[0] = 0;
        for(int i = 1;i <= N;i++)
        {
            cin >> a[i];
            b[i] = b[i-1] + a[i];
        }
        for(int i = 1;i <= N;i++)
        {
            c[i] = b[i] - b[i-lowbit(i)];
        }
        cout << "Case " << k << ":" <<endl;
        string str;
        while(cin >> str && (str != "End"))
        {
            int x,y;
            cin >> x >> y;
            if(str == "Query")
            {
                cout << sum(y) - sum(x-1) <<endl;
            }
            else if (str == "Add")
            {
                addz(x,y);
            }
            else
            {
                addf(x,y);
            }
        }
    }
    return 0;
}
