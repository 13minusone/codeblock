#include<bits/stdc++.h>
using namespace std;
#define task "loco"
#define ll long long
#define SZ(c) c.size()
const ll maxsize = 100000;
long long mod ;
ll d[4][4],f[4][4],g[4][4];
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
void mul(ll m[4][4],ll h[4][4])
{
    ll ret[4][4];
    for( int i = 1 ; i <= 3 ; ++i)
    {
        for(int j = 1 ; j <= 3 ; ++j)
        {
            ret[i][j]=0;
            for(int k = 1 ; k <= 3 ; ++k)
            {
                ret[i][j]=((ret[i][j]%mod)+(nhan(d[i][k],h[k][j])%mod))%mod;
            }

        }
    }
    for(int i = 1 ; i <= 3 ; ++i)
    {
        for(int j = 1 ; j <= 3 ; ++j)
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
void pow(ll m[4][4],ll n)
{
    if(n<=1)return;
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


        cin >> n >> t ;
        mod=t;
        g[1][1]=g[1][2]=g[1][3]=1;
        g[2][1]=1;
        g[3][2]=1;
        for(int i =1 ;i<=3;i++)
        {
            for(int j=1;j<=3;j++)
            {
                d[i][j]=g[i][j];
            }
        }
        if(n<=2)
        {
            cout << n;
        }
        else
        {
            pow(d,n);

            ll p =d[1][1] ;
            cout << p << endl;
        }


}
int main()
{

    fastio();
    inti();
    nhap();
}
