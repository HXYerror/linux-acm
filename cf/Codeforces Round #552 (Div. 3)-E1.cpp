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
const int MAX = 200020;
const int INF = 0xfffffff;//268435455,2e8;
const double EPS = 0.0000001;
const int MOD = 100;
int T,N,M;


/*-------------------------------------------------------------------------------------------*/
int flag[MAX];
int skill[MAX];
struct STU
{
    int v;
    int p;
}stu[MAX];

struct RL
{
    int l;
    int r;
}pre[MAX];

bool Cmp(STU a,STU b)
{
    return a.v > b.v;
}

/* ------------------------------------------------------------------------------------------*/

int find_prel(int x)
{
    if(pre[x].l == x)
    {
        return x;
    }
    else return pre[x].l = find_prel(pre[x].l);
}

int find_prer(int x)
{
    if(pre[x].r == x)
    {
        return x;
    }
    else return pre[x].r = find_prer(pre[x].r);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> N >>M;
    int cnt = 0;
    for(int i = 0;i < N;i++)
    {
        cin >> skill[i];
        stu[i].v = skill[i];
        stu[i].p = i;
        pre[i].l = pre[i].r = i;
    }
    sort(stu,stu+N,Cmp);


    int ff = 1;
    for(int i = 0;i < N;i++)
    {
        if(cnt == N) break;
        int x = stu[i].p;
        if(!flag[x])
        {
            flag[x] = ff;
            int cnnt = 0;
            int m;
            for(m = x+1;m < N;m++)
            {
                if(cnnt == M) break;//end flag
                int k = m;
                if(pre[m].r != m)
                {
                    m = find_prer(m);
                }
                if(m == N) break;
                if(!flag[m])
                {
                    flag[m] = ff;
                    cnnt++;
                    cnt++;
                    pre[k].r = min(m+1,N-1);
                    pre[k].l = x;
                }
            }
            pre[x].r = min(m,N-1);

            cnnt = 0;
            for(m = x-1;m >= 0;m--)
            {
                if(cnnt == M) break;
                int k = m;
                if(pre[m].l != m)
                {
                    m = find_prel(m);
                }
                if(m < 0) break;
                if(!flag[m])
                {
                    flag[m] = ff;
                    cnnt++;
                    cnt++;
                    pre[k].l = max(m-1,0);
                    pre[k].r = x;
                }
            }
            pre[x].l = max(m,0);
            if(ff == 1)
            {
                ff = 2;
            }
            else ff = 1;
        }

    }
    for(int i = 0;i < N;i++)
    {
        cout << flag[i];
    }
    return 0;
}