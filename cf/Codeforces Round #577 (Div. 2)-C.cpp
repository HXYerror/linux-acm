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
const int MAX = 10010;//100000
const int MAX_1 = 2;
const int MAX_2 = 1000010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;//998244353;
const double PI = acos(-1);
LL T,N,M,K;
/*-------------------------------------------------------------------------------------------*/
vector<LL> a;
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
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    int mid = N / 2;
    LL cnt = 1;
    for(int i = mid+1;i < N;i++)
    {
        LL n = cnt * (a[i] - a[mid]);
        if(n <= M)
        {
            a[mid] = a[i];
            cnt++;
            M -= n;
        }
        else
        {
            int k = M / cnt;
            a[mid] += k;
            M = 0;
            break;
        }
    }
    if(M)
    {
        int k = M / cnt;
        a[mid] += k;
        M = 0;
    }
    cout << a[mid] <<endl;
    return 0;
}