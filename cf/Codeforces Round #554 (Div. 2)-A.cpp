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
const int MAX_1 = 100;
const int INF = 0xfffffff;//268435455,2e8;
const double EPS = 0.0000001;
const int MOD = 1000000007;
int T,N,M;

/*-------------------------------------------------------------------------------------------*/

/* ------------------------------------------------------------------------------------------*/



int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
/* --------------------------------------------------------------------------------------*/
    cin >> N >> M;
    int cnto,cnte;
    cnto = cnte = 0;
    for(int i = 0;i < N;i++)
    {
        int x;
        cin >> x;
        if(x % 2) cnto++;
        else cnte++;
    }
    int cno,cne;
    cno = cne = 0;
    for(int i = 0;i < M;i++)
    {
        int x;
        cin >> x;
        if(x % 2) cno++;
        else cne++;
    }
    int ans = 0;
    ans +=min(cnto,cne);
    ans +=min(cnte,cno);
    cout <<ans << "\n";
    return 0;
}