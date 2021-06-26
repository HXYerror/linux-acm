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
const int MAX = 501000;
const int MAX_1 = 500000;
const int INF = 0xfffffff;//268435455,2e8;
const double EPS = 0.0000001;
const int MOD = 10000007;
int T,N,M;

/*-------------------------------------------------------------------------------------------*/

set<int> a;
/* ------------------------------------------------------------------------------------------*/


int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
/* --------------------------------------------------------------------------------------*/
    cin >> N;
    a.insert(N);
    int flag = 0;
    while(1)
    {
        N++;

        while(N % 10 == 0)
        {
            N /= 10;
        }
        a.insert(N);
        //1cout << N <<endl;
        if(flag && N == 1)
        {
            break;
        }
        if(N == 1) flag = 1;
    }
    cout << a.size() << "\n";
    return 0;
}