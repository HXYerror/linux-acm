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
const int MAX = 200010;
const int MAX_1 = 1000100;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;
int T,N,M;


/*-------------------------------------------------------------------------------------------*/
map<char,int> q;
char letter[5] = {'x','t','C','p','c'};
/* ------------------------------------------------------------------------------------------*/

char fin(char c)
{
    if(c == 't') return 'x';
    else if(c == 'C') return 't';
    else if(c == 'p') return 'C';
    else if(c == 'c') return 'p';
}

int main()
{
    //std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    while(cin >> N)
    {
        q.clear();
        for(int i = 0;i < 5;i++)
        {
            q[letter[i]] = 0;
        }
        int ans = 0;
        char x;
        for(int i = 0;i < N;i++)
        {
            cin >> x;
            auto it = q.find(x);
            if(it != q.end())
            {

                if(it->first == 'x')
                {
                    it->second++;
                }
                else
                {
                    char b = fin(it->first);
                    if(q[b] > 0)
                    {
                        q[b]--;
                        it->second++;
                        if(it->first == 'c')
                        {
                            it->second--;
                            ans++;
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
