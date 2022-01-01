#include<bits/stdc++.h>
using namespace std;
int n,res;
struct doan
{
    int a,b;
};
doan d[10000000];
void nhap()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld %lld",&d[i].a,&d[i].b);
}
bool ss(doan x,doan y)
{
    return x.a<y.a;
}
void qs(int l,int r)
{
    int i=l,j=r;
    int p=d[l+rand()%(r-l)].a;
    while(i<=j)
    {
        while(p>d[i].a) i++;
        while(p<d[j].a) j--;
        if(i<=j)
        {
            swap(d[i],d[j]);
            i++;
            j--;
        }
    }
    if(i<r) qs(i,r);
    if(j>l) qs(l,j);
}
int bs(int x, int l, int r)
{
    int mid,res=0;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(d[mid].a<=x)
        {
            res=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return res;
}
void xuli()
{
    long long dem=0;
    int k;
    sort(d+1,d+1+n,ss);
    for(int i=1;i<=n-1;i++)
    {
        k=bs(d[i].b,i+1,n);
        if(k>0) dem=dem+(k-i);
    }
    printf("%lld",dem);
}
int main()
{
    freopen("intervals.inp","r",stdin);
    freopen("intervals.out","w",stdout);
    nhap();
    qs(1,n);
    xuli();
}
