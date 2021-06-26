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
const int MAX = 505;//100000
const int MAX_1 = 2010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;
int T,N,M;
/*-------------------------------------------------------------------------------------------*/
int mynext[MAX][MAX_1];
char str[MAX][MAX_1];
/* ------------------------------------------------------------------------------------------*/


void GetNextval(int n)
{
	int sLen = strlen(str[n]);
	mynext[n][0] = -1;
	int k = -1;
	int j = 0;
	while (j < sLen - 1)
	{
		if (k == -1 || str[n][j] == str[n][k])
		{
			++j;
			++k;
			if (str[n][j] != str[n][k])
				mynext[n][j] = k;
			else
				mynext[n][j] = mynext[n][k];
		}
		else
		{
			k = mynext[n][k];
		}
	}
}


bool KmpSearch(int s,int p)
{
	int i = 0;
	int j = 0;
	int sLen = strlen(str[s]);
	int pLen = strlen(str[p]);
	while (i < sLen && j < pLen)
	{
		if (j == -1 || str[s][i] == str[p][j])
		{
			i++;
			j++;
		}
		else
		{
			j = mynext[p][j];
		}
	}
	if (j == pLen)
		return true;
	else
		return false;
}


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    cin >> T;
    for(int t = 1;t <= T;t++)
    {
        cin >> N;
        for(int i = 1;i <= N;i++)
        {
            cin >> str[i];
        }
        cout << "Case #" << t << ": ";
        int ans = -1;
        for(int i = 1;i < N;i++)
        {
            GetNextval(i);
        }
        int j = 1;
        for(int i = 2;i <= N;i++)
        {
            while(i > j && KmpSearch(i,j))
            {
                j++;
            }
            if(i > j) ans = max(i,ans);
        }
        cout << ans <<endl;
    }
    return 0;
}