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
const int MAX = 200010;//100000
const int MAX_1 = 2010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;
const double PI = acos(-1);
LL T,N,M;
/*-------------------------------------------------------------------------------------------*/
char ans[][10]={{"1113"},{"2133"},{"2243"},{"2444"}};
/* ------------------------------------------------------------------------------------------*/

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    while(cin >> N >> M)
    {
        if(N % 4 != 0 || M % 4 != 0)
        {
            cout << "no response" <<endl;
        }
        else
        {
            for(int i = 0;i < N / 4;i++)
            {
                for(int k = 0;k < 4;k++)
                {
                    for(int j = 0;j < M/4;j++)
                    {
                        cout << ans[k];
                    }
                    cout <<endl;
                }

            }

        }
    }

    return 0;
}