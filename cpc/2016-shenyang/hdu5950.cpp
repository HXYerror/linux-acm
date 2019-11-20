/*************************************************************************
	> File Name: hdu5950.cpp
	> Author: HXYerror
	> Mail: zx841985525@163.com 
	> Created Time: 2019年11月20日 星期三 20时09分18秒
 ************************************************************************/

#include <bits/stdc++.h>
#define ll  long long
using namespace std;
const int MAX = 100010;
const int INF = 0x3f3f3f3f;
const ll MOD = 2147493647;
const int MAX_1 = 7;
ll T,N,M,K;
/* --------------------------------------------------------------------------------------------------*/
ll getmatrix[MAX_1][MAX_1] = 
{
    1,1,0,0,0,0,0,
    2,0,0,0,0,0,0,
    1,0,1,0,0,0,0,
    4,0,4,1,0,0,0,
    6,0,6,3,1,0,0,
    4,0,4,3,2,1,0,
    1,0,1,1,1,1,1
};
ll ans[MAX_1][MAX_1];
ll ansmatrix[MAX_1];
ll temp[MAX_1][MAX_1];
/* --------------------------------------------------------------------------------------------------*/
void init(ll a[][MAX_1])
{
    for(int i = 0;i < MAX_1;i ++)
    {
        for(int j = 0;j < MAX_1;j++)
        {
            a[i][j] = getmatrix[i][j];
            if(i == j) temp[i][j] = 1;
            else temp[i][j] = 0;
        }
    }
}

void calculate(ll a[][MAX_1],ll b[][MAX_1])
{
    ll  c[MAX_1][MAX_1];
    for(int i = 0;i < MAX_1;i++)
    {
        fill(c[i],c[i]+MAX_1,0);
    }
    for(int i = 0;i < MAX_1;i++)
    {
        for(int j = 0;j < MAX_1;j++)
        {
            for(int k = 0;k < MAX_1;k++)
            {
                c[i][j] += (a[i][k] * b[k][j]) % MOD;
                c[i][j] = c[i][j] % MOD;
            }
        }
    }
    for(int i = 0;i < MAX_1;i++)
    {
        for(int j = 0;j < MAX_1;j++)
        {
            a[i][j] = c[i][j];
        }
    }
}

void Q()
{
    while(K)
    {
        if(K & 1) calculate(temp,ans);
        calculate(ans,ans);
        K >>= 1;
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
    cin >> T;
    while(T--)
    {
        cin >> K >> N >> M;
        init(ans);
        ansmatrix[0] = M;
        ansmatrix[1] = N;
        ansmatrix[2] = 16;
        ansmatrix[3] = 8;
        ansmatrix[4] = 4;
        ansmatrix[5] = 2;
        ansmatrix[6] = 1;
        K -= 2;
        Q();
        ll endans = 0;
        //for(int i = 0;i < MAX_1;i++)
        //{
            //for(int j = 0;j < MAX_1;j++)
            //{

                //cout << temp[i][j] << " ";
            //}
            //cout << endl;
        //}
        for(int i = 0;i < MAX_1;i++)
        {
            endans += (ansmatrix[i] * temp[i][0]) % MOD;
            endans %= MOD;
        }
        cout << endans << "\n";
    }
    return 0;
}

