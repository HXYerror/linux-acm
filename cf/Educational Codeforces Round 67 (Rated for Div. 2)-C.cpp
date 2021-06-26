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
const int MAX = 1020;//100000
const int MAX_1 = 2010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 10;//998244353;
int T,N,M;
/*-------------------------------------------------------------------------------------------*/
struct Pos
{
    int l,r;
};
Pos a1[MAX];
Pos a0[MAX];
int a[MAX];
int book[MAX][MAX];
/* ------------------------------------------------------------------------------------------*/
 
bool Cmp(Pos a,Pos b)
{
    if(a.l < b.l) return true;
    else if(a.l == b.l)
    {
        if(a.r <= b.r) return true;
        else return false;
    }
    else return false;
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    cin >> N >> M;
    Pos temp;
    int t,l,r;
    int cnt1 = 0;
    int cnt0 = 0;
    while(M--)
    {
        cin >> t >> l >> r;
        temp.l = l;
        temp.r = r;
        if(t == 1)
        {
            a1[cnt1] = temp;
            cnt1++;
        }
        else
        {
            a0[cnt0] = temp;
            cnt0++;
        }
    }
 
    sort(a1,a1+cnt1,Cmp);
    fill(a+1,a+N+1,1);
    for(int i = 0;i < cnt1;++i)
    {
        //cout << a1[i].l << " " << a1[i].r <<endl;
        for(int j = a1[i].l;j <= a1[i].r;j++)
        {
            if(!book[j][j+1]) a[j] = a[j-1]+1;
            if(j != a1[i].r) book[j][j+1] = 1;
        }
    }
    int flag = 1;
    for(int i = 0;i < cnt0;++i)
    {
        int j = 0;
        for(j = a0[i].l;j < a0[i].r;++j)
        {
            if(a[j] > a[j+1])
            {
                book[j][j+1] = 2;
                break;
            }
            else if(book[j][j+1] == 0 && book[j-1][j] != 2)
            {
                a[j] = a[j+1]+1;
                book[j][j+1] = 2;
                break;
            }
            else if(book[j][j+1] == 0 && book[j-1][j] == 2)
            {
                int k = j;
                book[j][j+1] = 2;
                a[k] = a[k+1]+1;
                while(k--)
                {
                    if(k == 0) break;
                    a[k] = max(a[k+1]+1,a[k]);
                    if(book[k-1][k] != 2)
                        break;
                }
                break;
            }
        }
        if(j == a0[i].r)
        {
            flag = 0;
            break;
        }
    }
    if(flag)
    {
        cout << "YES" <<endl;
        for(int i = 1;i <= N;i++)
        {
            cout << a[i];
            if(i != N) cout << " ";
            else cout <<endl;
        }
    }
    else cout << "NO" <<endl;
    return 0;
}