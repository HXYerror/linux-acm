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
const int MAX = 1010;//100000
const int MAX_1 = 2;
const int MAX_2 = 1000010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;//998244353;
const double PI = acos(-1);
LL T,N,M,K;
/*-------------------------------------------------------------------------------------------*/
 
/* ------------------------------------------------------------------------------------------*/
 
void mycase(int x,char str[])
{
    cout << "Case #" << x <<": "<<str <<endl;
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
    int cnt = 0;
    char tensix[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
    int pow2[5] = {1,2,4,8};
    while(T--)
    {
        cnt++;
        string str;
        cin >> str;
        char ans[MAX];
        int pos = 1;
        for(int i = 0;i < str.size();i++)
        {
            int n = 0;
            for(int j = 0;j < 4;j++)
            {
                if(str[i+j] == '1') n+= pow2[3 - j];
            }
            ans[pos++] = tensix[n];
            i += 3;
        }
        int l,r;
        l = r = -1;
        int maxl = 0;
        int ansl,ansr;
        ansl = ansr = -1;
        for(int i = 1;i < pos;i++)
        {
            if(ans[i] == '0')
            {
                if(i % 4 == 1)
                {
                    if(l == -1) l = i;
                }
                else if(i % 4 == 0)
                {
                    if(l != -1) r = i;
                    if((r - l + 1) > 4)
                    {
                        if((r - l + 1) > maxl)
                        {
                            ansr = r;
                            ansl = l;
                            maxl = r-l+1;
                        }
                        else if((r - l + 1) == maxl)
                        {
                            if(ansl == 1 || r != pos-1)
                            {
                                ansr = r;
                                ansl = l;
                                maxl = r-l+1;
                            }
                        }
 
                    }
                }
            }
            else
            {
                l = r = -1;
 
            }
        }
        ans[pos] = '\0';
//cout << ans <<endl;
//cout << ansl << " " <<ansr <<endl;
        char rans[MAX];
        int p = 0;
        int flag = 1;
        for(int i = 1;i < pos;i++)
        {
            if(i == ansl)
            {
                rans[p++] = ':';
                rans[p++] = ':';
                i +=  maxl-1;
                flag = 0;
                continue;
            }
            if(i % 4 == 1 && i != 1 && flag)
            {
                rans[p++] = ':';
            }
            if(ans[i] == '0' && i % 4 == 1)
            {
                int j;
                for(j = 0;j < 4;j++)
                {
                    if(ans[i+j] != '0') break;
                }
                i += j - 1;
                if(j == 4) rans[p++] = '0';
            }
            else
            {
                rans[p++] = ans[i];
            }
            flag = 1;
        }
        rans[p] = '\0';
        mycase(cnt,rans);
 
    }
    return 0;
}