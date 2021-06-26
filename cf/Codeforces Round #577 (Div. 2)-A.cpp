
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
const int MAX = 10010;//100000
const int MAX_1 = 2;
const int MAX_2 = 1000010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;//998244353;
const double PI = acos(-1);
LL T,N,M,K;
/*-------------------------------------------------------------------------------------------*/
int b[MAX];
/* ------------------------------------------------------------------------------------------*/
 
 
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* -----------------------------------------------------------------------------------------*/
    cin >> N >> M;
    string s[MAX];
    for(int i = 0;i < N;i++)
    {
        cin >> s[i];
    }
    for(int i = 0;i < M;i++)
    {
        cin >> b[i];
    }
    int ans = 0;
    for(int i = 0;i < M;i++)
    {
        map<char,int> a;
        for(int j = 0;j < N;j++)
        {
            a[s[j][i]]++;
        }
        int maxcnt= 0;
        for(auto it= a.begin();it != a.end();it++)
        {
            maxcnt = max(maxcnt,it->second);
        }
        ans += maxcnt * b[i];
    }
    cout << ans <<endl;
    return 0;
}