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
const int MAX = 300010;
const int MAX_1 = 55;
const int INF = 0xfffffff;//268435455,2e8;
const double EPS = 0.0000001;
const int MOD = 10000007;
int T,N,M;


/*-------------------------------------------------------------------------------------------*/
map<int,int> a;
struct Pos
{
    int x;
    int p;
}b[MAX];
/* ------------------------------------------------------------------------------------------*/

bool Cmp(Pos a,Pos b)
{
    return a.x < b.x;
}

int main()
{
    //std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    LL ans = 2e18;
    cin >> N;
    int x;
    for(int i = 1;i <= N;i++)
    {
        cin >> x;
        b[i].x = x;
        b[i].p = i;
        a[i] = x;
    }
    sort(b+1,b+N+1,Cmp);
    map<int,int> ::iterator itb,ite;
    for(int i = 1;i < N;i++)
    {
        LL k;
        int pos = b[i].p;
        itb = a.begin();
        ite = a.end();
        ite--;
        k = b[i].x / max((pos - itb->first),(ite->first - pos));
        ans = min(ans,k);
        a.erase(pos);
        if(ans == 0) break;
    }
    cout << ans;
    return 0;
}