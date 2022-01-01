#include<bits/stdc++.h>
using namespace std;
int i,n,d,j,k;
 int a[1000005];
 long long f[1000005],mx=-9999999;
 void nhap()
 {
      cin>>n>>k;
     	for(i=1;i<=n;i++) cin>>a[i];
 }
 void xuli()
 {
     f[0]=0;
     for(int i=1;i<=n;i++)
     {
         int maxx=f[i-1];
         for(j=i-k;j<=i-2;j++)
                if(j>=0)
                    if(f[j]>maxx) maxx=f[j];
        f[i]=maxx+a[i];
     }
     int fmax=f[0];
     for (i=1;i<=n;i++)
        if(f[i]>fmax) fmax=f[i];
     cout<<fmax;
 }
 int main()
 {
        freopen("nhaycoc.inp","r",stdin);
     	freopen("nhaycoc.out","w",stdout);
     	nhap();
     	xuli();
 }
