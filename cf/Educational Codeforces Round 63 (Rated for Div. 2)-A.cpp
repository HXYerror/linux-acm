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
const int MAX = 100100;
const int INF = -0xfffffff;//268435455,2e8;
const double EPS = 0.0000001;
const int MOD = 1000000007;
int T,N,M;


/*-------------------------------------------------------------------------------------------*/
char c[MAX];
/* ------------------------------------------------------------------------------------------*/

int main()
{
    //std::ios::sync_with_stdio(false);
    cin >>N;
    cin >> c;
    int cnt = 0;
    int cntx = 0;
    int n = (N- 11);
    for(int i = 0;i <= n;i++)
    {
        if(c[i] == '8')
        {
            cnt++;
        }
        else cntx++;
    }
    if(cnt - cntx > 0)
    {
        cout <<"YES";
    }
    else
        cout << "NO";
    return 0;
}