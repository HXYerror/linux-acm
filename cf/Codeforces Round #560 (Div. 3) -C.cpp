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
const int MAX = 200010;
const int MAX_1 = 300010;
const int INF = 0x3f3f3f3f;//1061109567,1e9;
const double EPS = 0.0000001;
const int MOD = 10000;
int T,N,M;


/*-------------------------------------------------------------------------------------------*/

char a[MAX];
/* ------------------------------------------------------------------------------------------*/


int main()
{
    //std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    cin >> N;
    cin >> a;
    int ans = 0;
    for(int i = 0;i < N;i++)
    {
        int k = i;
        i++;
        while(a[k] == a[i])
        {
            a[i] = '0';
            ans++;
            if(i == N-1) break;
            i++;
        }
    }
    if((N - ans) % 2)
    {
        int cnt = 0;
        cout << ans + 1 <<endl;
        for(int i = 0;i < N;i++)
        {
            if(cnt == N-ans-1) break;
            if(a[i] == '0') continue;
            else
            {
                cout << a[i];
                cnt++;
            }
        }
        cout <<endl;
    }
    else
    {
        cout <<ans <<endl;
        for(int i = 0;i <N;i++)
        {
            if(a[i] == '0') continue;
            else cout << a[i];
        }
        cout <<endl;
    }
    return 0;
}