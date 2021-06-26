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
const int MAX = 2*131072;//100000
const int MAX_1 = 505;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;
int T,N,M;
/*-------------------------------------------------------------------------------------------*/

/* ------------------------------------------------------------------------------------------*/

int gcd(int a,int b)
{
    return a % b == 0 ? b : gcd(b,a%b);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    cin >> T;
    for(int i = 1;i <= T;i++)
    {
        int k;
        cin >> k >> N >> M;
        int n = gcd(N,M);
        int m = (k / n);
        cout << "Case #" << i << ": ";
        if(m % 2 == 0) cout << "Iaka" <<endl;
        else cout << "Yuwgna" <<endl;
    }
    return 0;
}