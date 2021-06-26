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
const int MAX = 10;
const int INF = 0xfffffff;//268435455,2e8;
const double EPS = 0.0000001;
const int MOD = 100;
int T,N,M;

//std::ios::sync_with_stdio(false);
/*-------------------------------------------------------------------------------------------*/

/* ------------------------------------------------------------------------------------------*/



int main()
{
    LL a[5];
    for(int i = 0;i < 4;i++)
    {
        cin >> a[i];
    }
    sort(a,a+4);
    for(int i =0;i < 3;i++)
    {
        cout << a[3]-a[i];
        if(i !=  2) cout << " ";
    }
    return 0;

}