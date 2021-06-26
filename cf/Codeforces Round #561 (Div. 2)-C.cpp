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
const int MAX = 200010;
const int MAX_1 = 1000100;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;
int T,N,M;


/*-------------------------------------------------------------------------------------------*/
vector<int> a;
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
    int x;
    for(int i = 0;i < N;i++)
    {
        cin >> x;
        if(x > 0) a.push_back(x);
        else if(x < 0) a.push_back(-x);
    }
    LL ans = 0;
    sort(a.begin(),a.end());
    for(int i = a.size()-1;i >= 1;i--)
    {
        auto y = lower_bound(a.begin(),a.end(),(a[i]+1)/2);
        int qaq = distance(a.begin(),y);
        ans += i - qaq;
        //cout << ans << " "<< (a[i]+1)/2 << (y - a.begin()) / sizeof(int) << endl;
    }
    cout << ans << endl;
    return 0;
}