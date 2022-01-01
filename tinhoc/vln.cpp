#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll m,n,x[10000],d[1000];
void inti()
{
   freopen("vln.inp","r",stdin);
   freopen("vln.out","w",stdout);
}
void nhap()
{

cin>>n>>m;
fu(i,1,n,1)
{
    cin>>x[i];
    d[i]=d[i-1]+x[i];
}
ll maxx=-1;
fu(i,1,n,1)
{
    ll g=m/3;

    if(g<i-1)
    {
        maxx=max(maxx,d[i+g]-d[i-g-1]);
    }
    else
    {
        maxx=max(maxx,d[i+g]);
    }
   // cout<<i<<" "<<g<<" "<<maxx<<endl;
}
cout<<maxx;
}
int main()
{
IOS
inti();
nhap();

}

