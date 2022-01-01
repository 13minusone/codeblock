#include<bits/stdc++.h>
using namespace std;
#define task ""
#define ll long long
#define SZ(c) c.size()
const ll maxsize = 100000;
long long mod = 1e15 + 7;
ll d[5][5],f[5][5],g[5][5];
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
void mul(ll m[5][5],ll h[5][5])
{
    ll ret[5][5];
    for( int i = 1 ; i <= 4 ; ++i)
    {
        for(int j = 1 ; j <= 4 ; ++j)
        {
            ret[i][j]=0;
            for(int k = 1 ; k <= 4 ; ++k)
            {
                ret[i][j]=((ret[i][j]%mod)+(nhan(d[i][k],h[k][j])%mod))%mod;
            }

        }
    }
    for(int i = 1 ; i <= 4 ; ++i)
    {
        for(int j = 1 ; j <= 4 ; ++j)
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
void pow(ll m[5][5],ll n)
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
    cin >> t;
    for( int j = 1 ; j <= t ; ++j)
    {
        cin >> n ;
        g[1][1]=g[1][2]=g[1][3]=g[1][4]=1;
        g[2][1]=0,g[2][2]=g[2][3]=g[2][4]=1;
        g[3][1]=g[3][3]=g[3][4]=0;
        g[3][2]=1;
        g[4][1]=g[4][2]=g[4][4]=0;
        g[4][3]=1;
        d[1][1]=1;
        d[1][2]=1 ;
        d[1][3]=1 ;
        d[1][4]=1;
        d[2][1]=0;
        d[2][2]=1 ;
        d[2][3]=1 ;
        d[2][4]=1;
        d[3][1]=0;
        d[3][2]=1 ;
        d[3][3]=0 ;
        d[3][4]=0;

        d[4][1]=0;
        d[4][2]=0 ;
        d[4][3]=1 ;
        d[4][4]=0;


        if(n<=3)
        {
            long long res = 0;
            for (int i = 1; i<=n; i++) res += i;
            cout<<res << endl;
        }
        else
        {
            pow(d,n-3);
            //cout << d[1][1] << endl;
            ll p=((6*d[1][1])%mod+(3*d[1][2])%mod+(2*d[1][3])%mod+(d[1][4])%mod)%mod ;
            cout << p << endl;
        }
    }

}
int main()
{

    fastio();
    // inti();
    nhap();
}


