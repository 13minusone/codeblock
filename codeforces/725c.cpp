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
    ll t,n,l,r,a[200006];
    vector<ll>f;
    cin >> t ;
    fu(i,1,t,1)
    {
        cin >> n >> l >> r;
         ll s=0;
         f.push_back(LONG_MAX);

        fu(j,1,n,1)
        {
            cin >> a[j];
            f.push_back(a[j]);
            sort(f.begin(),f.end());
            ll g=lower_bound(f.begin(),f.end(),l-a[j])-f.begin();
            ll h=upper_bound(f.begin(),f.end(),r-a[j])-f.begin();

            cout << j << " " << g << " " << h << endl;
            s=s+h-g;

        }
        cout << s<< endl;
        f.clear();

    }
}
int main()
{
    fastio();
    nhap();
}

