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
const int MAX = 1010;//100000
const int MAX_1 = 2010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;
const double PI = acos(-1);
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
    cin >> N >> M;//bushu,m留下多少
    LL sum =(N*(1+N))/2;
    LL s = sum - M;
    LL l = 0;
    LL r = N;
    LL mid;
    while(l <= r)
    {
        mid = (l+r)/2;
        LL cha = s - mid;
        LL su = (mid*(N+N-mid+1))/2;
        if(cha > su)
        {
            l = mid+1;
        }
        else if(su > cha)
        {
            r = mid-1;
        }
        else break;
        //cout << l<<" " << r << " "<<mid << " " << cha << " " << su <<endl;
    }
    cout << mid << endl;
    return 0;
}