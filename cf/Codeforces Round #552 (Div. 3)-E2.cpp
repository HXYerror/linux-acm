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
struct STU
{
    int v;
    int p;
}stu[MAX];


bool Cmp(STU a,STU b)
{
    return a.v > b.v;
}

map<int,int> sk;

/* ------------------------------------------------------------------------------------------*/


int main()
{
    std::ios::sync_with_stdio(false);
    cin >> N >>M;
    int cnt = 0;
    for(int i = 1;i <= N;i++)
    {
        int x;
        cin >> x;
        stu[i].v = x;
        stu[i].p = i;
        sk[i] = x;
    }
    sort(stu+1,stu+N+1,Cmp);
    int ff = 1;
    for(int i = 1;i <= N;i++)
    {
        map<int,int> ::iterator it;
        int x = stu[i].p;
        if(!flag[x])
        {
            flag[x] = ff;
            //cout << x << " " << ff <<endl;
            int cnnt = 0;
            it = sk.find(x);
            it++;
            while(cnnt != M)
            {
                if(it == sk.end()) break;
                flag[it->first] = ff;
               // cout << it->first << " " << ff <<endl;
                sk.erase(it++);
                cnnt++;
            }


            it = sk.find(x);
            if(it == sk.begin())
            {
                if(ff == 1)
                {
                    ff = 2;
                }
                else ff = 1;
                sk.erase(it);
                continue;
            }
            else it--;
            cnnt = 0;
            while(cnnt != M)
            {
                flag[it->first] = ff;
                //cout << it->first << " " << ff<<endl;
                if(it == sk.begin())
                {
                    sk.erase(it);
                    break;
                }
                else sk.erase(it--);
                cnnt++;
            }
            sk.erase(sk.find(x));
            if(ff == 1)
            {
                ff = 2;
            }
            else ff = 1;
        }

    }
    for(int i = 1;i <= N;i++)
    {
        cout << flag[i];
    }
    return 0;
}