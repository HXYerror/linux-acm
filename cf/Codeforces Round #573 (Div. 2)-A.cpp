By HXYerror, contest: Codeforces Round #573 (Div. 2), problem: (A) Tokitsukaze and Enhancement, Accepted, #
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
    int n = N % 4;
    if(n == 0)
    {
        cout << 1 << " " <<'A' <<endl;
    }
    else if(n == 1)
    {
        cout << 0 << " " <<'A' <<endl;
    }
    else if(n == 2)
    {
        cout << 1 << " " <<'B' <<endl;
    }
    else
    {
        cout << 2 << " " <<'A' <<endl;
    }
    return 0;
}