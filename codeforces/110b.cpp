#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b,c) for(int  i = a ; i <=b ;i+=c)
#define fd(i,a,b,c) for(int  i = a ; i >=b ;i-=c)
#define ll long long
#define SZ(c) c.size()
const ll maxsize = 20000;
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
    ll t,n,x,a[maxsize];
    cin >> t;
    fu(u,1,t,1)
    {
        cin >> n;
        ll s=0;
        fu(i,1,n,1)
        {
            cin >> a[i];
        }
        fu(i,1,n,1)
        {
            fu(j,i+1,n,1)
            {
                if(__gcd(a[i],2*a[j])>1||__gcd(a[j],a[i]*2)>1)
                {
                    s++;
                }
            }
        }
        cout << s << endl;

    }
}
int main()
{
    fastio();
    nhap();
}

