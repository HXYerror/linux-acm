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
        vector<int> a;
        cnt = 0;
        cin >> N >> M;
        int x;
        for(int i = 0;i < N;i++)
        {
            cin >> x;
            if(x % 2) cnt++;
            a.push_back(x);
        }
        if(cnt < M || (cnt - M) % 2)
        {
            cout << "NO" <<endl;
        }
        else
        {
            cout << "YES" <<endl;
            int k = 0;
            for(int i = 0;i < N;i++)
            {
                if(a[i] % 2 && k < M-1)
                {
                    k++;
                    cout << i+1 << " ";
                }
            }
            cout << N <<endl;
        }
    }
 
 
    return 0;
}