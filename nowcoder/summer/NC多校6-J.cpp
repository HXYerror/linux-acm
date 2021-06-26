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
LL lesum[MAX];//奖励和
LL temax[MAX][MAX];//i技能学到j时，再向上能赚多少
LL temsum[MAX];//j时，向上赚的和
LL tesum[MAX];//1 - i层的技能消耗和
LL a[MAX][MAX];//技能
/* ------------------------------------------------------------------------------------------*/
  
void mycase(int x,LL ans)
{
    cout << "Case #" << x <<": "<<ans <<endl;
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
    while(T--)
    {
        cnt++;
        cin >> N >> M;
        for(int i = 1;i <= N;i++)
        {
            a[i][0] = 0;
            for(int j = 1;j <= M;j++)
            {
                cin >> a[i][j];//技能
            }
        }
  
        lesum[0] = 0;
        LL level;
        for(int i = 1;i <= M;i++)
        {
            cin >> level;//奖励
            lesum[i] = level + lesum[i-1];//奖励和
        }
  
        fill(tesum,tesum+MAX,0);
        for(int i = 1;i <= N;i++)
        {
            temax[i][M] = 0;
            tesum[M] += a[i][M];
            for(int j= M-1 ; j >= 0;j--)
            {
                tesum[j] += a[i][j];
                temax[i][j] = min(a[i][j+1]+ temax[i][j+1],min(a[i][j+1],(LL)0));
            }
        }
  
        fill(temsum,temsum+MAX,0);
        for(int i = 0;i <= M;i++)
        {
            tesum[i] += tesum[i-1];//等级都到i的花费
            for(int j = 1;j <= N;j++)
            {
                temsum[i] += temax[j][i];
            }
        }
        LL ans = 0;
        LL temp;
        for(int i = 1;i <= N;i++)
        {
            for(int j = 0;j <= M;j++)
            {
                temp = lesum[j] - tesum[j] - temsum[j] + temax[i][j];
                ans = max(ans,temp);
            }
        }
        mycase(cnt,ans);
    }
    return 0;
}