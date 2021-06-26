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
int a[MAX];
/* ------------------------------------------------------------------------------------------*/
 
void mycase(int x,int ans)
{
    cout << "Case #" << x <<": "<<ans <<endl;
}
 
bool check(int n)
{
    int b[MAX];
    fill(b,b+MAX,0);
    int cnt = 0;
    for(int j = 0;j < M;j++)
    {
        int m = n;
        for(int i = N-1;i >= 0;i--)
        {
            if(a[i] <= m && !b[i])
            {
                m -= a[i];
                b[i] = 1;
                cnt++;
            }
        }
    }
    return cnt == N;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* -----------------------------------------------------------------------------------------*/
    cin >> T;
    int cnt = 0;
    while(T--)
    {
        cnt++;
        cin >> N >> M;
        int sum = 0;
        int maxv = 0;
        for(int i = 0;i < N;i++)
        {
            cin >> a[i];
            sum += a[i];
            maxv = max(maxv,a[i]);
        }
        int minv = ceil((sum * 1.0)/ M);
        minv = max(minv,maxv);
        sort(a,a+N);
        int ans;
        for(int i = minv;;i++)
        {
            if(check(i))
            {
                ans = i;
                break;
            }
        }
        mycase(cnt,ans);
    }
    return 0;
}