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
const int MAX = 100010;
const int MAX_1 = 55;
const int INF = 0xfffffff;//268435455,2e8;
const double EPS = 0.0000001;
const int MOD = 10000007;
int T,N,M;


/*-------------------------------------------------------------------------------------------*/

/* ------------------------------------------------------------------------------------------*/


int main()
{
    //std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    cin >> N >> M;
    int k;
    if(N % 2) k = N/2+1;
    else k = N / 2;
    if(M == 1 || M == 0)
    {
        cout << 1 << "\n";
        return 0;
    }
    if(M == k)
    {
        if(N % 2) cout << k-1 << "\n";
        else cout << k << "\n";
    }
    else if(M < k)
    {
        cout << M << "\n";
    }
    else
    {
        cout << N - M << "\n";
    }
    return 0;
}