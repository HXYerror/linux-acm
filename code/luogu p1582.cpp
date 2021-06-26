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
const int MOD = 998244353;
const double PI = acos(-1);
LL T,N,M;
/*-------------------------------------------------------------------------------------------*/
LL sq2[35];
/* ------------------------------------------------------------------------------------------*/


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    LL n = 1;
    for(int i = 0;i < 35;i++)
    {
        sq2[i] = n << i;
    }
    cin >> N >> M;
    int ans = 0;
    int mi = INF;
    while(M && N)
    {
        for(int i = 0;i < 35;i++)
        {
            if(N < sq2[i])
            {
                N -= sq2[i-1];
                M--;
                mi = min(mi,i-1);
                //cout << i-1 <<endl;
                break;
            }
        }
    }
    if(N)
    {
        ans += sq2[mi] - N;
    }
    cout << ans <<endl;
    return 0;
}