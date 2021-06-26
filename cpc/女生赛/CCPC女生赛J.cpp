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
const double PI = acos(-1);
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
    while(cin >> N)
    {
        double angle = (2*PI) / N;
        double angsin = sin(angle);
        double s = 0;
        s += (N-1) * angsin * 0.5;
        angsin = sin(0.5 * angle);
        s +=  angsin;
        cout << fixed << setprecision(6) << s <<endl;
    }
    return 0;
}