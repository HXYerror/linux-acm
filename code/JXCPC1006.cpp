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
const int MAX = 1010;//100000
const int MAX_1 = 100010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;
const double PI = acos(-1);
LL T,N,M;
/*-------------------------------------------------------------------------------------------*/
map<char,int> a;
/* ------------------------------------------------------------------------------------------*/

int gcd(int a,int b)
{
    return a % b ? gcd(b,a % b) : b;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    while(cin >> N)
    {
        char c;
        a.clear();
        for(int i = 0;i < N;i++)
        {
            cin >> c;
            a[c]++;
        }
        int anss,ansm;
        if(a.size() < 4)
        {
            cout << "0/1" <<endl;
        }
        else
        {
            anss = a['a'] * a['v'] * a['i'] * a['n'];
            ansm = N * N * N * N;
            int k =gcd(anss,ansm);
            cout << anss / k << "/" << ansm / k <<endl;
        }

    }

    return 0;
}