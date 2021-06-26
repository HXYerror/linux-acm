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
const int MAX = 150;//100000
const int MAX_1 = 2010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 10;//998244353;
int T,N,M;
/*-------------------------------------------------------------------------------------------*/
vector<int> a[MAX];
map<char,int> b;
/* ------------------------------------------------------------------------------------------*/
 
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    cin >> N;
    char c;
    for(int i = 1;i <= N;i++)
    {
        cin >> c;
        a[(int)c].push_back(i);
    }
    string s;
    cin >> M;
    while(M--)
    {
        cin >> s;
        b.clear();
        int ans = 1;
        for(int i = 0;i < s.size();i++)
        {
            b[s[i]]++;
            ans = max(ans,a[(int)s[i]][b[s[i]]-1]);
        }
        cout << ans <<endl;
    }
    return 0;
}