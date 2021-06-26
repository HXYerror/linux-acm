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
int T,N,M,K;
/*-------------------------------------------------------------------------------------------*/
 
/* ------------------------------------------------------------------------------------------*/
 
int main()
{
    //std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* -----------------------------------------------------------------------------------------*/
    scanf("%d%d",&N,&M);
    int j = N;
    int r;
    for(int i = 1;i <= j;i++,j--)
    {
        if(j == i)
        {
            r = M;
            for(int l = 1;l <= r;l++,r--)
            {
                if(l == r) printf("%d %d\n",i,r);
                else
                {
                    printf("%d %d\n",i,l);
                    printf("%d %d\n",i,r);
                }
 
            }
        }
        else
        {
            r = M;
            for(int l = 1;l <= M;l++,r--)
            {
                printf("%d %d\n",i,l);
                printf("%d %d\n",j,r);
            }
        }
 
    }
    return 0;
}