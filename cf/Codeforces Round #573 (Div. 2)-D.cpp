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
const int MAX = 100010;//100000
const int MAX_1 = 2010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;
const double PI = acos(-1);
LL T,N,M;
/*-------------------------------------------------------------------------------------------*/
map<int,int> a;
vector<int> b;
/* ------------------------------------------------------------------------------------------*/

int mycoutans(bool flag)
{
    if(flag) cout << "cslnb" <<endl;
    else cout << "sjfnb" << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    cin >> N;
    int x;
    for(int i = 0;i < N;i++)
    {
        cin >>x;
        a[x]++;
        b.push_back(x);
    }
    if(a.find(0) != a.end())
    {
        if(a[0] > 1)
        {
            mycoutans(1);
            return 0;
        }
    }
    int cnt = 0;
    for(auto it = a.begin();it != a.end();it++)
    {
        if(it->second > 2)
        {
            mycoutans(1);
            return 0;
        }
        if(it -> second > 1)
        {
            cnt++;
            if(cnt == 2)
            {
                mycoutans(1);
                return 0;
            }
            if(a.find(it->first - 1) != a.end())
            {
                mycoutans(1);
                return 0;
            }
        }
    }
    LL sum = 0;
    LL cmt = 0;
    sort(b.begin(),b.end());
    for(int i = 0;i < N;i++)
    {
        sum += b[i] + cmt;
        cmt++;
    }
    if(sum % 2 == 0) mycoutans(1);
    else mycoutans(0);
    return 0;
}
