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
const int MAX = 3;
const int MAX_1 = 2;
const int INF = 0x3f3f3f3f;//1061109567,1e9;
const double EPS = 0.0000001;
const int MOD = 10000;
int T,N,M;


/*-------------------------------------------------------------------------------------------*/
int a[MAX][MAX];
int b[MAX][MAX];

/* ------------------------------------------------------------------------------------------*/

void calculate(int a[][MAX],int b[][MAX])
{
    int c[MAX][MAX];
    for(int i = 0;i < MAX_1;i++)
    {
        fill(c[i],c[i]+MAX,0);
    }
    for(int i =0;i < MAX_1;i++)
    {
        for(int j = 0;j < MAX_1;j++)
        {
            for(int k = 0;k < MAX_1;k++)
            {
                c[i][j] += (a[i][k]*b[k][j]) % MOD;
            }
        }
    }
    for(int i = 0;i < MAX_1;i++)
    {
        for(int j = 0;j < MAX_1;j++)
        {
            a[i][j] = c[i][j];
        }
    }
}

void Fibonacci(int n)
{
    while(n)
    {
        if(n&1)
        {
            calculate(b,a);
        }
        calculate(a,a);
        n >>= 1;
    }
}
int main()
{
    //std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/

    while(cin >> N && N != -1)
    {
        //构造矩阵，相当于底数
        a[0][0] = 0;
        a[0][1] = 1;
        a[1][0] = 1;
        a[1][1] = 1;
        //相当于sum= 1
        b[0][0] = 1;
        b[0][1] = 0;
        b[1][0] = 0;
        b[1][1] = 1;
        if(N == 0)
        {
            cout << 0 <<endl;
            continue;
        }
        if(N == 1 || N == 2)
        {
            cout << 1 << endl;
            continue;
        }
        Fibonacci(N-2);
        cout << (b[0][1]+b[1][1]) % MOD << endl;
    }
    return 0;
}
