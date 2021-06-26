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
const int MAX = 400020;//100000
const int MAX_1 = 15;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;//998244353;
const double PI = acos(-1);
LL T,N,M,K;
/*-------------------------------------------------------------------------------------------*/
map<int,int> cnt;
set<int> num;
vector<int> a;
int sumcnt[MAX];
/* ------------------------------------------------------------------------------------------*/
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* -----------------------------------------------------------------------------------------*/
    cin >> N >> M;
    int x;
    for(int i = 0;i < N;i++)
    {
        cin >> x;
        num.insert(x);
        cnt[x]++;
    }
    M *= 8;
    if(N == 0)
    {
        cout << "0" <<endl;
        return 0;
    }
    int k = M / N;
    if(k > 30)
    {
        cout << 0 << endl;
        return 0;
    }
    K = 1<<k;
//cout << K <<endl;
    for(auto it = num.begin();it != num.end();it++)
    {
        a.push_back(*it);
    }
    int len = a.size();
    for(int i = len-1;i >= 0;i--)
    {
        sumcnt[i] = sumcnt[i+1] + cnt[a[i]];
    }
    int ans = INF,temp;
    if(num.size() <= K)
    {
        cout << 0 <<endl;
        return 0;
    }
    else
    {
        K = len - K;
        int sum = 0;
        int cntm = 0;
        temp = sumcnt[len - K];
        ans = min(ans,temp);
        for(int i = 0;i < len;i++)
        {
            if(cntm == K) break;
            cntm++;
            sum += cnt[a[i]];
            temp = sum;
            temp += sumcnt[len - K + cntm];
            ans = min(ans,temp);
        }
    }
    cout << ans <<endl;
    return 0;
}