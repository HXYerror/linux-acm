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
const int MAX_1 = 100010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;
const double PI = acos(-1);
LL T,N,M;
/*-------------------------------------------------------------------------------------------*/
vector<LL> a;
/* ------------------------------------------------------------------------------------------*/

LL gcd(LL a,LL b)
{
    return a%b ?  gcd(b,a%b) : b;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    while(cin >> N >> M)
    {
        a.clear();
        LL x;
        LL sum = 0;
        LL k = 1;
        LL lcm = 1;
        LL temp;
        for(int i = 0;i < N;i++)
        {
            cin >> x;
            temp = gcd(k,x);
            lcm = (k*x) / temp;
            k = lcm;
            a.push_back(x);

        }

        for(int i = 0;i < N;i++)
        {
            sum += lcm / a[i];
        }

        if(M % sum == 0)
        {
            int m = M / sum;
            cout << "Yes" <<endl;
            for(int i = 0;i < N;i++)
            {
                cout << (lcm / a[i]) *m ;
                if(i != N-1) cout << " ";
                else cout <<endl;
            }
        }
        else cout << "No" <<endl;

    }

    return 0;
}
