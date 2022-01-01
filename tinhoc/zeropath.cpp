#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
void fastio()
{

ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
    int m,n;
    ll d[5000001],x=0;

void inti()
{
   freopen("zeropath.inp","r",stdin);
   freopen("zeropath.out","w",stdout);
}
queue<ll>dta;
ll a[5000001];
void solve(ll n)
{
    fu(i,2,int(sqrt(n)),1)
{

    if(n%i==0)
    {
        if(i>n/i)
        {
            if(d[((n/i)-1)*(i+1)]==0)
            {
                dta.push(((n/i)-1)*(i+1));
                d[((n/i)-1)*(i+1)]++;
            }
        }

        else
        {
            if(d[((n/i)+1)*(i-1)]==0)
            {
                dta.push(((n/i)+1)*(i-1));
                d[((n/i)+1)*(i-1)]++;
            }
        }
        }
    }
    while(dta.empty()==false)
    {
        ll f=dta.front();
        a[x]=f;
        x++;

        dta.pop();
        solve(f);
    }
}

void nhap()
{

cin>>n;
solve(n);
cout<<x+1<<endl;

sort(a,a+x);
cout<<"0"<<" ";
fu(i,0,x,1)
{
    cout<<a[i]<< " ";
}

}
int main()
{
fastio();
inti();
nhap();

}

