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
const int MAX = 100010;//100000
const int MAX_1 = 2010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;
const double PI = acos(-1);
LL T,N,M;
/*-------------------------------------------------------------------------------------------*/
 
/* ------------------------------------------------------------------------------------------*/
 
void myanscout(bool flag)
{
    if(!flag) cout << "Alice" <<endl;
    else cout << "Bob"<<endl;
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    cin >> T;
    int k;
    while(T--)
    {
        cin >> N >> k;
        if(k % 3 == 0)
        {
            N = N%(k+1);
            if(N == k) myanscout(0);
            else myanscout(!(N % 3));
        }
        else
        {
            myanscout(!(N % 3));
        }
    }
    return 0;
}