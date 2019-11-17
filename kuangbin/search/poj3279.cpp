
//#include <bits/stdc++.h>
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
#define ll  long long
using namespace std;
const int MAX = 20;//100000
const int MAX_1 = 1000100;
const int MAX_2 = 1000010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;//998244353;
const double PI = acos(-1);
//void runtime(){cout << "The run time is:" << (double)clock() /CLOCKS_PER_SEC<< "s" << endl;}
ll T,N,M,K;

/* --------------------------------------------------------------------------------------------------*/
int a[MAX][MAX];
int cnt[MAX][MAX];
int to[4][2] = {0,1, 0,-1, 1,0, -1,0};
int temp[MAX][MAX];
vector<int> ans;
int minans = INF;
/* --------------------------------------------------------------------------------------------------*/

void turn(int i,int j)
{
    cnt[i][j] ++;
    int ti,tj;
    for(int k = 0;k < 4;k++)
    {
        ti = i + to[k][0];
        tj = j + to[k][1];
        if(ti >= 0 && ti < N && tj >= 0 && tj < M) cnt[ti][tj]++;
    }
}
void mycout()
{
    for(int i = 0;i < N;i++)
    {
        for(int j = 0;j < M;j++)
        {
            cout << cnt[i][j];
            if(j < M-1) cout << " ";
        }
        cout << "\n";
    }
}
void dfs(int &cmt)
{
    for(int i = 1;i < N;i++)
    {
        for(int j = 0;j < M;j++)
        {
            temp[i][j] = (a[i-1][j] + cnt[i-1][j]) % 2;
            if((a[i-1][j] + cnt[i-1][j]) % 2)
            {
                turn(i,j);
                //mycout();
                cmt++;
                if(cmt == minans) return;
            }
        }
    }
    int flag = 1;
    for(int j = 0;j < M;j++)
    {
        if((a[N-1][j] + cnt[N-1][j]) % 2) flag = 0;
    }
    if(flag && cmt < minans)
    {
        ans.clear();
        minans = cmt;
        for(int i = 0;i < N;i++)
        {
            for(int j = 0;j < M;j++)
            {
                ans.push_back(temp[i][j]);
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* -----------------------------------------------------------------------------------------*/
    cin >> N >> M;
    for(int i = 0;i < N;i++)
    {
        for(int j = 0;j < M;j++)
        {
            cin >> a[i][j];
        }
    }

    for(int i = 0;i < 1<<M;i++)
    {
        memset(cnt,0,sizeof(cnt));
        memset(temp,0,sizeof(temp));
        int cmt = 0;
        int n = i;
        for(int j = M-1;j >= 0;j--)
        {
            int k = n&1;
            n >>= 1;
            if(k)
            {
                turn(0,j);
                cmt++;
            }
            temp[0][j] = k;
        }
        dfs(cmt);
    }

    if(minans != INF)
    {
        for(int i = 0;i < N;i++)
        {
            for(int j = 0;j < M;j++)
            {
                cout << ans[M*i+j];
                if(j < M-1) cout << " ";
            }
            cout << "\n";
        }
    }
    else cout << "IMPOSSIBLE" << "\n";
    return 0;
}
