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
const int MAX = 350;
const int MAX_1 = 1000100;
const int INF = 0x3f3f3f3f;//1061109567,1e9;
const double EPS = 0.0000001;
const int MOD = 10000;
int T,N,M;


/*-------------------------------------------------------------------------------------------*/

int a[MAX];
map<int,int> p;
int prime[MAX_1];
int visit[MAX_1];
int flag[MAX_1];
map<int,int> cnt;
/* ------------------------------------------------------------------------------------------*/

int gcd(int a,int b)
{
    return a % b == 0 ? b : gcd(b,a%b);
}

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
    //std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    cin >> T;
    Prime(MAX_1);
    while(T--)
    {
        cin >> N;
        int ma = 0;
        p.clear();
        cnt.clear();
        for(int i = 0;i < N;i++)
        {
            cin >> a[i];
            ma = max(a[i],ma);
            p[a[i]]  = 1;
        }
        if(N == 1)
        {
            if(flag[a[0]]) cout << (LL)a[0] * a[0] << endl;
            else cout << "-1" <<endl;
            continue;
        }
        else
        {
            for(int i = 0;i < N;i++)
            {
                int k = a[i];
                map<int,int> cntt;
                while(k != 1)
                {
                    for(int i = 1;i < prime[0];i++)
                    {
                        if(flag[k])
                        {
                            cntt[k]++;
                            k=1;
                            break;
                        }
                        if(k % prime[i] == 0)
                        {
                            cntt[prime[i]]++;
                            k /= prime[i];
                            break;
                        }
                    }
                }

                map<int,int>::iterator it;
                for(it= cntt.begin();it!=cntt.end();it++)
                {
                    auto its = cnt.find(it->first);
                    if(its != cnt.end())
                    {
                        its->second = max(it->second,its->second);
                    }
                    else
                    {
                        cnt[it->first] = it->second;
                    }
                }
            }
            LL ans = 1;
            map<int,int>::iterator it;
            int cntx = 1;
            for(it = cnt.begin();it != cnt.end();it++)
            {
                cntx *= (it->second + 1);
                for(int i= 0;i < it->second;i++)
                {
                    ans *= it->first;
                }
            }
            //cout << cntx <<endl;

            if(cntx - 2 == N && p.find(ans) == p.end())
            {
                cout << ans << endl;
            }
            else if(cnt.size() == 1 && cntx - 1 == N )
            {
                it = cnt.begin();
                ans *= it->first;
                cout <<  ans << endl;
            }
            else
            {
                cout << "-1" <<endl;
            }
        }
    }
    return 0;
}