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
const int MAX = 100010;//100000
const int MAX_1 = 70;
const int INF = 100000;//0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;//998244353;
const double PI = acos(-1);
LL T,N,M;
/*-------------------------------------------------------------------------------------------*/
LL pow2[MAX_1];
/* ------------------------------------------------------------------------------------------*/
 
void mycout(LL a,LL b)
{
    cout << 2 << " " << b << " " << a <<endl;
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    pow2[0] = 1;
    for(int i = 1;i <= 62;i++)
    {
        pow2[i] = pow2[i-1]<<1;
    }
    cin >> T;
    while(T--)
    {
        cin >> N;
        if(N % 3 == 0)
        {
            cout << 1 << " " << N <<endl;
            continue;
        }
        M = N;
        int k,cnt = 0;
        vector<int> mod1,mod2;
        while(M)
        {
            k = M&1;
            M >>= 1;
            if(k)
            {
                if(cnt % 2)  mod2.push_back(cnt);
                else mod1.push_back(cnt);
            }
            cnt++;
        }
        if(N % 3 == 1)
        {
            if(mod1.size() > 1) mycout(N-pow2[mod1[0]],N-pow2[mod1[1]]);
            else if(mod1.size() < 1) mycout(N-pow2[mod2[0]]-pow2[mod2[1]],pow2[mod2[0]]+pow2[mod2[1]]+pow2[mod2[2]]);
            else mycout(N-pow2[mod1[0]],pow2[mod1[0]]+pow2[mod2[0]]);
        }
        else
        {
            if(mod2.size() >1) mycout(N-pow2[mod2[0]],N-pow2[mod2[1]]);
            else if(mod2.size() < 1) mycout(N-pow2[mod1[0]]-pow2[mod1[1]],pow2[mod1[0]]+pow2[mod1[1]]+pow2[mod1[2]]);
            else mycout(N-pow2[mod2[0]],pow2[mod2[0]]+pow2[mod1[0]]);
        }
    }
    return 0;
}