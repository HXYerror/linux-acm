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
    cin >> T;
    while(T--)
    {
        cin >> N >> M;
        int ma,mi;
        ma = 0;
        mi = INF;
        int x;
        for(int i = 0;i < N;i++)
        {
            cin >> x;
            ma = max(ma,x);
            mi = min(mi,x);
        }
        if(ma - M > mi + M)
        {
            cout << "-1" <<endl;
        }
        else
        {
            cout << mi+M <<endl;
        }
    }
    return 0;
}