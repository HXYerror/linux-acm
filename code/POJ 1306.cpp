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
const int MAX = 102;
const int INF = 0xfffffff;//268435455,2e8;
const double EPS = 0.0000001;
const int MOD = 100;
int T,N,M;

//std::ios::sync_with_stdio(false);
/*-------------------------------------------------------------------------------------------*/
LL c[MAX][MAX];
/* ------------------------------------------------------------------------------------------*/


int main()
{
    for(int i = 1;i <MAX ;i++)
    {
        c[i][1] = i;
        for(int j = 2;j <= i;j++)
        {
            c[i][j] = c[i-1][j-1]+c[i-1][j];
        }
    }
    while(cin >> N >> M && (M || N))
    {
        cout <<N << " things taken " << M <<" at a time is " << c[N][M] << " exactly.\n";
        //100 things taken 30 at a time is -4938587152604057488 exactly.超过LL
    }
    return 0;

}
