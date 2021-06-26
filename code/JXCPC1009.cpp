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

/* ------------------------------------------------------------------------------------------*/


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    string str;
    while(cin >> N)
    {

        double sum = 0;
        for(int i = 0;i < N;i++)
        {
            cin >> str;
            int l = str.size();
            if(str[l-1] > '4')
            {
                sum += 0.001 * (10 - (int)(str[l-1] - '0'));
            }
            else sum -= 0.001 * (int)(str[l-1] - '0');
        }
        cout << fixed << setprecision(3) << sum <<endl;
    }

    return 0;
}
