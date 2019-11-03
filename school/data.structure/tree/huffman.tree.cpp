/*************************************************************************
	> File Name: huffman.tree.cpp
	> Author: HXYerror
	> Mail: zx841985525@163.com 
	> Created Time: 2019年11月03日 星期日 14时41分28秒
 ************************************************************************/

#include <bits/stdc++.h>
#define ll  long long
using namespace std;
const int MAX = 100010;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;//998244353;

/* --------------------------------------------------------------------------------------------------*/
struct piece
{
    double x;
    int flag;
};
bool cmp(piece  a,piece  b)
{
    return a.x < b.x;
}
/* --------------------------------------------------------------------------------------------------*/

int main()
{
    double N;
    int M;
    cout << "Please input the length n of the board and the number m  of you what cut :";
    cin >> N >> M;
    cout << "Please input m number of the length of piece:";
    vector<piece> a;
    vector<double> ans;
    piece y;
    double x;
    for(int i = 0; i < M;i++)
    {
        cin >> x;
        y.x = x;
        y.flag = 1;
        a.push_back(y);
    }
    sort(a.begin(),a.end(),cmp);
    double anspay = 0;
    while(a.size() != 1)
    {
        double temp = a[0].x + a[1].x;
        anspay = anspay + temp;
        if(a[0].flag) ans.push_back(a[0].x);
        if(a[1].flag) ans.push_back(a[1].x);
        a.erase(a.begin()),a.erase(a.begin());
        auto it = a.begin();
        y.x = temp;
        y.flag = 0;
        for(;it != a.end();it++)
        {
            if(it->x  >= temp) 
            {
                a.insert(it,y);
                break;
            }
        }
        if(it == a.end()) a.push_back(y);
    }
    cout <<"the pay is:" <<anspay<< endl;
    for(int i = M-1;i >= 0;i--)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}

