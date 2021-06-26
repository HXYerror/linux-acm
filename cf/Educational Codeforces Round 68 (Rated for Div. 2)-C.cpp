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
const int MAX = 50010;//100000
const int MAX_1 = 2010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;
const double PI = acos(-1);
LL T,N,M;
/*-------------------------------------------------------------------------------------------*/
 
/* ------------------------------------------------------------------------------------------*/
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    cin >> T;
    //s->t del p
    while(T--)
    {
        string s,t,p;
        map<char,int> ss,pp;
        cin >> s >> t >> p;
        int cnt = 0;
        bool flag = true;
        for(int i = 0;i < s.size();i++)
        {
            ss[s[i]]++;
            int j = cnt;
            bool a = false;
            for(;j < t.size();j++)
            {
                if(t[j] == s[i])
                {
                    cnt = j+1;
                    a = true;
                    break;
                }
            }
            if(!a) flag = false;
        }
        if(!flag)
        {
            cout << "NO" <<endl;
            continue;
        }
        for(int i = 0;i < p.size();i++)
        {
            pp[p[i]]++;
        }
 
        for(int i = 0;i < t.size();i++)
        {
            if(ss.find(t[i]) == ss.end())
            {
                if(pp.find(t[i]) == pp.end())
                {
                    flag = false;
                    break;
                }
                else
                {
                    pp[t[i]]--;
                    if(pp[t[i]] == 0) pp.erase(t[i]);
                }
            }
            else
            {
                ss[t[i]]--;
                if(ss[t[i]] == 0) ss.erase(t[i]);
            }
        }
        if(flag && ss.empty()) cout << "YES" <<endl;
        else cout << "NO" <<endl;
    }
    return 0;
}