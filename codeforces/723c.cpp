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
    ll n;
    ll a[2005];
    pair<int,int> f[2005][2005];
    cin >> n;
    fu(i,1,n,1)
    {
        cin >> a[i];
    }
    f[1][1].first=a[1];
    f[1][1].second=1;

    fu(i,2,n,1)
    {
       fd(j,i-1,1,1)
       {
           if(f[i])
       }
    }
}
int main()
{
    fastio();
    inti();
}

