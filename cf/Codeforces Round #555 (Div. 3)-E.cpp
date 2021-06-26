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

int a[MAX];
multiset<int> d;

/* ------------------------------------------------------------------------------------------*/


int main()
{
/* --------------------------------------------------------------------------------------*/
    cin >> N;
    for(int i = 0;i < N;++i)
    {
        cin >> a[i];
    }
    for(int i = 0;i < N;++i)
    {
        int x;
        cin >> x;
        d.insert(x);
    }
    multiset<int>::iterator it;
    for(int i = 0;i < N;++i)
    {
        auto it = d.lower_bound(N - a[i]);
        if(it == d.end()) it = d.begin();
        cout <<  (a[i] + *it) % N << " ";
        d.erase(it);
    }
    cout <<"\n";
    return 0;
}