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
vector<vector<ll>>f(500+9,vector<ll>(501*(500/4)+1,0));
void nhap()
{
    ll n;
    cin >> n;
    ll s=0;
    if(n%2==0)
    {
        s=s+(n+1)*(n/2);
    }
    else
    {
        ll mid=n/2;
        s=s+(n+1)*(mid)+mid+1;


    }

    if(s%2!=0)
    {
        cout << 0 << endl;
    }
    else
    {
        ll d=s/2;

        f[0][0]=1;

        fu(i,1,n-1,1)
        {
            fu(j,0,d,1)
            {
                f[i][j]=f[i-1][j];
                if(j>=i)
                {
                    f[i][j]+=f[i-1][j-i];
                    f[i][j]%=mod;
                }

            }
        }
        cout << f[n-1][d];
    }

}
int main()
{
    fastio();
    nhap();
}

