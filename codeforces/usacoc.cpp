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
ll a[maxsize+5],b[maxsize+5],f[maxsize+5],g[maxsize+5];
vector<ll>vec;
void nhap()
{
    ll n;

    cin >> n;

    fu(i,1,n,1)
    {
        cin >> a[i];
        f[a[i]]=i;
    }
    ll maxx=0;
    fu(i,1,n,1)
    {
        cin >> b[i];
 g[i]=f[b[i]];
    }

    fu(i,1,n,1)
    {
        ll k = lower_bound(vec.begin(),vec.end(),g[i])-vec.begin();
        if(k==vec.size())
        {
            vec.push_back(g[i]);

        }
        else
        {
            vec[k]=g[i];
        }
    }
    cout << vec.size();
}
int main()
{
    fastio();
    nhap();
}

