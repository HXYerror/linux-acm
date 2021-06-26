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
const int MAX = 2000010;
const int MAX_1 = 1000100;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;
int T,N,M;


/*-------------------------------------------------------------------------------------------*/

char vow[] = {'a','a','e','i','o','u','a','e','i','o','u'};
/* ------------------------------------------------------------------------------------------*/



int main()
{
    //std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    cin >> N;
    int n,m;
    n = m = 0;
    if(N < 25)
    {
        cout << "-1" <<endl;
        return 0;
    }
    for(int i = 5;i*i <= N;i++)
    {
        if(N % i == 0)
        {
            n = i;
            m = N / i;
            break;
        }
    }
    if(n == 0)
    {
        cout << "-1" <<endl;
    }
    else
    {
        for(int i = 1;i <= n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                if(j < 5)
                {
                    int k = i%6;
                    if(!k) k++;
                    cout << vow[k+j];
                }
                else
                {
                    cout << vow[i % 6];
                }
            }
        }
    }
    return 0;
}