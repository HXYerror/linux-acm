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
const int MAX_1 = 15;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;//998244353;
const double PI = acos(-1);
LL T,N,M,K;
/*-------------------------------------------------------------------------------------------*/
int a[MAX];
/* ------------------------------------------------------------------------------------------*/
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* -----------------------------------------------------------------------------------------*/
    int x,y;
    cin >> N >> x >> y;
    for(int i = 0;i < N;i++)
    {
        cin >> a[i];
    }
    for(int i = 0;i < N;i++)
    {
        int l,r;
        if(i - x >= 0) l = i-x;
        else l = 0;
 
        if(i+y < N) r = i+y;
        else r = N-1;
 
            int flag = 1;
            for(int j = l;j < i;j++)
            {
                if(a[j] <= a[i])
                {
                    flag = 0;
                    break;
                }
            }
            for(int j = i+1;j <= r;j++)
            {
                if(flag == 0) break;
                if(a[j] <= a[i])
                {
                    flag = 0;
                    break;
                }
            }
            if(flag)
            {
                cout << i+1 <<endl;
                break;
            }
 
    }
    return 0;
}