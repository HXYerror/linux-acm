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
const int MAX = 200010;//100000
const int MAX_1 = 2010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 10;//998244353;
LL T,N,M;
/*-------------------------------------------------------------------------------------------*/
vector<LL> a;
/* ------------------------------------------------------------------------------------------*/
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    LL k;
    cin >> N >> M >> k;
    LL x;
    for(int i = 0;i < M;i++)
    {
        cin >> x;
        a.push_back(x);
    }
    LL ans = 0;
    LL pianyi = 0;
    LL page = k;
    for(int i = 0;i < M;i++)
    {
        LL n = (a[i] - pianyi) / k;
        if((a[i] - pianyi) % k == 0)
        {
            pianyi++;
            ans++;
        }
        else
        {
            page = (n+1)*k;
            int j =i+1;
            for(;j < M;j++)
            {
                if((a[j] - pianyi) > page)
                    break;
            }
            ans++;
            pianyi += j - i;
            i = j-1;
        }
 
    }
    cout << ans <<endl;
 
    return 0;
}