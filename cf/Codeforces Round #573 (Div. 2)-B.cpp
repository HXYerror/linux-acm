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
    char c[4];
    int a[4];
    string s;
    map<string,int> b;
    for(int i = 1;i < 4;i++)
    {
        cin >> s;
        b[s]++;
        a[i] = (int)s[0];
        c[i] = s[1];
    }
    if(b.size() == 1)
    {
        cout << 0 <<endl;
    }
    else if(b.size() == 2)
    {
        cout << 1 <<endl;
    }
    else
    {
        if(c[1] == c[2])
        {
            if(c[2] == c[3])
            {
                sort(a+1,a+4);
                if(a[1] + 1 == a[2] && a[3]-1 == a[2])
                {
                    cout << 0 <<endl;
                }
                else if(abs(a[1]-a[2]) == 1|| abs(a[1]-a[3]) == 1 || abs(a[3]-a[2]) == 1 || abs(a[1]-a[2]) == 2|| abs(a[1]-a[3]) == 2 || abs(a[3]-a[2]) == 2)
                {
                   cout << 1 <<endl;
                }
                else cout << 2 <<endl;
 
            }
            else
            {
                if(abs(a[1]-a[2]) == 1||abs(a[1]-a[2]) == 2)
                    cout << 1 <<endl;
                else cout << 2 <<endl;
            }
        }
        else
        {
            if(c[2] == c[3])
            {
                if(abs(a[2]-a[3]) == 1||abs(a[2]-a[3]) == 2)
                    cout << 1 <<endl;
                else cout << 2 <<endl;
            }
            else
            {
                if(c[1] == c[3])
                {
                    if(abs(a[1]-a[3]) == 1||abs(a[1]-a[3]) == 2)
                        cout << 1 <<endl;
                    else cout << 2 <<endl;
                }
                else
                {
                    cout << 2 <<endl;
                }
            }
        }
    }
    return 0;
}