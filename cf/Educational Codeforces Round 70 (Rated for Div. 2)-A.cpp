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
const int MAX_1 = 2;
const int MAX_2 = 1000010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;//998244353;
const double PI = acos(-1);
LL T,N,M,K;
/*-------------------------------------------------------------------------------------------*/
 
/* ------------------------------------------------------------------------------------------*/
 
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* -----------------------------------------------------------------------------------------*/
    cin >> T;
    string s1,s2;
    while(T--)
    {
        cin >> s1 >> s2;
        int l1 = s1.size();
        int l2 = s2.size();
        int cnt = 0;
        for(int j = l2-1;j >= 0;j--)
        {
            if(s2[j] == '1') break;
            cnt++;
        }
        int i;
        int cmt = 0;
        for(i = l1 - 1 - cnt;i >= 0;i--)
        {
            if(s1[i] == '1') break;
            cmt++;
        }
 
        cout << cmt <<endl;
 
    }
    return 0;
}