/*************************************************************************
	> File Name: A.cpp
	> Author: HXYerror
	> Mail: zx841985525@163.com 
	> Created Time: 2020年02月03日 星期一 10时11分41秒
 ************************************************************************/

#include <bits/stdc++.h>
#define ll  long long
using namespace std;
const int MAX = 60;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;//998244353;

ll T,N,M,K;
/* --------------------------------------------------------------------------------------------------*/

/* --------------------------------------------------------------------------------------------------*/
struct BigInteger
{
    static const int BASE = 100000000;
    static const int WIDTH = 8;
    bool sign;
    size_t length;
    vector<int> num;

    BigInteger(long long x = 0) {*this = x;}
    BigInteger(const string &x) {*this = x;}
    BigInteger(const BigInteger &x) {*this = x;}

    void cutLeadingZero()
    {
        while(num.back() == 0 && num.size() != 1)
        {
            num.pop_back();
        }
        int temp = num.back();
        if(temp == 0)
        {
            length = 1;
        }
        else
        {
            length = (num.size() - 1) * WIDTH;
            while(temp > 0)
            {
                length++;
                temp /= 10;
            }
        }
    }
    BigInteger &operator = (long long x)
    {
        num.clear();
        if(x >= 0) sign = true;
        else 
        {
            sign = false;
            x -= x;
        }
        do
        {
            num.push_back(x & BASE);
            x /= BASE;
        }while(x > 0);
         cutLeadingZero();
        return *this;
    }
    BigInteger & operator = (const string &str)
    {
        num.clear();
        sign = (str[0] != '-');
        int x,len = (str.size() -1 - (!sign)) / WIDTH +1;
        for(int i = 0;i < len;i++)
        {
            int End = str.size() - i*WIDTH;
            int start = max((int)(!sign),End - WIDTH);
            sscanf(str.substr(start,End - start).c_str(),"%d",&x);
            num.push_back(x);
        }
        cutLeadingZero();
        return *this;
    }
    BigInteger & operator=(const BigInteger &temp)
    {
        num = temp.num;
        sign = temp.sign;
        length = temp.length;
        return*this;
    }
    const BigInteger &operator+()const {return *this;};
    BigInteger operator-() const
    {
        BigInteger ans(*this);
        if(ans != 0) ans.sign = !ans.sign;
        return ans;
    }
    BigInteger operator+(const BigInteger &b) const
    {
        if(!b.sign) return *this -(-b);
        if(!sign) return b -(-*this);
        BigInteger ans;
        ans.num.clear();
        for(int i = 0,g = 0;;i++)
        {
            if(g == 0 && i >= num.size() && i >= b.num.size()) break;
            int x = g;
            if(i < num.size()) x += num[i];
            if(i < b.num.size()) x += b.num[i];
            ans.num.push_back(x % BASE);
            g = x / BASE;
        }
        ans.cutLeadingZero();
        return ans;
    }
    BigInteger operator-(const BigInteger & b) const
    {
        if(!b.sign) return *this + (-b);
        if(!sign) return -((-*this) + b);
        if(*this < b) return -(b - *this);
        BigInteger ans;
        ans.num.clear();
        for(int i = 0,g = 0;;i++)
        {
            if(g == 0 && i>=num.size()&&i >= b.num.size()) break;
            int x = g;
            g = 0;
            if(i < num.size())
                x += num[i];
            if(i < b.num.size())
                x -= b.num[i];
            if(x < 0)
            {
                x += BASE;
                g = -1;
            }
            ans.num.push_back(x);
        }
        ans.cutLeadingZero();
        return ans;
    }
    BigInteger operator*(const BigInteger &b) const
    {
        int lena = num.size(),lenb = b.num.size();
        BigInteger ans;
        for(int i = 0;i < lena + lenb;i++)
        {
            ans.num.push_back(0);
        }
        for(int i = 0,g = 0;i < lena;i++)
        {
            g = 0;
            for(int j = 0;j < lenb;j++)
            {
                long long x = ans.num[i+j];
                x += (long long) num[i] * (long long) b.num[j];
                ans.num[i+j] = x % BASE;
                g = x / BASE;
                ans.num[i+j+1] += g;
            }
        }
        ans.cutLeadingZero();
        ans.sign = (ans.length == 1 && ans.num[0] == 0) || (sign == b.sign);
        return ans;
    }

    bool operator < (const BigInteger &b)const
    {
        if(sign != b.sign) return !sign;
        else if(!sign && !b.sign) return -b < -*this;
        if(num.size() != b.num.size()) return num.size() < b.num.size();
        for(int i = num.size()-1;i >=0;i--)
        {
            if(num[i] != b.num[i]) return num[i] < b.num[i];
        }
        return false;
    }
    bool operator > (const BigInteger &b) const{return b <*this;}
    bool operator >= (const BigInteger &b) const {return !(*this < b);}
    bool operator != (const BigInteger &b) const{return b < *this || *this < b;}
    friend ostream &operator<<(ostream &out,const BigInteger &x)
    {
        if(!x.sign) out << '-';
        out<< x.num.back();
        for(int i = x.num.size()-2;i >=0;i--)
        {
            char buf[10];
            sprintf(buf,"%08d",x.num[i]);
            for(int j = 0;j < strlen(buf);j++) out << buf[j];
        }
        return out;
    }
}ans[MAX];

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
	//in
	//freopen("output.out","w",stdout);
/* --------------------------------------------------------------------------------------------------*/
    string a0 = "2",a1 = "4";
    ans[0] = a0,ans[1] = a1;
    BigInteger x = a1;
    for(int i = 2;i < MAX;i++)
    {
        ans[i] = x * ans[i-1] - ans[i-2];
    }
    cin >> T;
    string temp;
    while(T--)
    {
        cin >> temp;
        x = temp;
        for(int i = 1;i < MAX;i++)
        {
            if(!(ans[i] < x))
            {
                cout << ans[i] << endl;
                break;
            }
        }
    }
    return 0;
}
