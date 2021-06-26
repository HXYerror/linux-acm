#include<bits/stdc++.h>
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
#include <deque>
#include <utility>
#define LL long long
using namespace std;
const int MAX = 2000;//100000
const int MAX_1 = 2;
const int MAX_2 = 1000010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;//998244353;
const double PI = acos(-1);
LL T,N,M,K;
/*-------------------------------------------------------------------------------------------*/
    int c[20];
/* ------------------------------------------------------------------------------------------*/
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* -----------------------------------------------------------------------------------------*/
    cin >> N;
    string str;
    cin >> str;
 
    for(int i = 0;i < N;i++)
    {
        if(str[i] == 'L')
        {
            for(int i = 0;i < 10;i++)
            {
                if(c[i] == 0)
                {
                    c[i] = 1;
                    break;
                }
            }
        }
        else if(str[i] == 'R')
        {
            for(int i = 9;i >= 0;i--)
            {
                if(c[i] == 0)
                {
                    c[i] = 1;
                    break;
                }
            }
        }
        else c[str[i] - '0'] = 0;
    }
    for(int i = 0;i < 10;i++)
    {
        cout << c[i];
    }
    return 0;
}