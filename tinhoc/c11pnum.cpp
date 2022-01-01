#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int p[1000001],a[1000001];
int t,k,maxx=1000000,d;
ll n;

void sang()
{

    for(int i=1;i<=maxx;i++)
    {
        p[i]=1;
    }
    p[0]=0;
    p[1]=0;
    for(int i=2;i<=int(sqrt(maxx));i++)
    {
        if(p[i]==1)
        {
            for(int j=i*i;j<=maxx;j+=i) p[j]=0;
        }
    }
}
void tao_mang_nt()
{
    d=0;
    for(int i=1;i<=maxx;i++)
    {
        if(p[i]==1)
        {
            d++;
            a[d]=i;
        }
    }
}

bool check(int x)
{
    ll s=1;
    for(int i=x;i<=x+k-2;i++)
    {

        s=s*a[i];
        if(s>n/a[x+k-1]) return false;
    }

    return true;
}

int tknp(int x, int l,int r)
{
    int mid,res=-1;
    while(l<=r)
    {
        mid=(l+r)/2;
        if (check(mid)==true)
        {
            res=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return res;
}

void giai()
{
    ll s;int x;
    cin>>n>>k;
    x=tknp(n,1,d);

    if(x==-1) cout<<x<<endl;
    else
    {
        s=1;
        for(int i=x;i<=x+k-1;i++)
            s=s*a[i];
        cout<<s<<endl;
    }
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
   freopen("c11pnum.inp","r",stdin);
   freopen("c11pnum.out","w",stdout);
    sang();
    tao_mang_nt();
    cin>>t;
    for(int i=1;i<=t;i++)
        giai();
}
