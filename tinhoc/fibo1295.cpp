#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b,c) for(int  i = a ; i <=b ;i+=c)
#define fd(i,a,b,c) for(int  i = a ; i >=b ;i-=c)
#define ll long long
#define SZ(c) c.size()
const ll maxsize = 100000;
const ll mod=int(1e9)+7;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
ll f[3][3],m[3][3];
void nhan(ll d[3][3],ll c[3][3])
{
    ll g[4][4];
    fu(i,1,2,1)
    {
        fu(j,1,2,1)
        {
            g[i][j]=0;
            fu(k,1,2,1)
            {
                g[i][j]=g[i][j]+d[i][k]*c[k][j];

            }
        }
    }
    f[1][1]=g[1][1]%mod;
    f[1][2]=g[1][2]%mod;
    f[2][1]=g[2][1]%mod;
    f[2][2]=g[2][2]%mod;
}
void poww(ll d[3][3],ll n)
{
    if(n<=1)
    {
        return ;
    }
    poww(d,n/2);
    nhan(d,d);
    if(n&1)
    {
        nhan(d,m);
    }


}
void inti()
{
    freopen("fibo1295.inp","r",stdin);
    freopen("fibo1295.out","w",stdout);
}
void nhap()
{

    ll n,t;
    cin >>t;
    fu(i,1,t,1)
    {
         f[1][1]=1;
    f[1][2]=1;
    f[2][1]=1;
    f[2][2]=0;
    m[1][1]=1;
    m[1][2]=1;
    m[2][1]=1;
    m[2][2]=0;
        cin >> n;
        if(n==0)
        {
            cout << 0 <<endl;

        }
        else
        {
        poww(f,n-1);
        cout << f[1][1]<<endl;
        }
    }

}
int main()
{

    fastio();
     inti();
    nhap();
}

