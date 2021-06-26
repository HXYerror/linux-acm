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
const int MAX = 10001000;
const int MAX_1 = 1010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;
int T,N,M;
/*-------------------------------------------------------------------------------------------*/
double dis[MAX_1][MAX_1];
int pre[MAX_1];
int x[MAX_1];
int y[MAX_1];
vector<int> use;
/* ------------------------------------------------------------------------------------------*/
double distan(int i,int j)
{
    double z;
    z = sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]));
    return z;
}

int find_n(int n)
{
    if(pre[n] == n)
        return n;
    else return pre[n] = find_n(pre[n]);
}

void unit(int p,int q)
{
    int root1 = find_n(p);
    int root2 = find_n(q);
    if(root1 == root2) return;
    else
    {
        pre[root1] = root2;
        return;
    }
}

bool if_same(int p,int q)
{
    int root1 = find_n(p);
    int root2 = find_n(q);
    if(root1 == root2) return true;
    else return false;
}


int main()
{
    //std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    cin >> N >> T;
    for(int i = 1;i <= N;i++)
    {
        cin >> x[i] >> y[i];
    }
    for(int i = 1;i <= N;i++)
    {
        for(int j = 1;j <= N;j++)
        {
            dis[i][j] = distan(i,j);
        }
    }
    for(int i = 1;i <= N;i++)
    {
        pre[i] = i;
    }
    char c;
    while(cin >> c)
    {
        if(c == 'O')
        {
            int p;
            cin >> p;
            for(int i = 0;i < use.size();i++)
            {
                if(dis[p][use[i]] <= T || (((dis[p][use[i]] - (int)dis[p][use[i]]) == 0) && (int)dis[p][use[i]] == T))//yiwen
                {
                    unit(p,use[i]);
                }
            }
            use.push_back(p);
        }
        else
        {
            int p,q;
            cin >> p >>q;
            if(if_same(p,q)) cout << "SUCCESS" <<endl;
            else cout << "FAIL" <<endl;
        }
    }
    return 0;
}