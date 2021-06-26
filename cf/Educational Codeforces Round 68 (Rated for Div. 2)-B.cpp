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
vector<vector<int> > str(MAX);
vector<int> mam;
vector<int> man;
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
    while(T--)
    {
        cin >> N >> M;
        int cntn = 0;
        int cntm = 0;
 
        char c;
        int y[MAX];
        fill(y,y+MAX,0);
 
        for(int i = 0;i < MAX;i++)
        {
            str[i].clear();
        }
 
        for(int i = 1;i <= N;i++)
        {
            int x = 0;
            for(int j = 1;j <= M;j++)
            {
                cin >> c;
                str[i].push_back((int)c);
                if(c == '*')
                {
                    x++;
                    y[j]++;
                }
            }
            if(x > cntm)
            {
                cntm = x;
                mam.clear();
                mam.push_back(i);
            }
            else if(x == cntm)
            {
                mam.push_back(i);
            }
        }
 
        for(int i = 1;i <= M;i++)
        {
            if(y[i] > cntn)
            {
                cntn = y[i];
                man.clear();
                man.push_back(i);
            }
            else if(y[i] == cntn)
            {
                man.push_back(i);
            }
        }
 
        int ans = N - cntn + M - cntm;
        if(ans == 0 || ans == 1)
        {
            cout << ans <<endl;
        }
        else
        {
            int flag = 0;
            for(int i = 0;i < man.size();i++)
            {
                for(int j = 0;j < mam.size();j++)
                {
                    if(str[mam[j]][man[i]-1] == (int)'.')
                    {
                        ans--;
                        flag = 1;
                        break;
                    }
                }
                if(flag) break;
            }
            cout << ans <<endl;
        }
    }
    return 0;
}