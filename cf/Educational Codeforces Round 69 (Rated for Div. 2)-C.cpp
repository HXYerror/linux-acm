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
const int MAX = 300020;//100000
const int MAX_1 = 70;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;//998244353;
const double PI = acos(-1);
LL T,N,M;
/*-------------------------------------------------------------------------------------------*/
int a[MAX];
/* ------------------------------------------------------------------------------------------*/
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    cin >> N >> M;
    int sum = 0;
    multiset<int,greater<int>> a;
    int x,y;
    cin >> x;
    int n;
    for(int i = 1;i < N;i++)
    {
        cin >> y;
        n = y - x;
        sum += n;
        a.insert(n);
        x = y;
    }
    int cnt = 0;
    int add = 0;
    for(auto it = a.begin();;it++)
    {
        if(cnt == M-1) break;
        add += *it;
        cnt++;
    }
    cout << sum -add <<endl;
    return 0;
}