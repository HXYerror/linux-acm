
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
const int MOD = 10;//998244353;
int T,N,M;
/*-------------------------------------------------------------------------------------------*/
map<int,int> b;
 
/* ------------------------------------------------------------------------------------------*/
int power4(int n,int p,int k)
{
    LL m = (1LL * n * n) % p;
    m = (m * n) % p;
    m = (m * n) % p;
    m = m - (1LL * k * n) % p;
    m = m%p;
    if(m < 0) m += p;
    return (int)m;
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    int p,k;
    cin >> N >> p >> k;
    int m;
    LL ans = 0;
    for(int i = 0;i < N;i++)
    {
        cin >> m;
        int n =  power4(m,p,k);
        if(b.find(n) != b.end())
        {
            ans += (int)b[n];
            b[n]++;
        }
        else b[n] = 1;
    }
    cout << ans << endl;
    return 0;
}