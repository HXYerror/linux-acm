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
const int MAX = 300;//100000
const int MAX_1 = 10;
const int MAX_2 = 1000010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;//998244353;
const double PI = acos(-1);
int T,N,M,K;
/*-------------------------------------------------------------------------------------------*/
string str;
/* ------------------------------------------------------------------------------------------*/
int solve(int l,int r,vector<int> a,int n,int cnt)
{
    char c[MAX];
    int j = 0;
    for(int i = a[l];i <= n;i++)
    {
        c[j++] = str[i];
    }
    int lc = j;
    c[j] = '\0';
    char cmp[MAX];
    int k = l;
    while(r >= l)
    {
        while(k <= r)
        {
            int i;
            int j = 0;
 
            int m;
            if(r == cnt-1) m = n + 1;
            else m = a[r+1];
 
            for(i = a[k];i < m;i++)
            {
                cmp[j++] = str[i];
            }
            for(i = a[l];i < a[k];i++)
            {
                cmp[j++] = str[i];
            }
            cmp[j] = '\0';
          // cout<< r << " " << c << " " << cmp <<endl;
            if(strcmp(c,cmp) > 0) break;
            k++;
        }
        if(k == r+1) break;
        int m;
        m = n - a[r] + 1;
        c[lc - m] = '\0';
        r--;
    }
    return r;
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* -----------------------------------------------------------------------------------------*/
    cin >> T;
    while(T--)
    {
        cin >> str;
        N = str.size();
        vector<int> a;
        int cnt1 = 0;
        int k = 0;
        for(k = 0 ;k < N;k++)
        {
            if(str[k] == '1')
            {
                cnt1++;
            }
            else break;
        }
        if(cnt1 > 0)
        {
            while(cnt1--)
            {
                cout << "1";
            }
            cout << " ";
        }
        int cnt0 = 0;
        int j;
        for(j = N-1;j >= 0;j--)
        {
            if(str[j] == '0') cnt0++;
            else break;
        }
        int cnt = 0;
        for(int i = k;i < j;)
        {
            a.push_back(i);
            cnt++;
            while(i <= j)
            {
                if(str[i] == '0') i++;
                else break;
            }
            while(i <= j)
            {
                if(str[i] == '1') i++;
                else break;
            }
        }
        int n = -1;
        while(n < cnt-1)
        {
            int m = n+1;
            n = solve(n+1,cnt-1,a,j,cnt);
            int r;
            if(n == cnt-1) r = j+1;
            else r = a[n+1];
            for(int i = a[m];i < r;i++)
                cout << str[i];
            cout << " ";
        }
        if(cnt0)
        {
            while(cnt0--) cout << "0";
        }
        cout <<endl;
    }
 
    return 0;
}