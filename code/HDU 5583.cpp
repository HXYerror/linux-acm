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
const int MAX = 100010;//100000
const int MAX_1 = 2010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;
const double PI = acos(-1);
LL T,N,M;
/*-------------------------------------------------------------------------------------------*/
LL sum[MAX];
LL sqsum[MAX];
/* ------------------------------------------------------------------------------------------*/

void mycase(int n)
{
    cout << "Case #" << n <<": ";
}

LL befores(string str,int *cnt)
{
    LL ans = 0;
    for(int i = 0;i < str.size();i++)
    {
        if(i > 0)
        {
            if(str[i] == str[i-1])
            {
                sum[*cnt]++;
            }
            else
            {
                sqsum[*cnt] = sum[*cnt]*sum[*cnt];
                ans += sqsum[*cnt];
                (*cnt)++;
                sum[*cnt]++;
            }
        }
        else sum[*cnt]++;
    }
    sqsum[*cnt] = sum[*cnt]*sum[*cnt];
    ans += sqsum[*cnt];
    (*cnt)++;
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    //min shang or you
    cin >> T;
    int CNT = 0;
    while(T--)
    {
        CNT++;
        LL ans = 1;
        string str;
        cin >> str;
        fill(sum,sum+MAX,0);
        int cnt = 0;
        LL tempsum = befores(str,&cnt);
        LL tempsq;
        for(int i = 1;i < cnt;i++)
        {
            if(sum[i] <= sum[i-1])
            {
                if(sum[i] == 1)
                {
                    if(i+1>=cnt) sqsum[i+1] = sum[i+1] = 0;

                    LL n = (sum[i-1]+1+sum[i+1]);
                    tempsq = n*n;
                    ans = max(ans,tempsum - sqsum[i-1]-sqsum[i]-sqsum[i+1] + tempsq);
                }
                else
                {
                    LL n = sum[i-1]+1;
                    LL m = sum[i]-1;
                    tempsq = n*n+m*m;
                    ans = max(ans,tempsum - sqsum[i-1]-sqsum[i]+ tempsq);
                }
            }
            else
            {
                LL n = sum[i-1]-1;
                LL m = sum[i]+1;
                tempsq = n*n+m*m;
                ans = max(ans,tempsum - sqsum[i-1]-sqsum[i]+ tempsq);
            }
        }
        ans = max(ans,tempsum);
        mycase(CNT);
        cout<<ans <<"\n";
    }

    return 0;
}