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
const int MAX = 100010;
const int MAX_1 = 1000100;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;
int T,N,M;
/*-------------------------------------------------------------------------------------------*/
double a[MAX];
/* ------------------------------------------------------------------------------------------*/
 
 
int main()
{
    //std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    cin >> N;
    for(int i = 0;i < N;i++)
    {
        cin >> a[i];
    }
    LL z = 0;
    LL f = 0;
    for(int i = 0;i < N;i++)
    {
        if(a[i] > 0)
            z +=(LL)a[i];
        else f +=(LL)a[i];
    }
    LL k = z + f;
    if(k > 0)
    {
        LL m = k;
        for(int i = 0;i < N;i++)
        {
            double b = a[i];
            if(b > 0) cout << (int)b <<endl;
            else
            {
                if(m > 0 && ((b - (int)b) != 0))
                {
                    cout << (int)b - 1 <<endl;
                    m--;
                }
                else cout << (int)b <<endl;
            }
        }
    }
    else
    {
        LL m = -k;
        for(int i = 0;i < N;i++)
        {
            double b = a[i];
            if(b < 0) cout << (int)b <<endl;
            else
            {
                if(m > 0 && ((b - (int)b) != 0))
                {
                    cout << (int)b + 1 <<endl;
                    m--;
                }
                else cout << (int)b <<endl;
            }
        }
    }
}
 