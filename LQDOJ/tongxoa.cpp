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
    int n,a[maxsize+2],d[maxsize+2],f[maxsize+2];
    ll s=0,maxx=0;
    cin >> n;

    fu(i,1,n,1)
    {
        cin >> a[i];
        s=s+a[i];
        d[a[i]]++;
    }
    fu(i,1,n,1)
    {
        f[a[i]]=max(f[a[i]-1],f[a[i]-2]+i*d[a[i]]);
    }
    cout << f[a[n]];
}
int main()
{
    fastio();
    nhap();
}

