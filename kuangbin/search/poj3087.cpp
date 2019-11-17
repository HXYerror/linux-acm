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
const int MAX = 110;
const int INF = 0xfffffff;//268435455,2e8;
const double EPS = 0.0000001;
const int MOD = 100;
int T,N,M;

//std::ios::sync_with_stdio(false);
/*-------------------------------------------------------------------------------------------*/

string s1;
string s2;
string s;
string e;
/* ------------------------------------------------------------------------------------------*/


int main()
{
    cin >> N;
    for(int j = 1;j <= N;j++)
    {
        cin >> M;
        cin >> s1 >> s2 >> e;
        map<string,int> flag;
        //cout << s1 << "\n" << s2 << "\n" << e << "\n";
        s = e;
        int ans = 0;
        while(1)
        {
            int k = 0;
            for(int i = 0;i < M;i++)
            {
                s[k++] = s2[i];
                s[k++] = s1[i];
            }
            ans++;
            if(flag.find(s) != flag.end())
            {
                cout << j <<" -1" << "\n";
                break;
            }
            else
            {
                flag[s] = 1;
            }
            if(s == e)
            {
                cout << j << " "<<ans << "\n";
                break;
            }
            s2 = s.substr(M,2*M);
            s1 = s.substr(0,M);
        }

    }
    return 0;

}
