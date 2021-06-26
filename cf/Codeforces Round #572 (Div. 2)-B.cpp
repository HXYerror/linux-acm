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
int T,N,M;
/*-------------------------------------------------------------------------------------------*/
vector<int> a;
int b[MAX];
/* ------------------------------------------------------------------------------------------*/
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------*/
    cin >> N;
    int x;
    for(int i = 0;i < N;i++)
    {
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(),a.end(),greater<int>());
    if(a[0] >= a[1]+a[2])
    {
        cout << "NO";
        return 0;
    }
    cout << "YES" <<endl;
    int i,j;
    i = j = 100000;
    b[i--] = a[0];
    int k = 1;
    while(k < N)
    {
        b[i--] = a[k++];
        if(k >= N) break;
        b[++j] = a[k++];
    }
    for(i = i+1;i <= j;i++)
    {
        cout << b[i];
        if(i != j) cout << " ";
    }
    return 0;
}