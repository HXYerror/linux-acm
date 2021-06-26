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
const int MAX_1 = 55;
const int INF = 0xfffffff;//268435455,2e8;
const double EPS = 0.0000001;
const int MOD = 10000007;
int T,N,M;


/*-------------------------------------------------------------------------------------------*/
map<int,int> flag;
/* ------------------------------------------------------------------------------------------*/


int main()
{
    //std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    int ans = 0;
    int cnt = 0;
    cin >> N;
    for(int i = 1;i<=N;i++)
    {
        int x;
        cin >> x;
        if(!flag[x]) cnt++;
        flag[x]++;
        map<int,int> ::iterator it;
        if(i % cnt == 1)
        {
            int k = 0;
            int m = 0;
            for(it = flag.begin();it != flag.end();it++)
            {
                k = max(k,it->second);
            }
            for(it = flag.begin();it != flag.end();it++)
            {
                if(it -> second == k-1)
                {
                    m++;
                }
            }
            if(m==cnt-1) ans = i;
        }

        if(cnt >= 2 && (i-1) % (cnt-1) == 0)
        {
            int k = 0;
            for(it = flag.begin();it != flag.end();it++)
            {
                k = max(k,it->second);
            }
            int m = 0;
            for(it = flag.begin();it != flag.end();it++)
            {
                if(it->second == k)
                {
                    m++;
                }
            }
            if(k * m == i-1) ans = i;
        }

        if(cnt == i || cnt == 1)
            ans = i;
        if(cnt == 2)
        {
            for(it = flag.begin();it != flag.end();it++)
            {
                if(it->second == 1)
                {
                    ans = i;
                    break;
                }
            }
        }
    }

    cout << ans;
    return 0;
}
