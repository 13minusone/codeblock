#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b,c) for(int  i = a ; i <=b ;i+=c)
#define fd(i,a,b,c) for(int  i = a ; i >=b ;i-=c)
#define ll long long
#define SZ(c) c.size()
const ll maxsize = 100000;
const ll mod=int(1e9)+7;
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
    unsigned ll q,l,r,x;
    cin >> q;
    //cout << mod << endl;
    fu(i,1,q,1)
    {
        cin >> l >> r >> x ;
        unsigned  ll s=r-l+1;
       unsigned ll c=l/x;
        if(l%x!=0)
        {

            l=c;
        }
        else
        {
            l=c-1;
        }
        unsigned ll y=r/x;
        r=y;
        unsigned ll t=r-l;

        unsigned ll sum=s+((s%mod*((s-1)%mod)/(2%mod))%mod);
        unsigned ll sum1=t+(t%mod*((t-1)%mod)/(2%mod))%mod;

        cout << (sum-sum1)%mod << endl;
    }
}
int main()
{
    fastio();
    nhap();
}

