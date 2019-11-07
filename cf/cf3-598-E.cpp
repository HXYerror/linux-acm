/*************************************************************************
	> File Name: cf3-598-E.cpp
	> Author: HXYerror
	> Mail: zx841985525@163.com 
	> Created Time: 2019年11月06日 星期三 19时54分45秒
 ************************************************************************/

#include <bits/stdc++.h>
#define ll  long long
using namespace std;
const int MAX = 100010;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;//998244353;

ll T,N,M,K;
/* --------------------------------------------------------------------------------------------------*/
struct Pos
{
    int p;
    int v;
};
bool cmp(Pos a,Pos b)
{
    return a.v < b.v;
}

/* --------------------------------------------------------------------------------------------------*/

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
	//in
	//out
/* --------------------------------------------------------------------------------------------------*/
    cin >> N;
    int x;
    vector<Pos> a;
    Pos temp;
    for(int i = 0;i < N;i++)
    {
        cin >> x;
        temp.v = x;
        temp.p = i;
        a.push_back(temp);
    }
    return 0; 
}
