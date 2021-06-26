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
const int MAX = 10;
const int INF = 0xfffffff;//268435455,2e8;
const double EPS = 0.0000001;
const int MOD = 100;
int T,N,M;

//std::ios::sync_with_stdio(false);
/*-------------------------------------------------------------------------------------------*/
int flag[110];
int a[110];
/* ------------------------------------------------------------------------------------------*/



int main()
{
    cin >> N;
    int max_i,min_i;
    max_i = 0;
    min_i = 110;
    int cnt = 0;
    for(int i = 0;i < N;i++)
    {
        cin >> a[i];
        if(!flag[a[i]])
        {
            flag[a[i]] = 1;
            cnt++;
        }
        if(a[i] > max_i) max_i = a[i];
        if(a[i] < min_i) min_i = a[i];
    }
    if(cnt > 3)
    {
        cout << "-1";
    }
    else if(cnt == 1)
    {
        cout << "0";
    }
    else if(cnt == 2)
    {
        if((max_i+min_i) % 2 == 0)
        {
            int ans1 = max_i- min_i;
            int ans2 = (max_i+min_i) / 2 - min_i;
            cout << min(ans1,ans2);
        }
        else cout << max_i- min_i;
    }
    else
    {
        if((max_i+min_i) % 2 == 0)
        {
            int k;
            for(int i = 0;i< N;i++)
            {
                if(a[i] != min_i && a[i] != max_i)
                {
                    k = a[i];
                    break;
                }
            }
            int m = (max_i+min_i) / 2 - min_i;
            if(min_i+m == k) cout << m;
            else cout << "-1";
        }
        else cout << "-1";
    }
    return 0;
}