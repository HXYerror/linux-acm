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
 
int intere(int n)
{
    if(n < 10)
    {
        return n;
    }
    if(n >= 10 && n <= 99)
    {
        return (n/10) + n % 10;
    }
    if(n >= 100 && n <= 999)
    {
        return n/100 + (n-(n/100)*100)/10 +(n-(n/100)*100)%10;
    }
    return 0;
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    cin >> N;
    for(int i = N;i <= 2000;i++)
    {
        int k = intere(i);
        if(i >= 1000)
        {
            cout << 1003 << endl;
            break;
        }
        if(k % 4 == 0)
        {
            cout << i <<endl;
            break;
        }
    }
    return 0;
}