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
char c2[MAX];
/* ------------------------------------------------------------------------------------------*/
int ind(int l,int r,int ans,int mi)
{
    while(l <= r)
    {
        if(a[l] > mi)
        {
            mi = a[l];
            l++;
            c[ans++] = 'L';
        }
        else break;
    }
    return ans;
}

int ind2(int l,int r,int ans,int mi)
{
    while(l <= r)
    {
        if(a[r] > mi)
        {
            mi = a[r];
            r--;
            c2[ans++] = 'R';
        }
        else
        {
            break;
        }
    }
    return ans;
}

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
    int ff = 1;
    while(l <= r)
    {
        if(a[l] == a[r] && a[l] > mi)
        {
            //cout << ans <<endl;
            mi = a[l];
            c[ans] = 'L';
            c2[ans++] = 'R';
            int x = ind(l+1,r,ans,mi);
            int y = ind2(l,r-1,ans,mi);
            //cout << x << " " << y <<endl;
            ans = max(x,y);
            if(x > y)
            {
                ff = 2;
            }
            else
            {
                ff = 3;
            }
            break;
        }
        if(a[l] > mi && a[r] > mi)
        {
            if(a[l] > a[r])
            {
                mi = a[r];
                r--;
                c[ans] = 'R';
                c2[ans++] = 'R';
            }
            else
            {
                mi = a[l];
                l++;
                c[ans] = 'L';
                c2[ans++] = 'L';
            }
        }
        else if(a[l] > mi)
        {
            mi = a[l];
            l++;
            c[ans] = 'L';
            c2[ans++] = 'L';
        }
        else if(a[r] > mi)
        {
            mi = a[r];
            r--;
            c[ans] = 'R';
            c2[ans++] = 'R';
        }
        else
        {
            break;
        }
    }
    cout << ans << "\n";
    if(ff == 2)
    {
        for(int i = 0;i < ans;i++)
        {
            cout << c[i];
        }
    }
    else
    {
        for(int i = 0;i < ans;i++)
        {
            cout << c2[i];
        }
    }
    cout << "\n";
    return 0;
}