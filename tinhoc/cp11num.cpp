#include<bits/stdc++.h>
using namespace std;
long long p[10000000],c[10000000];
void sang()
{

    for(int i=1;i<=int(1e7);i++)
    {
        p[i]=1;
    }
    p[0]=0;
    p[1]=0;
    for(int i=2;i<=int(sqrt(int(1e7)));i++)
    {
        if(p[i]==1)
        {
            for(int j=i*i;j<=int(1e7);j+=i) p[j]=0;
        }
    }
}
void taont()
{
     long long d=0;
    for(int i=1;i<=(int(1e7));i++)
    {
        if(p[i]==1)
        {
            d++;
            c[d]=i;
        }
    }
}

int tknp(unsigned long long  x, int l,int r,long long k)
{
    int mid,res=-1;
    while(l<=r)
    {
        mid=(l+r)/2;
        long long s=1;
        for(int i=mid;i<=mid+k-1;i++)
        {
            s=s*c[i];
        }
        if (s<=x)
        {
            res=s;
            l=mid+1;
        }
        else r=mid-1;
    }
    return res;
}
int main()
{
    unsigned long long t,n,k;
freopen("cp11pnum.inp","r",stdin);
freopen("cp11pnum.out","w",stdout);
    cin>>t;
    sang();
    taont();
    for(int i=1;i<=t;i++)
    {
        cin>>n>>k;
        cout<<tknp(n,1,n,k)<<endl;

    }
}
