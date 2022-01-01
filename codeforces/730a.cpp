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
void nhap()
{
    ll t,a,b;
    cin >> t;
    for(int i = 1 ; i <= t ; ++i)
    {
        cin >> a >> b;
        if(abs(a-b)==1)
        {
            cout << 1 << " " << 0 << endl;
            continue;
        }
        if(a==b)
        {
            cout << 0 << " " << 0 << endl;
            continue;
        }
         if (a<b) swap(a,b);
        ll k=a-b;
        cout << k << " ";
        ll x=a%k;
        ll y=b%k;
        if (x==y)
        {
            cout << min(k, min(x, k-x)) << endl;
        }
        else
        {
            cout << k << endl;
        }

    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}


