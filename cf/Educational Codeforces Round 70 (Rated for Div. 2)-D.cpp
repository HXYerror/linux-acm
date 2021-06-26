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
const int MAX = 10010;//100000
const int MAX_1 = 2;
const int MAX_2 = 1000010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;//998244353;
const double PI = acos(-1);
int T,N,M,K;
/*-------------------------------------------------------------------------------------------*/
vector<LL> b;
/* ------------------------------------------------------------------------------------------*/
 
 
int main()
{
    //std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* -----------------------------------------------------------------------------------------*/
    LL a;
    for(int i = 2;i < MAX;i++)
    {
        a = (i * (i-1)) / (LL)2;
        b.push_back(a);
        if(a > 50000) break;
    }
    scanf("%d",&T);
    while(T--)
    {
        vector<int> ansn;
        vector<int> ansm;
        scanf("%d",&N);
        for(int i = b.size()-1;i >= 0;i--)
        {
            if(b[i] > N) continue;
            else
            {
                if(i == 0)
                {
                    ansm.push_back(N);
                    ansn.push_back(i+2);
                    break;
                }
                int l = 1;
                int r = 10000;
                while(r > l)
                {
                    int mid = (l+r) / 2;
                    if(N / mid > 0) l = mid+1;
                    else r = mid - 1;
                }
                for(int j = (l+r) / 2;j >= 1;j--)
                {
                    if(b[i] * j <= N)
                    {
                        N -= b[i]*j;
                        ansm.push_back(j);
                        ansn.push_back(i+2);
                        break;
                    }
                }
            }
            if(N == 0) break;
        }
        int sum[MAX];
        fill(sum,sum+MAX,0);
        for(int i = ansn.size()-1;i >= 0;i--)
        {
            sum[i] = sum[i+1] + ansn[i];
        }
        for(int i = 0;i < ansn.size();i++)
        {
//cout << ansm[i] << " " << ansn[i] <<endl;
            for(int j = 1;j <= ansm[i];j++)
            {
                printf("1");
            }
            int n;
            if(i != ansn.size()-1) n = ansn[i] - ansn[i+1];
            else n = ansn[i];
            for(int j = 1;j <= n ;j++)
            {
                printf("3");
            }
        }
       printf("7\n");
    }
    return 0;
}