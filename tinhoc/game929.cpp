#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll m,n,x[1000001],f[1000001],d[1000001];
void inti()
{
   freopen(".inp","r",stdin);
   freopen(".out","w",stdout);
}
void nhap()
{

cin>>n;
fu(i,1,n,1)
{cin>>x[i];


}

f[1]=x[1];
f[2]=x[2]+x[1];
d[1]=x[1];
d[2]=x[2];
fu(i,3,n,1)
{

   f[i]=max(f[i-2]+x[i],f[i-1]);


}
cout<<max(f[n],d[n]);
}
int main()
{
IOS
//inti()
nhap();

}

