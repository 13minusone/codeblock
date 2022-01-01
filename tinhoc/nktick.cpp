#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fu(a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(a,b,c) for(int i=a;i>=b;i=i-c)
    int m[60000],n,x[60000],f[60000];
void inti()
{
   freopen("nktick.inp","r",stdin);
   freopen("nktick.out","w",stdout);
}
void nhap()
{
inti();
cin>>n;
fu(1,n,1)scanf("%d",&x[i]);
fu(1,n-1,1)scanf("%d",&m[i]);
}
int main()
{
nhap();
f[1]=x[1];
for(int i=2;i<=n;i++)
{
    f[i]=min(f[i-1]+x[i],f[i-2]+m[i-1]);
//cout<<i<<" "<<f[i]<<endl;
}
cout<<f[n];
}
