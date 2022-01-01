#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b,c) for(int  i = a ; i <=b ;i+=c)
#define fd(i,a,b,c) for(int  i = a ; i >=b ;i-=c)
#define ll long long
#define SZ(c) c.size()
const ll maxsize = 200000;
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
    ll n,a[maxsize+5];
    cin >> n;
    vector<ll>vec;
    fu(i,1,n,1)
    {
        cin >> a[i];
        ll k=upper_bound(vec.begin(),vec.end(),a[i])-vec.begin();
        //cout << i << " " << k << endl;
        ll h=vec.size();
        if(k==h)
        {
            vec.push_back(a[i]);
        }
        else
        {
            vec[k]=a[i];
        }
    }
    cout << vec.size();
}
int main()
{
    fastio();
    nhap();
}

