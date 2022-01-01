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
    ll n, k,s=0,a[505];
    vector<vector<ll>>f(505,vector<ll>(505,0));
    vector<vector<ll>>dp(505,vector<ll>(505,0));
    cin >> n >> k;
    fu(i,1,n,1)
    {
        cin >> a[i];
        f[i][1]=a[i];
        dp[i][1]=max(f[i][1],dp[i-1][1]);
    }
    fu(i,2,n,1)
    {
        fu(j,2,k*3,1)
        {

            if((j+1)%3==0)
            {
                f[i][j]=-a[i];
            }
            else
            {
                f[i][j]=a[i];
            }
            ll c=0;
            fu(o,1,i-1,1)
            {
                c=max(c,f[i][j-1]);
            }
            f[i][j]+=c;
//            dp[i][j]=max(dp[i-1][j],f[i][j]);
//            //dp[i+1][j]=max(dp[i][j],dp[i+1][j]);
//            cout << i << " " << j << "  "<<dp[i][j] << endl;
        }
    }
    ll maxx=0;
    fu(i,1,n,1)
    {
        maxx=max(f[i][k*3],maxx);
    }
    cout << maxx << endl;

}
int main()
{

    fastio();
    // inti();
    nhap();
}

