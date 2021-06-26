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
 
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    string a,b;
    cin >> a >> b;
    int cntb = 0;
    int cnta = 0;
    int lb = b.size();
    for(int i = 0;i <lb;i++)
    {
        if(b[i] == '1') cntb++;
        if(a[i] == '1') cnta++;
    }
    int ans = 0;
    if(cntb % 2 == cnta %2) ans++;
    for(int i = lb;i < a.size();i++)
    {
        if(a[i - lb] == '1') cnta--;
        if(a[i] == '1') cnta++;
        if(cntb % 2 == cnta %2) ans++;
    }
    cout << ans <<endl;
    return 0;
}