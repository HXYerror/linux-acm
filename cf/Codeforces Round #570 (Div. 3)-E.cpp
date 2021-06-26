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
const int MOD = 10;//998244353;
LL T,N,M;
/*-------------------------------------------------------------------------------------------*/
map<string,int> a;
string str;
int flag[MAX];
int cnt = 0;
int ans = 0;
/* ------------------------------------------------------------------------------------------*/
void add(int n)
{
    string s(N-n,'0');
    int cmt = 0;
    for(int i = 0;i < N;i++)
    {
        if(!flag[i]) s[cmt++] = str[i];
    }
    //cout << s <<endl;
    if(a.find(s) == a.end())
    {
        a[s] = 1;
        ans += n;
        //cout << ans <<endl;
        cnt++;
    }
}
 
void dfs(int n,int deep,int m)
{
    for(int i = n;i < N;i++)
    {
        if(i > n && str[i] == str[i-1]) continue;
        if(cnt == M) return;
        if(deep == m)
        {
            flag[i] = 1;
            add(m);
            flag[i] = 0;
        }
        else
        {
            flag[i] = 1;
            dfs(i+1,deep+1,m);
            flag[i] = 0;
        }
 
    }
}
 
 
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    //ÿ���ǹ���һ������������ͬ
    //�������ǹ����ã�ÿ������Ҳ����ȫ���ǹ�
    cin >> N >> M;
    cin >> str;
    a[str] = 1;
    cnt++;
    for(int i = 1;i < N;i++)
    {
        dfs(0,1,i);
    }
    if(cnt == M) cout << ans <<endl;
    else if(cnt == M-1) cout << ans + N <<endl;
    else cout << "-1" << endl;
    return 0;
}