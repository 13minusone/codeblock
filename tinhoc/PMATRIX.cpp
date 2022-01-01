#include <bits/stdc++.h>
using namespace std;

int maxx=1000000,p[1000001],d=0;
int c[1000001],oo=1000000000;
int m,n,a[1001][1001],b[1001][1001];

void sang()
{

    for(int i=1;i<=maxx;i++)
    {
        p[i]=1;
    }
    p[0]=0;
    p[1]=0;
    for(int i=2;i<=int(sqrt(maxx));i++)
    {
        if(p[i]==1)
        {
            for(int j=i*i;j<=maxx;j+=i) p[j]=0;
        }
    }
}
void taont()
{
     d=0;
    for(int i=1;i<=maxx;i++)
    {
        if(p[i]==1)
        {
            d++;
            c[d]=i;
        }
    }
}

int tknp(int x, int l,int r)
{
    int mid,res=0;
    while(l<=r)
    {
        mid=(l+r)/2;
        if (c[mid]>=x)
        {
            res=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return res;
}


void taob()
{
    int k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            k=tknp(a[i][j],1,d);
            if(k>0) b[i][j]=c[k]-a[i][j];
        }
}

void giai()
{
    int minn=oo,s;
    sang();
    taont();

    taob();

    for(int i=1;i<=n;i++)
    {
        s=0;
        for(int j=1;j<=m;j++)
            s=s+b[i][j];
        if(s<minn) minn=s;
    }
    for(int i=1;i<=m;i++)
    {
        s=0;
        for(int j=1;j<=n;j++)
            s=s+b[j][i];
        if(s<minn) minn=s;
    }
    cout<<minn;
}

void nhap()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) cin>>a[i][j];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("pmatrix.inp","r",stdin);
    freopen("pmatrix.out","w",stdout);
    nhap();
    giai();
}

