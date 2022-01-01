#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b,c) for(int  i = a ; i <=b ;i+=c)
#define fd(i,a,b,c) for(int  i = a ; i >=b ;i-=c)
#define ll long long
#define SZ(c) c.size()
const ll maxsize = 100000;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void inti()
{
    freopen(".inp","r",stdin);
    freopen(".our","w",stdout);
}
ll n,d=0,l=0,g=0;
string s;
void nhap()
{
    cin >> n;
    cin >> s;
    stack<char>st;
    fu(i,0,n-1,1)
    {
        if(s[i]=='(')
        {
            d=i;
            break;
        }
        else
        {
            d++;
        }
    }
    ll s1=0,se=0;
    fu(i,d,n-1,1)
   {
    if(s[i]=='(')
    {
        s1++;
    }
    else
    {
        if(s1>=1)
        {
            s1--;
            l++;
        }
    }
   }
   cout << 2*l;
}
int main()
{
    fastio();
    nhap();
}

