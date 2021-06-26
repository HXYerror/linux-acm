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
const int MAX = 505;//100000
const int MAX_1 = 2010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;
int T,N,M;
/*-------------------------------------------------------------------------------------------*/
int cnt[MAX];
char str[MAX];
/* ------------------------------------------------------------------------------------------*/
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    cin >> N;
    cnt[0] = 0;
    for(int i = 1;i <= N;i++)
    {
        cin >> str[i];
        if(str[i] == '0') cnt[i] = cnt[i-1]+1;
        else cnt[i] = cnt[i-1];
    }
    str[N+1] = '\0';
    if(N % 2 == 1 || N - cnt[N] != cnt[N])
    {
        cout << 1 << endl;
        for(int i = 1;i <= N;i++)
        {
            cout << str[i];
        }
    }
    else
    {
        cout << 2 <<endl;
        for(int i = 1;i <= N;i++)
        {
            if(i - cnt[i] != cnt[i])
            {
                for(int j = 1;j <= i ; j++)
                {
                    cout << str[j];
                }
                cout << " ";
                for(int j = i+1;j <= N;j++)
                {
                    cout << str[j];
                }
                cout <<endl;
                break;
            }
        }
    }
    return 0;
}