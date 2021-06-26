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
const int MAX = 501000;
const int MAX_1 = 500000;
const int INF = 0xfffffff;//268435455,2e8;
const double EPS = 0.0000001;
const int MOD = 1000000007;
int T,N,M;

/*-------------------------------------------------------------------------------------------*/

int ans = 0;
int prime[MAX];
int visit[MAX];
int flag[MAX];
map<int,int> cnt;
/* ------------------------------------------------------------------------------------------*/

void Prime(int n)
{
    for(int i = 2;i <= n;i++)
    {
        if(!visit[i])
        {
            prime[++prime[0]] = i;
            flag[i] = 1;
        }
        for(int j = 1;j <= prime[0] && i*prime[j] <= n;j++)
        {
            visit[i*prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
/* --------------------------------------------------------------------------------------*/
    Prime(MAX_1);
    cin >> T;
    while(T--)
    {
        cin >> N;
        M = N;
        ans = 1;
        cnt.clear();
        if(flag[N])
        {
            cout << 1 << "\n";
            continue;
        }
        while(N != 1)
        {
            for(int i = 1;i < prime[0];i++)
            {
                if(flag[N])
                {
                    cnt[N]++;
                    N=1;
                    break;
                }
                if(N % prime[i] == 0)
                {
                    cnt[prime[i]]++;
                    N /= prime[i];
                    break;
                }
            }
        }
        map<int,int>::iterator it;
        for(it = cnt.begin();it != cnt.end();it++)
        {
            int k = 1;
            for(int i = 0;i <= it->second;i++)
            {
                k *= it->first;
            }
            ans *= (k-1) / (it->first -1);
            //cout << it->first << " " << it->second << endl;
        }
        cout << ans - M << "\n";
    }
    return 0;
}
