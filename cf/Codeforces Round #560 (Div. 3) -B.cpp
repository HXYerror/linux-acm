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
const int MAX_1 = 300010;
const int INF = 0x3f3f3f3f;//1061109567,1e9;
const double EPS = 0.0000001;
const int MOD = 10000;
int T,N,M;


/*-------------------------------------------------------------------------------------------*/

multiset<int>a;
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
    for(int i = 0;i < N;i++)
    {
        int x;
        cin >> x;
        a.insert(x);
    }
    int ans = 1;
    while(1)
    {
        auto it = a.lower_bound(ans);
        //cout << *it <<endl;
        if(it == a.end())
        {
            cout << ans-1 <<endl;
            break;
        }
        else
        {
            ans++;
            a.erase(it);
        }
    }
    return 0;
}