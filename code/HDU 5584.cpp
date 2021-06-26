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
const int MOD = 998244353;
const double PI = acos(-1);
LL T,N,M;
/*-------------------------------------------------------------------------------------------*/

/* ------------------------------------------------------------------------------------------*/
void mycase(int n)
{
    cout << "Case #" << n <<": ";
}
LL gcd(LL x,LL y)
{
    return x%y ? gcd(y,x%y) : y;
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    cin >> T;
    int CNT = 0;
    LL x,y;
    while(T--)
    {
        CNT++;
        cin >> x >> y;
        int ans = 1;
        LL k = gcd(x,y);
        if(x < y)
        {
            x = x + y;
            y = x - y;
            x = x - y;
        }
        while(x % ((y/k+1)*k) == 0 )
        {

            x = x / (y/k+1);
            ans++;
            if(x < y)
            {
                x = x + y;
                y = x - y;
                x = x - y;
            }
        }
        mycase(CNT);
        cout << ans <<"\n";
    }
    return 0;
}
