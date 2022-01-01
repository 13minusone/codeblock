#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
ll m,n,x;
void inti()
{
    freopen("sumofclubes.inp","r",stdin);
    freopen("sumofclubes.out","w",stdout);
}
unsigned long long  luythua(ll x)
{
    unsigned long long h=x*x;
    h=h*x;
    return h;
}
void check(ll x)
{
    ll o=0;
    map<ll,ll>f;
    for(int i=1; i<=pow(x,1.0/3); i++)
    {
        ll s=luythua(i);
        if(x-s>0)
        {
           f[x-s]=1;

            if(f[s]==1)
            {
                o=1;
                cout<<"YES"<<'\n';
                break;
            }
        }
    }
    if(o==0)cout<<"NO"<<'\n';
}
void nhap()
{

    cin>>n;
    fu(i,1,n,1)
    {
        cin>>x;
        check(x);
    }
}

int main()
{

   // inti();

    //cout<<pow(luythua(5993),1.0/3)<<" "<<luythua(5993)<<endl;
    nhap();
}

