#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll m,n,x[1000][1000],l=0;
    map<unsigned ll,ll>d;
void inti()
{
   freopen("tera.inp","r",stdin);
   freopen("tera.out","w",stdout);
}
void nhap()
{

scanf("%lld%lld",&n,&m);
fu(i,1,4,1)
{
    fu(j,1,n,1)
    {
        scanf("%lld",&x[i][j]);
        if(i==2)
    {
        unsigned ll s=x[2][j];
    fu(k,1,n,1)
    {
        ll s=x[2][j];
        s=s+x[1][k];
        d[s]++;
    }
    }
    if(i==4)
    {
         unsigned ll s=x[4][j];
    fu(k,1,n,1)
    {
        ll s=x[4][j];
        s=s+x[3][k];
        if(s<=m)
        {
            l=l+d[m-s];
        }
    }
    }

    }
}


printf("%lld",l);
}
int main()
{
//IOS
inti();
nhap();

}

