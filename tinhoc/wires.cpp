#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fu(a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(a,b,c) for(int i=a;i>=b;i=i-c)
    int m,n,a[10000],f[100000],maxx=-1;
void inti()
{
   freopen("wires.inp","r",stdin);
   freopen("wires.out","w",stdout);
}
void nhap()
{

cin>>n;
fu(1,n,1)cin>>a[i];
}
int main()
{
    inti();
nhap();
fu(1,n,1)
{
    for(int j=i-1;j>=1;j--)
    {
        if(a[j]<a[i])
        {
            f[i]=max(f[i],f[j]);
        }
    }
    f[i]=f[i]+1;
}
fu(1,n,1)maxx=max(maxx,f[i]);
cout<<maxx;
}
