#include <bits/stdc++.h>
using namespace std;
int n,a[100001],f[100001],b[100001],res=0,maxx=1;
int t[1000005];
int ds[1000005];

void nhap()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
}

void truyvet(int k)
{
    int d=0;
    while(k>0)
    {
        //cout<<k<<" ";
        d++;
        ds[d]=k;
        k=t[k];
    }
    cout<<d<<endl;
    for(int i=d;i>=1;i--)
        cout<<ds[i]<<" ";
}

void giai()
{
    int jmax,imax;
    f[1]=a[1];f[0]=0;
    for(int i=2;i<=n;i++)
    {
        jmax=0;
        for(int j=1;j<=i-1;j++)
            if(a[j]<a[i]&&f[j]>0&&f[j]>f[jmax])
                jmax=j;
        f[i]=f[jmax]+a[i];
        t[i]=jmax;
    }
    imax=1;
    for(int i=2;i<=n;i++)
        if(f[i]>f[imax]) imax=i;
    cout<<f[imax]<<endl;
    truyvet(imax);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("smax.inp","r",stdin);
    freopen("smax.out","w",stdout);
    nhap();
    giai();
}
