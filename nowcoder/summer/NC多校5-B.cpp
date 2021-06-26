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
const int MAX = 3;//100000
const int MAX_1 = 2;
const int MAX_2 = 1000010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int mod = 998244353;//998244353;
const double PI = acos(-1);
LL T,N,M,K;
/*-------------------------------------------------------------------------------------------*/
 
/* ------------------------------------------------------------------------------------------*/
void calculate(LL a[][MAX],LL b[][MAX],LL MOD)//这就是一个矩阵乘法
{
    LL c[MAX][MAX] = {0};
    for(int i =0;i < MAX_1;i++)
    {
        for(int j = 0;j < MAX_1;j++)
        {
            for(int k = 0;k < MAX_1;k++)
            {
                c[i][j] += (a[i][k]*b[k][j]) % MOD;
                c[i][j] = c[i][j] % MOD;
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
 
void Qmod2(int n,int m,LL MOD,LL a[][MAX],LL b[][MAX],LL c[][MAX])//快速幂的过程
{
    while(n || m)
    {
        if(n & 1)
        {
            calculate(b,a,MOD);
        }
        if(m & 1)
        {
            calculate(c,a,MOD);
        }
        calculate(a,a,MOD);
        n >>= 1;
        m >>= 1;
    }
}
 
void Qmod1(char str[],LL MOD,LL a[][MAX],LL b[][MAX])//快速幂的过程
{
    int l = strlen(str);
    LL c[MAX][MAX];
    int n;
    for(int i = l-1;i >= 0;i--)
    {
        n = str[i] - '0';
        c[0][0] = a[0][0];
        c[0][1] = a[0][1];
        c[1][0] = a[1][0];
        c[1][1] = a[1][1];
        Qmod2(n,9,MOD,c,b,a);
    }
}
 
 
int main()
{
    //std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* -----------------------------------------------------------------------------------------*/
    LL a[MAX][MAX];
    LL b[MAX][MAX];
    LL x1,x2,p,q;
    scanf("%lld%lld%lld%lld",&x1,&x2,&p,&q);
    LL MOD;
    char str[MAX_2];
    scanf("%s%lld",str,&MOD);
    //构造矩阵，相当于底数
    a[0][0] = 0;
    a[0][1] = q;
    a[1][0] = 1;
    a[1][1] = p;
    //相当于sum= 1
    b[0][0] = 1;
    b[0][1] = 0;
    b[1][0] = 0;
    b[1][1] = 1;
    Qmod1(str,MOD,a,b);
    printf("%lld",((b[0][0] * (x1 % MOD) ) % MOD + (b[1][0] * (x2 % MOD)) % MOD) % MOD);
    return 0;
}