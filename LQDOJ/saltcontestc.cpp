#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b,c) for(int  i = a ; i <=b ;i+=c)
#define fd(i,a,b,c) for(int  i = a ; i >=b ;i-=c)
#define ll long long
#define SZ(c) c.size()
const ll maxsize = 5000;
const ll mod=int(1e9)+7;
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
     ll n,k,s[maxsize+5];
    cin >> n >> k;
    vector<vector<ll>>f(n+5,vector<ll>(k+5,0));
    vector<vector<ll>>dp(n+5,vector<ll>(k+5,0));
    ll x;
    fu(i,1,n,1)
    {
        cin >> x;
        f[i][1]=x;

        dp[i][1]=(dp[i-1][1]%mod+f[i][1]%mod)%mod;

        s[i]=x;
    }
    ll sum=0,l;
    fu(j,2,k,1)
    {
            fu(i,1,n,1)
    {


            f[i][j] = ((s[i]%mod)*((((dp[n][j-1]%mod)-(dp[i][j-1]%mod)+mod)%mod)%mod))%mod    ;
            dp[i][j]=(dp[i-1][j]%mod+f[i][j]%mod)%mod;
            cout << i << " " << j <<" "<< dp[i][j] << " " << f[i][j] << endl;
        }

    }

    cout << dp[n][k];
}
int main()
{

    fastio();
    // inti();
    nhap();
}

