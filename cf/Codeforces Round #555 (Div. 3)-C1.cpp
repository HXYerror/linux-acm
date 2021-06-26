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
const int MAX = 201000;
const int MAX_1 = 500000;
const int INF = 0xfffffff;//268435455,2e8;
const double EPS = 0.0000001;
const int MOD = 10000007;
int T,N,M;

/*-------------------------------------------------------------------------------------------*/

int a[MAX];
char c[MAX];
/* ------------------------------------------------------------------------------------------*/


int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
/* --------------------------------------------------------------------------------------*/
    cin >> N;
    for(int i = 0;i < N;i++)
    {
        cin >> a[i];
    }
    int l = 0;
    int r = N-1;
    int ans = 0;
    int mi = 0;
    while(l <= r)
    {
        if(a[l] > mi && a[r] > mi)
        {
            if(a[l] > a[r])
            {
                mi = a[r];
                r--;
                c[ans++] = 'R';
            }
            else
            {
                mi = a[l];
                l++;
                c[ans++] = 'L';
            }
        }
        else if(a[l] > mi)
        {
            mi = a[l];
            l++;
            c[ans++] = 'L';
        }
        else if(a[r] > mi)
        {
            mi = a[r];
            r--;
            c[ans++] = 'R';
        }
        else
        {
            break;
        }
    }
    cout << ans << "\n";
    for(int i = 0;i < ans;i++)
    {
        cout << c[i];
    }
    cout << "\n";
    return 0;
}