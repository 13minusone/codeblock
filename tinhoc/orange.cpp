#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll m,n,x[1000001],d[1000001];

void inti()
{
   freopen("orange.inp","r",stdin);
   freopen("orange.out","w",stdout);
}
void nhap()
{

cin>>n;
fu(i,1,n,1)
{cin>>x[i];
d[x[i]]++;
}
sort(x+1,x+n+1);
unsigned ll maxx=0;
fd(i,n-1,1,1)
{
   // cout<<x[i]<<endl;
    if(x[i]!=x[i-1])
    {
        unsigned ll h=((n-i+1)*x[i]);
        maxx=max(maxx,h);
    }
}
cout<<maxx;
}
int main()
{
IOS
inti();
nhap();

}

