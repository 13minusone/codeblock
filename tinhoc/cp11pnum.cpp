#include<bits/stdc++.h>
using namespace std;
long long f;
long long tknp( unsigned long long n,long long l,long long r,long long k)
{

  if(l<=r)
    {
    long long mid=(r+l)/2;
    long long s=1;

    for(int i=0;i<k;i++)
    {
        s=s*(mid-i);
    }
    if(mid<=n)
    {
        f=s;
     return  tknp(n,mid+1,r, k);
    }
    else
    {
          return tknp(n,1,mid-1,k);
    }}
    else
    {
        return f;
    }

    return f;
}
int main()
{
    long long t,n,k;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>k;
        f=-1;
        cout<<tknp(n,1,int(sqrt(n)),k)<<endl;
    }
}
