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
const int MAX = 62;//100000
const int MAX_1 = 2010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;
const double PI = acos(-1);
LL T,N,M;
/*-------------------------------------------------------------------------------------------*/
LL tpow[MAX];
int ans[MAX];
/* ------------------------------------------------------------------------------------------*/
void mycase(int n)
{
    cout << "Case #" << n <<":" <<endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    cin >> T;
    int CNT = 0;
    for(int i =0;i < MAX;i++)
    {
        tpow[i] = 1 << i;
    }
    while(T--)
    {
        CNT++;
        cin >> N >> M;
        LL sum = 0;
        int flag = 0;
        for(int i =0;i < M;i++)
        {
            sum += tpow[i];
            ans[i] = 1;
        }
        if(!(N&1)) flag = 1;
        sum += flag;
        LL cha = sum - N;
        cha >>= 1;
        int i = 0;
        while(cha)
        {
            int x = cha&1;
            ans[i] = ans[i]-x;
            i++;
            cha>>=1;
        }
        mycase(CNT);
        for(int j = 0;j < M-1;j++)
        {
            cout << tpow[j] << " ";
            if(ans[j]) cout << "+"<<endl;
            else cout << "-" <<endl;
        }
        cout << tpow[M-1] + flag<< " ";
        if(ans[M-1]) cout << "+"<<endl;
        else cout << "-" <<endl;
    }
    return 0;
}