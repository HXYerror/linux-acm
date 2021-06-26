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
const int MAX = 110;//100000
const int MAX_1 = 100010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;
const double PI = acos(-1);
LL T,N,M;
/*-------------------------------------------------------------------------------------------*/
vector<int> a[MAX];
/* ------------------------------------------------------------------------------------------*/


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    cin >> N >> M;
    if(N == 1)
    {
        cout << "0" <<endl;
        return 0;
    }
    int x;
    for(int i = 0;i < N;i++)
    {
        cin >> x;
        a[x].push_back(i);
    }
    int ans = 0;
    for(int i = 1;i <= M;i++)
    {
        for(int j = 1;j <= M;j++)
        {
            if(i == j) continue;
            int li = a[i].size();
            int lj = a[j].size();
            if(li+lj < ans) break;
            int temp = 0;
            int m = 0;
            for(int k = 0;k < li;k++)
            {
                if(k != 0)
                {
                    if(a[j][m] > a[i][k]) continue;
                }
                //cout << a[i][k] << " " << a[j][m] <<endl;
                temp++;
                while(a[j][m] < a[i][k])
                {
                    m++;
                    if(m >= lj) break;
                }
                if(m >= lj) break;
                temp++;
                //m++;
            }
            ans = max(temp,ans);
        }
    }
    cout <<ans <<endl;
    return 0;
}