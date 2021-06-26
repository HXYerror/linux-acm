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
vector<int> b;
map<int,int> a;
map<int,int> c;
/* ------------------------------------------------------------------------------------------*/
 
 
 
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
    cin >> T;
    while(T--)
    {
        cin >> N;
        int x;
        for(int i = 0;i < N;i++)
        {
            cin >> x;
            a[x]++;
        }
        int ans = 0;
        for(auto it = a.begin();it!=a.end();it++)//��������
        {
            b.push_back(it->second);
        }
        sort(b.begin(),b.end());
        for(int i = 0;i < b.size();i++)
        {
            if(c.find(b[i]) == c.end())
            {
                c[b[i]]=0;
                ans += b[i];
            }
            else
            {
                int n = b[i];
                while(n--)
                {
                    if(c.find(n) == c.end())
                    {
                        ans += n;
                        c[n] = 0;
                        break;
                    }
                }
            }
        }
        cout << ans <<endl;
 
        a.clear();
        b.clear();
        c.clear();
    }
    return 0;
}