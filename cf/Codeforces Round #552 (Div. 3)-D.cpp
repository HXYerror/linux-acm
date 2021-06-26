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
const int MAX = 200020;
const int INF = 0xfffffff;//268435455,2e8;
const double EPS = 0.0000001;
const int MOD = 100;
int T,N,M;

//std::ios::sync_with_stdio(false);
/*-------------------------------------------------------------------------------------------*/
int A,B;
int ex[MAX];
/* ------------------------------------------------------------------------------------------*/




int main()
{
    cin >> N >> A >> B;
    for(int i = 0;i < N;i++)
    {
        cin >> ex[i];
    }
    int ans = 0;
    int a,b;
    a = A,b = B;
    for(int i = 0;i < N;i++)
    {
        if(a==0 && b==0)
        {
            break;
        }
        if(ex[i] == 0)
        {
            if(b > 0)
            {
                b--;
                ans++;
                continue;
            }
            else
            {
                a--;
                ans++;
                continue;
            }
        }
        else
        {
            if(a > 0)
            {
                if(b < B)
                {
                    a--;
                    b++;
                    ans++;
                    continue;
                }
                else
                {
                    b--;
                    ans++;
                    continue;
                }
            }
            else
            {
                b--;
                ans++;
                continue;
            }
        }
    }
    cout <<ans;
    return 0;
}