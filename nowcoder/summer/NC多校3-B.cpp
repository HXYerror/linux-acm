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
const int MAX = 200010;//100000
const int MAX_1 = 100000;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;//998244353;
const double PI = acos(-1);
LL T,N,M;
/*-------------------------------------------------------------------------------------------*/
int sum[MAX];
vector<int> flag[MAX];
/* ------------------------------------------------------------------------------------------*/
 
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    cin >> N;
    char c;
    int ans = 0;
    int cnt0,cnt1;
    cnt0 = cnt1 = 0;
    for(int i = 0;i < N;i++)
    {
        cin >> c;
        if(c == '0')
        {
            sum[i] = sum[i-1]- 1;
            cnt0++;
            flag[sum[i]+MAX_1].push_back(i);
        }
        else
        {
            cnt1++;
            sum[i] = sum[i-1] + 1;
            flag[sum[i]+MAX_1].push_back(i);
        }
 
    }
    if(cnt0 == N || cnt1 == N)
    {
        cout << "0" << " 0" <<endl;
        return 0;
    }
    for(int i = N-1;i >=0;i--)
    {
        int n;
        if(sum[i] == 0)
        {
            ans = max(ans,i+1);
            continue;
        }
        if(flag[sum[i]+MAX_1].size())
        {
            n = flag[sum[i]+MAX_1][0];
        }
        int m = i - n;
        ans = max(m,ans);
        if(ans == N) break;
    }
    cout << ans << " " << min(cnt0,cnt1)*2 <<endl;
    return 0;
}