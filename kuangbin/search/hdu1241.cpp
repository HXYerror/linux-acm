#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;
const int MAX = 100;

char Map[MAX + 5][MAX + 5];
int flag[MAX + 5][MAX + 5];
int to[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
int m,n;
void Find(int x,int y)
{
    int Tx,Ty;
    for(int i =0;i < 8;i++)
    {
        Tx = x + to[i][0];
        Ty = y + to[i][1];
        if(!flag[Tx][Ty] && Map[Tx][Ty] == '@' && Tx < m && Ty < n)
        {
            flag[Tx][Ty] = 1;
            Find(Tx,Ty);
        }
    }
}

int main()
{
    while(cin >> m >> n && !(m==0 && n ==0))
    {
        int ans = 0;
        getchar();
        for(int i = 0;i < m;i++)
        {
            cin.getline(Map[i],n+1);
        }//读入地图

        for(int i =0;i < MAX + 5;i++)
        {
            for(int j = 0;j < MAX + 5;j++)
            {
                flag[i][j] = 0;
            }
        }//重置flag

        for(int i =0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(!flag[i][j] && Map[i][j] == '@')
                {
                    ans++;
                    Find(i,j);
                }
            }
        }//搜索
        cout << ans << endl;//输出答案
    }
}
