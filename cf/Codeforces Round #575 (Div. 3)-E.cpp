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
const int MAX = 100010;//100000
const int MAX_1 = 70;
const int INF = 100000;//0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;//998244353;
const double PI = acos(-1);
LL T,N,M;
/*-------------------------------------------------------------------------------------------*/
 
/* ------------------------------------------------------------------------------------------*/
void mycout(int a,int b,int d,int c)
{
    if(c > 2*d+1)
    {
        cout << "NO" <<endl;
        return ;
    }
    else
    {
        cout << "YES" <<endl;
    }
    for(int i = 0;i < 2*d;i++)
    {
        cout << a << " " << b+i << endl;
    }
    if(c == 2*d+1)
    {
        cout << a << " " << b-1 <<endl;
        c--;
    }
    int cnt = 0;
    for(int i = 0;;i+=2)
    {
        if(cnt == c) break;
        cout << a-1 << " " << b+i <<endl;
        cnt++;
        if(cnt == c) break;
        cout << a+1 << " " << b+i <<endl;
        cnt++;
    }
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
    while(T--)
    {
        cin >> N >> M;//heibai
        if(N > M)
        {
            mycout(2,2,M,N-M);
        }
        else
        {
            mycout(2,3,N,M-N);
        }
    }
    return 0;
}