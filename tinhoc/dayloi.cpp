#include <bits/stdc++.h>
using namespace std;
int a[100005],f[100005],n,g[100005],p[100005],b[100005],s,res,maxx,maxx1=0;

void nhap()
{
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
}
int bs(int l,int r,int x)
{
    if (l>r) return res;
    int mid=(l+r)/2;
    if (b[mid]>x)
    {
        res=mid;
        return bs(mid+1,r,x);
    }
    else return bs(l,mid-1,x);
}

int bss(int l,int r,int x)
{
    if (l>r) return res;
    int mid=(l+r)/2;
    if (p[mid]>x)
    {
        res=mid;
        return bss(mid+1,r,x);
    }
    else return bss(l,mid-1,x);
}

void xuli()
{

    maxx=1,b[0]=1000000000;maxx1=1;
    p[1]=a[1],p[0]=1000000000;f[1]=1;
    for (int i=2;i<=n;i++)
    {
        int k1=bss(0,maxx1,a[i]);
        f[i]=k1+1;
        //cout<<k1<<endl;
        if (f[i]>maxx1) maxx1=f[i];
        p[f[i]]=a[i];
        //cout<<g[i]<<endl;
    }

    g[n]=1;res=0;b[1]=a[n];
    for (int i=n-1;i>=1;i--)
    {
        int k=bs(0,maxx,a[i]);
        g[i]=k+1;
        //cout<<k<<endl;
        if (g[i]>maxx) maxx=g[i];
        b[g[i]]=a[i];
        //cout<<f[i]<<endl;
    }
    s=0;
    for (int i=1;i<=n;i++)
    {
        s=max(f[i]+g[i],s);
        //cout<<f[i]<<" "<<g[i]<<endl;
    }
    cout<<s-1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("dayloi.inp","r",stdin);
    freopen("dayloi.out","w",stdout);
    nhap();
    xuli();
    //kt();
}

