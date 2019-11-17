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
const int MAX = 10;
const int INF = 0xfffffff;//268435455,2e8;
const double EPS = 0.0000001;
const int MOD = 100;
int T,N,M;

//std::ios::sync_with_stdio(false);
/*-------------------------------------------------------------------------------------------*/
int flag[MAX];
char cell[MAX][MAX];
int ans = 0;
/* ------------------------------------------------------------------------------------------*/

void dfs(int step,int row)
{
    if(step == M)
    {
        ans ++;
        return ;
    }
    for(int i = 0;i < N;i++)
    {
        if(cell[row][i] == '#' && !flag[i])
        {
            flag[i] = 1;
            dfs(step + 1,row+1);
            flag[i] = 0;
        }
    }
    if(row < N-1)dfs(step,row+1);
}

int main()
{
    while(cin >> N >> M && !(M == -1 && N == -1))
    {
        for(int i = 0;i < N;i++)
        {
            cin >> cell[i];//#can
        }
        ans = 0;
        fill(flag,flag+MAX,0);
        dfs(0,0);
        cout << ans <<"\n";
    }

    return 0;

}
