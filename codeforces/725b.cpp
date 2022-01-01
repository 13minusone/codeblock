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
    ll t,n,a[200006];
    cin >> t;
    fu(j,1,t,1)
    {
        cin >> n;
        ll s=0;
        fu(i,1,n,1)
        {
            cin >> a[i];
            s=s+a[i];
        }
        if(s%n!=0)
        {
            cout << "-1" << endl;
            continue ;
        }
        else
        {
            ll f=s/n,dem=0;
            fu(i,1,n,1)
            {
                if(a[i]>f)
                {
                    dem++;
                }
            }
            cout << dem << endl;
        }
    }
}
int main()
{
    fastio();
    nhap();
}

