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
const int MAX = 1000010;//100000
const LL MAX_1 = 1000010;
const int MAX_2 = 1000010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;//998244353;
const double PI = acos(-1);
LL T,N,M,K;

/*-------------------------------------------------------------------------------------------*/
char g[10][30];
/* ------------------------------------------------------------------------------------------*/
int check5(int j)
{
    if(g[1][j] == 'X') return 5;
    else if(g[4][j] == 'X') return 2;
    else return 3;
}

int check6(int j)
{
    if(g[1][j+3] == '.') return 6;
    else
    {
        if(g[3][j+2] == 'X') return 9;
        else return 0;
    }
}

int check(int j)
{
    int cnt = 0;
    for(int k = 0;k < 5 ;k++)
    {
        for(int i = 0;i < 7;i++)
        {
            if(g[i][k+j] == 'X') cnt++;
        }
    }
    if(cnt == 5*2) return check5(j);
    else if(cnt == 6*2) return check6(j);
    else
    {
        if(cnt == 2*2) return 1;
        else if(cnt == 4*2) return 4;
        else if(cnt == 3 * 2) return 7;
        else if(cnt == 7*2) return 8;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* -----------------------------------------------------------------------------------------*/
    cin >> T;
    while(T--)
    {
        int a[5];
        for(int i = 0;i < 7;i++)
        {
            cin >> g[i];
            g[i][21] = '.';
        }
        a[1] = check(0);
        a[2] = check(5);
        a[3] = check(12);
        a[4] = check(17);
        cout << a[1] << a[2] << ":" << a[3] << a[4] <<endl;
    }
    return 0;
}