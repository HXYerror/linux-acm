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
        cin >> N >> M;
        multiset<int,greater<int>> a;
        LL sum = 0;
        int cnt = 0;
        int x;
        cin >> x;
        a.insert(x);
        cout << 0 <<" ";
        sum += x;
        multiset<int,greater<int>> ::iterator  it;
        int flag = 1;
        for(int i = 1;i < N;i++)
        {
            cin >> x;
            sum += x;
            while(sum > M)
            {
                if(flag)
                {
                    flag = 0;
                    it = a.begin();
                }
                else it++;
                sum -= *it;
                cnt++;
            }
            while(sum < M)
            {
                if(cnt >0 && sum + *it <= M)
                {
                    sum += *it;
                    it--;
                    cnt--;
                }
                else break;
            }
            cout << cnt <<" ";

            a.insert(x);
            if(cnt > 0 && x > *it)
            {
                sum += *it;
                sum -= x;
                it--;
            }

        }
        cout <<endl;
    }
    return 0;
}