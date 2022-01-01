#include<bits/stdc++.h>
using namespace std;
#define task "nendayso"
#define ll long long
#define SZ(c) c.size()
const ll maxsize = 100000;
long long mod = 1e9 ;
ll d[3][3],f[3][3],g[3][3];
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
ll nhan(ll a, ll b)
{
    ll c = 0;
    while (b)
    {
        if (b & 1)
        {
            c += a;
            if (c >= mod) c -= mod;
        }
        a += a;
        if (a >= mod) a -= mod;
        b /= 2;
    }
    return c;
}
void mul(ll m[3][3],ll h[3][3])
{
    ll ret[3][3];
    for( int i = 1 ; i <= 2; ++i)
    {
        for(int j = 1 ; j <= 2 ; ++j)
        {
            ret[i][j]=0;
            for(int k = 1 ; k <= 2; ++k)
            {
                ret[i][j]=((ret[i][j]%mod)+(nhan(d[i][k],h[k][j])%mod))%mod;
            }

        }
    }
    for(int i = 1 ; i <= 2; ++i)
    {
        for(int j = 1 ; j <= 2; ++j)
        {
            d[i][j]=ret[i][j];
        }
    }

}
void inti()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
void pow(ll m[3][3],ll n)
{
    if(n==1)return;
    pow(m,n/2);
    mul(m,m);
    if(n&1)
    {
        mul(m,g);
    }
}
void nhap()
{

    ll n,t;

        cin >> n ;
       g[1][1]=2;g[1][2]=1;
       g[2][1]=0;
       g[2][2]=2;
   for(int i =1;i<=2;i++)
   {
       for(int j =1 ;j<=2;++j)
       {
           d[i][j]=g[i][j];
       }
   }
   if(n<=1)
   {
       cout << n;
   }
   else
   {

            pow(d,n-1);
            //cout << d[1][1] << " " << d[1][2] << " " << d[2][1] << " " << d[2][2]<< endl;
            ll p=(d[1][2]%mod+d[2][2]%mod)%mod ;

            cout << p << endl;
   }

}
int main()
{

    fastio();
    inti();
    nhap();
}

