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
ll a[2*maxsize+5];
map<ll,ll>f;
void nhap()
{
    ll n,maxx=-1,r;
    cin >> n;
    fu(i,1,n,1)
    {
        cin >> a[i];
        if(f[a[i]]==0)
        {
            f[a[i]]=f[a[i]-1]+1;
        }
    if(f[a[i]]>maxx)
    {
        maxx=f[a[i]];
        r=a[i];
    }

    }
    vector<ll>vec;
    cout << maxx << endl;
    fd(i,n,1,1)
    {
        if(a[i]==r)
        {
            vec.push_back(i);
           r--;
        }

    }
    fd(i,maxx-1,0,1)
    {
        cout << vec[i] << " ";
    }

}
int main()
{
    fastio();
    nhap();
}

