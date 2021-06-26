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
const int MAX = 100;//100000
const LL MAX_1 = 100;
const int MAX_2 = 1000010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 1000000007;//998244353;
const double PI = acos(-1);
LL T,N,M,K;
 
/*-------------------------------------------------------------------------------------------*/
LL a[MAX];
/* ------------------------------------------------------------------------------------------*/
void mycout(int x,int y,int p,int q)
{
    int j = 1;
    while(j < p+1)
    {
        int n = x&1;
        cout << n ;
        x >>= 1;
        j++;
 
    }
    j = p+1;
    while(j < N+1)
    {
        int n = y&1;
        cout << n ;
        y >>= 1;
        j++;
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
    cin >> N >> M;
    for(int i = 1;i <= N;i++)
    {
        cin >> a[i];
    }
    map<LL,int> left;
    int n = N / 2;
    int m = N - n;
    int r = 1 << n;
    left[0] = 0;
    for(int i = 1;i < r;i++)
    {
        int j = i;
        LL sum = 0;
        int p = 1;
        while(p < n+1)
        {
            int x = j&1;
            if(x) sum += a[p];
            p++;
            j >>= 1;
        }
        left[sum] = i;
    }
    int l = 1 << m;
    for(int i = 1;i < l;i++)
    {
        int j = i;
        LL sum = 0;
        int p = n+1;
        while(p < N+1)
        {
            int x = j&1;
            if(x) sum += a[p];
            p++;
            j >>= 1;
        }
        auto it = left.find(M - sum);
        if(it != left.end())
        {
            mycout(it->second,i,n,m);
            //cout << it->first << " " << sum << endl;
            break;
        }
    }
    return 0;
}