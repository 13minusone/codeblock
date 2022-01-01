#include<bits/stdc++.h>
using namespace std;
long long n,a[1000000],f[1000000];
int main()
{
    freopen("nkcable.inp","r",stdin);
    freopen("nkcable.out","w",stdout);
    cin>>n;

    for(int i=1;i<=n-1;i++)
    {

        cin>>a[i];



    }
    f[2]=a[1];
    f[3]=a[2]+a[1];
    for(int i=4;i<=n;i++)
   {
  f[i]=min(f[i-1],f[i-2])+a[i-1];
    }
    cout<<f[n];
}
