/*************************************************************************
	> File Name: C.cpp
	> Author: HXYerror
	> Mail: zx841985525@163.com 
	> Created Time: 2020年02月05日 星期三 16时01分03秒
 ************************************************************************/

#include <bits/stdc++.h>
#define ll  long long
using namespace std;
const int MAX = 100010;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;//998244353;

ll T,N,M,K;
/* --------------------------------------------------------------------------------------------------*/
vector<double> x,y;
/* --------------------------------------------------------------------------------------------------*/

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
	//in
	//out
/* --------------------------------------------------------------------------------------------------*/
    ll X,Y;
    cin >> X >> Y;
    cin >> N >> M;
    double a,b;
    for(int i = 0;i < N;i++)
    {
        cin >> a >> b;
        double k = (b - Y) / (a - X);
        if(a*X < 0) 
        {
            y.push_back(Y - k*X);
        }
        if(b*Y < 0)
        {
            x.push_back(Y/k - X);
        }
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    if(N - x.size() > M  && N - y.size() > M)
    {
        cout << -1 << endl;
        return 0;
    }
    double ans = 1e18;
    K = N - M;
    if(N - x.size() <= M)
    {
        int j = K-1;
        for(int i = 0;i < x.size();i++)
        {
            ans = min(ans,x[j] - x[i]);
            j++;
            if(j == x.size()) break;
        }
    }
    if(N - y.size() <= M)
    {
        int j = K-1;
        for(int i = 0;i < y.size();i++)
        {
            ans = min(ans,y[j] - y[i]);
            j++;
            if(j == y.size()) break;
        }
    }
    cout << fixed << setprecision(8)<<ans << endl;
    return 0;
}

