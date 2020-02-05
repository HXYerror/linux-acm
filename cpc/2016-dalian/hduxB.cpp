/*************************************************************************
	> File Name: hduxB.cpp
	> Author: HXYerror
	> Mail: zx841985525@163.com 
	> Created Time: 2019年11月22日 星期五 17时36分41秒
 ************************************************************************/

#include <bits/stdc++.h>
#define ll  long long
using namespace std;
const int MAX = 100010;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;//998244353;

ll T,N,M,K;
/* --------------------------------------------------------------------------------------------------*/
int ans[MAX];
vector<int> mark;
int maxx = 0;
/* --------------------------------------------------------------------------------------------------*/
void dfs(int a,int step,int summ,int suma)
{
    if(suma == N)
    {
        if(summ > maxx)
        {
            maxx =summ;
            mark.clear();
            for(int i = 0;i < step;i++)
            {
                mark.push_back(ans[i]);
            }
        }
        return;
    }
    for(int i = a+1;i <= N;i++)
    {
        if(suma + i > N) return;
        ans[step] = i;
        dfs(i,step+1,summ*i,suma+i);
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
	//in
	//out
/* --------------------------------------------------------------------------------------------------*/
    while(cin >> N)
    {
        maxx = 0;
        dfs(0,0,1,0);
        for(int i = 0;i < mark.size();i++)
        {
            cout << mark[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

