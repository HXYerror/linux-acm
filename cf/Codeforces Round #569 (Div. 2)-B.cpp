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
const int MAX = 200050;//100000
const int MAX_1 = 15;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;//998244353;
const double PI = acos(-1);
LL T,N,M,K;
/*-------------------------------------------------------------------------------------------*/
int a[MAX];
/* ------------------------------------------------------------------------------------------*/
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* -----------------------------------------------------------------------------------------*/
    cin >> N;
    int fmin = INF;
    int fminpos;
    for(int i = 0;i < N;i++)
    {
        cin >> a[i];
        if(a[i] >= 0) a[i] = -a[i] - 1;
        if(a[i] < fmin)
        {
            fmin = a[i];
            fminpos = i;
        }
    }
    if(N % 2)
    {
        for(int i = 0;i < N;i++)
        {
            if(i == fminpos)
            {
                cout << -a[i] - 1;
            }
            else cout << a[i];
            if(i != N-1) cout << " ";
        }
    }
    else
    {
        for(int i = 0;i < N;i++)
        {
            cout << a[i];
            if(i != N-1) cout << " ";
        }
    }
 
    return 0;
}