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
const int MAX = 25;//100000
const int MAX_1 = 100010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;
const double PI = acos(-1);
LL T,N,M;
/*-------------------------------------------------------------------------------------------*/
 
/* ------------------------------------------------------------------------------------------*/
 
LL gcd(LL a,LL b)
{
    return a%b ? gcd(b,a%b):b;
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    LL x,y,a,b;
    while(cin >> x >> a >> y>>b)
    {
        LL k = gcd(x,a);
        a = a/k;
        x = x/k;
        LL n = x / a;
        x -= n*a;
        k = gcd(y,b);
        b = b / k;
        y = y / k;
        LL m = y / b;
        int flag = 0;
        y -= m*b;
        if(n == m)
        {
            if(a == b && y == x)
            {
                flag = 1;
            }
            else if(a > b && y == x)
            {
                flag = 0;
            }
            else if(a < b && y == x)
            {
                flag = -1;
            }
            else if(a == b && y > x)
            {
                flag = 0;
            }
            else if(a == b && y < x)
            {
                flag = -1;
            }
            else if(a > b && y > x)
            {
                flag = 0;
            }
            else if(a < b && y < x)
            {
                flag = -1;
            }
            else
            {
                LL p,q;
                while(1)
                {
                    p = x / a;
                    q = y / b;
                    if(p > q)
                    {
                        flag = -1;
                        break;
                    }
                    else if (q > p)
                    {
                        flag = 0;
                        break;
                    }
                    x = (x % a)*10;
                    y = (y % b)*10;
                }
            }
 
        }
        else
        {
            if(n > m) flag = -1;
            else flag = 0;
        }
        if(flag == 0) cout << "<"<<endl;
        else if(flag == 1)cout << "=" <<endl;
        else cout <<">"<<endl;
    }
 
    return 0;
}