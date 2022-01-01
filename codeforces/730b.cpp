#include<bits/stdc++.h>
using namespace std;
#define task ""
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
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
ll t,n,a[2*maxsize+5];
void nhap()
{

    cin >> t;
    for(int o = 1 ; o <= t ; ++o)
    {
        ll s=0;
        cin >> n;
        for(int i = 1 ; i <= n ;++i)
        {
            cin >> a[i];
            s+=a[i];
        }
        ll h=s%n;
        if(h==0)
        {
            cout << 0 << endl;

        }
        else
        {
            ll p=h*(n-h);
        cout << p << endl;
        }

    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}


