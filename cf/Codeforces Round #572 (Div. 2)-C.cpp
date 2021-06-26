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
int table[35][MAX];
int a[MAX];
int b[35][MAX];
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
    for(int i = 0;i < N;i++)
    {
        cin >> a[i];
    }
    int k = 0;
    int sum = 0;
    for(int j = 0;(1 << j) < N;j++)
    {
        int n = 1 << j;
        for(int i = 0;i < N - sum;i++)
        {
            if(i+n >= N-sum) break;
            k = a[i] + a[i+n];

            if(k >= 10) table[j][i] = 1;
            else table[j][i] = 0;

            if(i < n*2)
            {
                if(table[j][i]) b[j][i] =1;
                else b[j][i] = 0;
            }
            else
            {
                if(table[j][i]) b[j][i] = b[j][i-n*2]+1;
                else b[j][i] = b[j][i-n*2];
            }

            a[i] = k % MOD;
        }
        sum += n;
    }
    cin >> M;
    int x,y;
    while(M--)
    {
        int ans = 0;
        cin >> x >> y;
        int n = y - x +1;
        int m = 0;
        while(n > 1)
        {
            n = n / 2;
            m++;
        }
        n = y - x +1;
        for(int i = 1;i <= m;i++)
        {
            int p = 1 << i;
            n /= 2;
            ans += (b[i-1][x-1+(n-1)*p] -b[i-1][x-1]);
            if(table[i-1][x-1]) ans++;
        }
        cout << ans <<endl;
    }
    return 0;
}
