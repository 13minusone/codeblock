#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b,c) for(int  i = a ; i <=b ;i+=c)
#define fd(i,a,b,c) for(int  i = a ; i >=b ;i-=c)
#define ll long long
#define SZ(c) c.size()
const ll maxsize = 1000000;
const ll mod = int(1e9)+7;;
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
ll n,t,a[maxsize+5],f[maxsize+5];
void nhap()
{

    cin >> t >> n;
    fu(i,1,t,1)
    {
        cin >> a[i];

    }
    f[0]=1;
    fu(i,1,t,1)
    {
        fu(j,0,n,1)
        {
            if(j>=a[i])
            {
                f[j]+=f[j-a[i]];
                f[j]%=mod;
            }
        }
        //cout <<i << " "<< f[i] << endl;
    }
    cout << f[n];

}
int main()
{
    fastio();
    nhap();
}

