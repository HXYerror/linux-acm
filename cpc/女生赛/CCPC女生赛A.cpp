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
const int MOD = 998244353;
int T,N,M;
/*-------------------------------------------------------------------------------------------*/

/* ------------------------------------------------------------------------------------------*/

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    cin >> N;
    double ans = 0;
    int sum = 0;
    int x;
    for(int i = 0;i < N;i++)
    {
        cin >> x;
        if(sum < 100 || sum >= 400) ans += (double)x;
        else if(sum >= 100 && sum < 150) ans += x * 0.8;
        else if(sum >= 150 && sum < 400) ans += x * 0.5;
        sum += x;
    }
    cout << fixed <<setprecision(2) << ans <<endl;
    return 0;
}