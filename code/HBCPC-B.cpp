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
LL a[MAX][MAX];
LL b[MAX][MAX];

/* ------------------------------------------------------------------------------------------*/

void calculate(LL a[][MAX],LL b[][MAX],LL mod)
{
    LL c[MAX][MAX];
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
                c[i][j] += (a[i][k]*b[k][j]) % mod;
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

void dengbi(int n,LL mod)
{
    while(n)
    {
        if(n&1)
        {
            calculate(b,a,mod);
        }
        calculate(a,a,mod);
        n >>= 1;
    }
}
int main()
{
    //std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    cin >> T;
    while(T--)
    {
        LL n,q,mod;
        cin >> q >> n >> mod;
        //构造矩阵，相当于底数
        q %= mod;
        a[0][0] = q;
        a[0][1] = 0;
        a[1][0] = 1;
        a[1][1] = 1;
        //相当于sum= 1
        b[0][0] = 1;
        b[0][1] = 0;
        b[1][0] = 0;
        b[1][1] = 1;
        if(n == 0)
        {
            cout << 1 <<endl;
            continue;
        }
        if(n == 1 )
        {
            cout << q << endl;
            continue;
        }
        dengbi(n-1,mod);
        cout << ((b[0][0]+b[1][0]) *q)  % mod << endl;
    }
    return 0;
}
