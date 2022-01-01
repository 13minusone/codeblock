#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b,c) for(int  i = a ; i <=b ;i+=c)
#define fd(i,a,b,c) for(int  i = a ; i >=b ;i-=c)
#define ll long long
#define SZ(c) c.size()
const ll mod = int(1e9)+7;
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
ll chap(ll x, ll y)
{
    unsigned ll s = x;
    fu(i,1,y,1)
    {
        s=s*(x-i);
        s=s/i;
    }
    s/=(x-y);
    return s;
}
void nhap()
{
    ll n,m;
    cin >> n >> m ;
    string s;
    cin >> s;
    cout << chap(2000,1001) << endl;
    ll d=0;
    fu(i,0,m-1,1)
    {
        if(s[i]=='(')
        {
            d++;
        }
        else
        {
            d--;
        }
    }
    fu(i,1,n,1)
    {
        fu(j,1,i,1)
        {

        }
    }

}
int main()
{
    fastio();
    nhap();
}

