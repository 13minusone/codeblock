#include <bits/stdc++.h>
using namespace std;
int n,a[200001],f[200001],b[200001],res=0,maxx=1;
int t[2000005];

void nhap()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
}

int ds[2000005];
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
    for(int i=d;i>=1;i--)
        cout<<ds[i]<<" ";
}

int bs(int x,int l,int r)
{
    int res=0,m;
    while(l<=r)
    {
        m=(l+r)/2;
        if(a[b[m]]<x)
        {
            res=m;
            l=m+1;
        }
        else r=m-1;
    }
    return res;
}

void giai()
{
    int res,k;
    f[1]=1;res=1;b[1]=1;
    for(int i=2;i<=n;i++)
    {
        k=bs(a[i],1,f[res]);
        f[i]=k+1;
        b[f[i]]=i;
        t[i]=b[k];
        if(f[i]>f[res]) res=i;
    }
    //for(int i=1;i<=res;i++) cout<<b[i]<<" ";
    cout<<f[res]<<endl;

}

void xuat()
{
    res=maxx;
    for (int i=n;i>=1;i--)
    {
        if (res==f[i])
        {
            a[res]=i;
            res--;
        }
        if (res==0) break;
    }
    cout<<maxx<<endl;
    for (int i=1;i<=maxx;i++) cout<<a[i]<<" ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("liqlis.inp","r",stdin);
//    freopen("liqlis.out","w",stdout);
    //xuli();
    //xuat();
    nhap();
    giai();
}
