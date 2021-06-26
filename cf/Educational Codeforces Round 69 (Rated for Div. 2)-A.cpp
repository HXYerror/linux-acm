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
const int MAX = 100020;//100000
const int MAX_1 = 70;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;//998244353;
const double PI = acos(-1);
int T,N,M;
/*-------------------------------------------------------------------------------------------*/
 
/* ------------------------------------------------------------------------------------------*/
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    cin >> T;
    while(T--)
    {
        cin >> N;
        int x;
        int max1,max2;
        max1 = max2 = 0;
        for(int i = 0;i < N;i++)
        {
            cin >> x;
            if(x > max1)
            {
                max2 = max1;
                max1 = x;
            }
            else if(x > max2)
            {
                max2 = x;
            }
        }
        cout << min(min(max1,max2)-1,N-2) <<endl;
    }
 
    return 0;
}
