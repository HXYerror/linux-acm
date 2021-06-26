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
const int MAX = 2510;
const int MAX_1 = 1000010;
const int INF = 0xfffffff;//268435455,2e8;
const double EPS = 0.0000001;
const int MOD = 10000007;
int T,N,M;


/*-------------------------------------------------------------------------------------------*/
int fish[MAX];
int r0[MAX];
int l0[MAX];
int h0[MAX];
int dpr[MAX];
int dpl[MAX];
/* ------------------------------------------------------------------------------------------*/


int main()
{
    //std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    cin >> N >> M;
    int ans = 0;
    for(int i = 1;i <= N;i++)
    {
        for(int j = 1;j <= M;j++)
        {
            cin >> fish[j];
            if(fish[j])
            {
                l0[j] = 0;
            }
            else
            {
                l0[j] = l0[j-1]+1;
            }
        }
        for(int j = M;j >= 1;j--)
        {
            if(fish[j])
            {
                r0[j] = 0;
            }
            else r0[j] = r0[j+1] + 1;
        }

        for(int j = 1;j <= M;j++)
        {
            if(fish[j]) dpr[j] = min(dpr[j+1]+1,min(h0[j]+1,r0[j+1]+1));
            else dpr[j] = 0;
        }
        for(int j = M;j >= 1;j--)
        {
            if(fish[j]) dpl[j] = min(dpl[j-1]+1,min(h0[j]+1,l0[j-1]+1));
            else dpl[j] = 0;
        }
        ans = max(ans,*max_element(dpl+1,dpl+M+1));
        ans = max(ans,*max_element(dpr+1,dpr+M+1));
        for(int j = 1;j <= M;j++)
        {
            if(fish[j])
            {
                h0[j] = 0;
            }
            else
            {
                h0[j] = h0[j]+1;
            }
        }
    }
    cout << ans <<"\n";
}
//        for(int j = 1;j <= M;j++)
//        {
//            cout << left << setw(3) << ddp[j];
//        }
//        cout <<endl;
