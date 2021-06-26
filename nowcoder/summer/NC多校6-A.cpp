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
const int MAX = 3010;//100000
const int MAX_1 = 2;
const int MAX_2 = 1000010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;//998244353;
const double PI = acos(-1);
LL T,N,M,K;
/*-------------------------------------------------------------------------------------------*/
 
/* ------------------------------------------------------------------------------------------*/
void mycout(int x,int n)
{
    cout << "Case #" <<n<<": ";
    if(x == 1)
    {
        cout << "Harmful" <<endl;
    }
    else if(x == 2)
    {
        cout << "Recyclable" <<endl;
    }
    else if(x == 3)
    {
        cout << "Dry" <<endl;
    }
    else
    {
        cout << "Wet" <<endl;
    }
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* -----------------------------------------------------------------------------------------*/
    cin >> T;
    string str1,str2;
    int cnt = 0;
    while(T--)
    {
        cnt++;
        cin >> str1 >> str2;
        map<char,int> num;
        for(int i = 0;i < str1.size();i++)
        {
            num[str1[i]]++;
        }
        int d,w,h;
        d = w = h = 0;
        char c = 'a';
        for(int i = 0;i < str2.size();i++)
        {
            if(str2[i] == 'd')
            {
                d += num[c];
            }
            else if(str2[i] == 'w')
            {
                w += num[c];
            }
            else
            {
                h +=  num[c];
            }
            c ++;
        }
        int n =str1.size();
        if(h >= n/4.0)
        {
            mycout(1,cnt);
        }
        else if(h <= n / 10.0)
        {
            mycout(2,cnt);
        }
        else
        {
            if(d >= 2*w)
            {
                mycout(3,cnt);
            }
            else mycout(4,cnt);
        }
    }
    return 0;
}