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
const int MAX = 300010;//100000
const int MAX_1 = 100010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;//998244353;
const double PI = acos(-1);
LL T,N,M;
/*-------------------------------------------------------------------------------------------*/
string rgb = "RGB";
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
    int cnt;
    while(T--)
    {
        string str;
        cin >> N >> M;
        cin >> str;
        int ans = INF;
        for(int i = 0;i < N;i++)
        {
            int cnt;
            if(i + M > N) break;
            for(int k = 0;k < 3;k++)
            {
                cnt = 0;
                for(int j = 0;j < M;j++)
                {
                    if(str[j+i] != rgb[(k+j) % 3]) cnt++;
                }
                ans = min(cnt,ans);
            }
            if(ans == 0) break;
        }
        cout << ans <<endl;
    }
    return 0;
}