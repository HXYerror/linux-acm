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
const int MAX = 200050;//100000
const int MAX_1 = 15;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;//998244353;
const double PI = acos(-1);
LL T,N,M,K;
/*-------------------------------------------------------------------------------------------*/
struct AandB
{
    int a,b;
}c[MAX];
int d[2*MAX];
/* ------------------------------------------------------------------------------------------*/
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* -----------------------------------------------------------------------------------------*/
    cin >> N >> T;
    for(int i = 1;i <= N;i++)
    {
        cin >> d[i];
    }
    int head,pos,time;
    head = max(d[1],d[2]);
    time  = 1;
    pos = N+1;
    AandB temp;
    temp.a = d[1];
    temp.b = d[2];
    c[time++] = temp;
    d[pos++] = min(d[1],d[2]);
    for(int i = 3;i <= N;i++)
    {
        temp.a = head;
        temp.b = d[i];
        c[time++] = temp;
        d[pos++] = min(head,d[i]);
        head = max(head,d[i]);
    }
    vector<int> f;
    for(int i = N+1;i < pos;i++)
    {
        f.push_back(d[i]);
    }
    while(T--)
    {
        cin >> M;
        if(M < time)
        {
            cout << c[M].a << " " << c[M].b <<endl;
        }
        else
        {
            cout << head << " " << f[(M - N) % (N-1)] <<endl;
        }
    }
    return 0;
}