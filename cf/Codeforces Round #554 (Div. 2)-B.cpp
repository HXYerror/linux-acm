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
const int MAX = 300010;
const int MAX_1 = 100;
const int INF = 0xfffffff;//268435455,2e8;
const double EPS = 0.0000001;
const int MOD = 1000000007;
int T,N,M;

/*-------------------------------------------------------------------------------------------*/

int er[40];
int ans[40];

/* ------------------------------------------------------------------------------------------*/

void BinaryRecursion(int n,int step)
{
    int a;
    a=n%2;
    n=n>>1;
    if (n==0);
    else BinaryRecursion(n,step+1);
    er[step] = a;
}

void fan(int n,int m)
{
    for(int i = m;i <= n;i++)
    {
        if(ans[i]) ans[i] = 0;
        else ans[i] = 1;
    }
}

int f(int n)
{
    int i;
    for(i = 0;i <= n;i++)
    {
        if(!ans[i])
        {
            return i;
        }
    }
    return i;
}

void f1(int n)
{
    for(int i = n;i >= 0;i--)
    {
        if(ans[i] == 1)
        {
            ans[i] = 0;
        }
        else
        {
            ans[i] = 1;
            return;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
/* --------------------------------------------------------------------------------------*/
    cin >> N;
    fill(er,er+40,-1);
    BinaryRecursion(N,0);
    int i = 0;
    for(;i < 50;i++)
    {
        if(er[i] == -1) break;
    }
    i--;
    for(int j = 0;j <= i;j++)
    {
        ans[j] = er[i - j];
        //cout << ans[j];
    }

    int cnt = 0;
    int cn = 0;
    int a[50];

    while(1)
    {
        int k = f(i);
        if(k > i)
        {
            break;
        }
        else
        {
            a[cn++] = i - k + 1;
            fan(i,k);
            cnt++;
            int k = f(i);
            if(k > i) break;
            f1(i);
            cnt++;
        }
//        for(int j = 0;j <= i;j++)
//        {
//            cout <<ans[j] << " ";
//        }
//        cout <<endl;
    }

    if(cnt == 0) cout << 0 <<endl;
    else
    {
        cout <<cnt <<endl;
        for(int j = 0;j < cn;j++)
        {
            cout << a[j];
            if(j!= cnt) cout << " ";
        }
    }
    return 0;
}

