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
bool solve(ll n)
{


   fu(i,0,11,1)
   {
       ll d=n-i*111;
       if(n-i*111<0)
       {
           return false;
        }
        if(d%11==0)
        {
            return true;
        }
   }
   return false;
}
void nhap()
{
    int t;
    ll n;
    cin >> t;
    ll u=__gcd(111,11);
    //cout << (111*11/u)/111 << endl;
    fu(i,1,t,1)
    {
        cin >> n;

        if(solve(n)==true)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }

    }
}
int main()
{
    fastio();
    nhap();
}

