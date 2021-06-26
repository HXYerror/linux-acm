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
const int MAX = 201000;
const int MAX_1 = 500000;
const int INF = 0xfffffff;//268435455,2e8;
const double EPS = 0.0000001;
const int MOD = 10000007;
int T,N,M;

/*-------------------------------------------------------------------------------------------*/

char a[15];
char c[MAX];
/* ------------------------------------------------------------------------------------------*/


int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
/* --------------------------------------------------------------------------------------*/
    cin >> N;
    cin >> c;
    a[0] = '0';
    for(int i = 1;i < 10;i++)
    {
        cin >> a[i];
    }
    for(int i = 0;i < N;i++)
    {
        if(a[c[i] - 48] > c[i])
        {
            for(int j = i;j < N;j++)
            {
                if(a[c[j] - 48] >= c[j] )
                {
                    c[j] = a[c[j] - 48];
                }
                else break;
            }
            break;
        }
    }
    cout << c << "\n";
    return 0;
}