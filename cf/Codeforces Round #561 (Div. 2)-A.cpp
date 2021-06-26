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
const int MAX = 2000010;
const int MAX_1 = 1000100;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;
int T,N,M;


/*-------------------------------------------------------------------------------------------*/

int flag[30];
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
    string s;
    for(int i = 0;i < N;i++)
    {
        cin >> s;
        flag[s[0] - 'a']++;
    }
    int ans = 0;
    for(int i = 0;i < 30;i++)
    {
        if(!flag[i]) continue;
        else if(flag[i] == 1 || flag[i] == 2) continue;
        else
        {
            if(flag[i] % 2)
            {
                int k = flag[i] / 2;
                if(k == 1)
                {
                    ans += 1;
                }
                else
                {
                    if(k == 2)
                    {
                        ans += 4;
                    }
                    else
                    {
                        ans += (k*(k-1)) / 2;
                        ans += (k*(k+1)) / 2;
                    }
                }
            }
            else
            {
                int k = flag[i] / 2;
                if(k == 2)
                {
                    ans+=2;
                }
                else
                {
                    ans += k*(k-1);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}