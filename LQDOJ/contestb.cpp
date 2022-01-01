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
void nhap()
{
    int n;
    ll p,s=0;
    cin >> n >> p;
    fu(i,1,n,1)
    {
        if(__gcd(i,n)==p)
        {
            s++;
        }
    }
    cout << s << endl;
}
int main()
{
    fastio();
    nhap();
}

