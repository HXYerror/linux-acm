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
const int MAX = 2000;//100000
const int MAX_1 = 2;
const int MAX_2 = 1000010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;//998244353;
const double PI = acos(-1);
LL T,N,M,K;
/*-------------------------------------------------------------------------------------------*/
 
/* ------------------------------------------------------------------------------------------*/
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* -----------------------------------------------------------------------------------------*/
    cin >> T;
    while(T--)
    {
        cin >> N >> M >> K;
        LL bag = M;
        LL h = 0;
        LL flag = 1;
        cin >> h;
        LL x;
        for(int i = 1;i < N;i++)
        {
            cin >> x;
            if(!flag) continue;
            LL m;
            if(h >= x)
            {
                m = h - x;
                bag = bag + m + min(K,x);
            }
            else
            {
                m = x - h;
                if(m >= K)
                {
                    bag -= m-K;
                }
                else bag = bag + min(K - m,h);
            }
            if(bag < 0)
            {
                flag = 0;
            }
            h = x;
            //cout << bag <<endl;
        }
        if(flag) cout << "YES" <<endl;
        else cout << "NO" <<endl;
    }
    return 0;
}