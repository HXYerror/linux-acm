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
const int MAX = 50010;//100000
const int MAX_1 = 2010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;
const double PI = acos(-1);
LL T,N,M;
/*-------------------------------------------------------------------------------------------*/

/* ------------------------------------------------------------------------------------------*/

void mycase(int n)
{
    cout << "Case #" << n <<": ";
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    //alice 1
    cin >> T;
    int CNT = 0;
    while(T--)
    {
        CNT++;
        string str;
        cin >> str;
        map<char,int> a;
        int ans = INF;
        for(int i = 0;i <str.size();i++)
        {
            if(a.find(str[i]) != a.end())
            {
                ans = min(ans,i - a[str[i]]);
                a[str[i]] = i;
            }
            else a[str[i]] = i;
        }
        mycase(CNT);
        if(ans < INF) cout << ans <<endl;
        else cout << -1 <<endl;
    }
    return 0;
}