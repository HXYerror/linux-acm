
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
const int MAX = 200050;//100000
const int MAX_1 = 15;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;//998244353;
const double PI = acos(-1);
LL T,N,M,K;
/*-------------------------------------------------------------------------------------------*/
int a[MAX];
int reduce[MAX];
int flag[MAX];
int dp[MAX];
vector<int> pay;
/* ------------------------------------------------------------------------------------------*/
 
void find_max()
{
    int tempmax;
    for(int i = pay.size()-1;i >= 0;i--)
    {
        dp[i] = max(dp[i+1],pay[i]);
    }
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* -----------------------------------------------------------------------------------------*/
    cin >> N;
    for(int i = 1;i <= N;i++)
    {
        cin >> a[i];
    }
    cin >> M;
    int sign,pos,x;
    vector<int> change;
    while(M--)
    {
        cin >> sign;
        if(sign == 1)
        {
            cin >> pos >> x;
            reduce[pos] = x;
            change.push_back(pos);
        }
        else
        {
            cin >> x;
            for(int i = 0;i < change.size();i++)
            {
                int p = change[i];
                flag[p] = pay.size()+1;
                a[p] = reduce[p];
                a[p] = max(a[p],x);
            }
            change.clear();
            pay.push_back(x);
        }
    }
    for(int i = 0;i < change.size();i++)
    {
        int p = change[i];
        flag[p] = pay.size()+1;
        a[p] = reduce[p];
    }
    find_max();
    for(int i = 1;i <= N;i++)
    {
        cout << max(a[i],dp[flag[i]]);
        if(i != N) cout << " ";
    }
    return 0;
}