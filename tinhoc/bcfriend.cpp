#include<bits/stdc++.h>
using namespace std;
int x,y,n,b,a[10000000];
int bs_max(int l,int r, int k)
{
    int kq=0,mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if (a[mid]<=k)
        {
            if(a[mid]==k) kq=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return kq;
}
int bs_min(int l,int r, int k)
{
    int kq=0,mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if (a[mid]>=k)
        {
            if(a[mid]==k) kq=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return kq;
}

void qs(int l,int r)
{
    int i=l,j=r;
    int p=a[l+rand()%(r-l)];
    while(i<=j)
    {
        while(p>a[i]) i++;
        while(p<a[j]) j--;
        if(i<=j)
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    if(i<r) qs(i,r);
    if(j>l) qs(l,j);
}

void nhap()
{
    scanf("%d %d",&n,&b);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
}
void giai()
{
    if(n>1) qs(1,n);
    long long res=0;
    for(int j=1;j<=n;j++)
    {

        y=bs_max(1,j-1,b-a[j]);
        x=bs_min(1,j-1,b-a[j]);
        if(x!=0) res=res+y-x+1;

    }
    printf("%lld",res);
}
int main()
{
    freopen("bcfriend.inp","r",stdin);
    freopen("bcfriend.out","w",stdout);
    nhap();
    giai();

}
