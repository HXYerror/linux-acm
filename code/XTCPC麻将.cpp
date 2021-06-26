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
const int MAX = 2000010;
const int MAX_1 = 1000100;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;
int T,N,M;


/*-------------------------------------------------------------------------------------------*/
string card[] = {"dong","nan","xi","bei","zhong","fa","bai"};
string shisan[] = {"dong","nan","xi","bei","zhong","fa","bai","1s","9s","1p","9p","1w","9w"};
map<string,int> maj;
map<string,int> word;
map<string,int> shisanyao;
/* ------------------------------------------------------------------------------------------*/


int main()
{
    //std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    string s;
    for(int i = 0;i < 7;i++)
    {
        word[card[i]] = 1;
    }
    for(int i = 0;i < 13;i++)
    {
        shisanyao[shisan[i]] = 1;
    }

    int f = 0;
    int ff = 0;
    char c = 'q';
    for(int i = 0;i < 14;i++)
    {
        cin >> s;
        maj[s]++;
        if(word.find(s) != word.end()) f = 1;
        else
        {
            if(c == 'q')
            {
                c = s[1];
            }
            else
            {
                if(c != s[1]) ff = 1;
            }
        }
    }
    if(f)
    {
        auto it = shisanyao.begin();
        for(;it != shisanyao.end();it++)
        {
            if(maj.find(it->first) == maj.end()) break;
        }
        if(it == shisanyao.end())
        {
            cout << "shisanyao!"<<endl;
        }
        else
        {
            cout << "I dont know!" <<endl;
        }
    }
    else
    {
        if(ff)
        {
            cout << "I dont know!" <<endl;
        }
        else
        {
            auto it = maj.begin();
            auto its = maj.end();
            its--;
            if(it->second > 2 && its->second>2)
            {
                cout << "jiulianbaodeng!" <<endl;
            }
            else
            {
                cout << "I dont know!"<<endl;
            }
        }
    }
    return 0;
}
