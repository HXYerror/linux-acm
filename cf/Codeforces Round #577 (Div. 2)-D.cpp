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
const int MAX = 200010;//100000
const int MAX_1 = 2;
const int MAX_2 = 1000010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;//998244353;
const double PI = acos(-1);
LL T,N,M,K;
/*-------------------------------------------------------------------------------------------*/
int Left[MAX];//最左边的宝藏
int Right[MAX];//最右边的宝藏
int lsafe[MAX];//当前列左边最近的出口
int rsafe[MAX];//当前列右边最近的出口
vector<int> b;//安全出口
/* ------------------------------------------------------------------------------------------*/
 
void lsize(int mid,LL *r, LL *l,int i)
{
    LL t1,t2;
    t1 = abs(mid - lsafe[mid])  + 1;
    t2 = abs(rsafe[mid] - mid)  + 1;
    *r =  min(abs(lsafe[mid] - Left[i] )  +  (Right[i] - Left[i]) + t1,abs(rsafe[mid] - Left[i] ) + (Right[i] - Left[i]) + t2);
    *l =  min(abs(lsafe[mid] - Right[i])  +  (Right[i] - Left[i]) + t1,abs(rsafe[mid] - Right[i]) + (Right[i] - Left[i]) + t2);
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* -----------------------------------------------------------------------------------------*/
    //2.选择左or右的宝藏
    //3.吃完一行的宝藏到达左or右
    //1.找到安全出口
    //现在吃完的宝藏步数最小
    int k,q;
    cin >> N >> M >> k >> q;
    int x,y;
    for(int i = 0;i < k;i++)//0代表没有宝藏
    {
        cin >> x >> y;
        if(Left[x] == 0)
        {
            Left[x] = Right[x] = y;
        }
        else
        {
            Left[x] = min(Left[x],y);
            Right[x] = max(Right[x],y);
        }
    }
    int temp;
    for(int i = 0;i < q;i++)
    {
        cin >> temp;
        b.push_back(temp);
    }
    sort(b.begin(),b.end());
    for(int i = 1;i <= M;i++)//INF没有安全
    {
        auto it = lower_bound(b.begin(),b.end(),i);
        if(it == b.end())
        {
            rsafe[i] = INF;
            it--;
            lsafe[i] = *it;
            continue;
        }
        if(it == b.begin())
        {
            if(*it == i) lsafe[i] = i;
            else lsafe[i] = -INF;
            rsafe[i] = *it;
            continue;
        }
        if(*it == i)
        {
            lsafe[i] = rsafe[i] = i;
        }
        else
        {
            rsafe[i] = *it;
            it--;
            lsafe[i] = *it;
        }
    }
    LL l,r;
    int L,R;
    if(Right[1])
    {
        l = Right[1] - 1 + Right[1] - Left[1];
        r = Right[1] - 1;
        R = Right[1];
        L = Left[1];
    }
    else
    {
        L = R = 1;
        l = r = 0;
    }
    LL cnt = 0;
    for(int i = 2;i <= N;i++)
    {
        if(!Right[i])
        {
            cnt++;
            continue;
        }
        LL ar,al;
        lsize(R,&ar,&al,i);
        LL br,bl;
        lsize(L,&br,&bl,i);
        LL tl,tr;
        tl = l + bl;
        tl = min(r + al,tl);
        tr = l + br;
        tr = min(r + ar,tr);
        L = Left[i];
        R = Right[i];
        l = tl + cnt;
        r = tr + cnt;
        cnt = 0;
    }
    cout << min(r,l) <<endl;
    return 0;
}