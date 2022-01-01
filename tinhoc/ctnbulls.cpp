#include<bits/stdc++.h>
using namespace std;
    long long n,k,f[1000000];

int main()
{
    freopen("ctnbulls.inp","r",stdin);
    freopen("ctnbulls.out","w",stdout);
    cin>>n>>k;
    f[0]=1;
    f[1]=2;
    for(int i=2;i<=k;i++)
    {
        f[i]=f[i-1]+1;
    }
    for(int i=k+1;i<=n;i++)
    {
        f[i]=(f[i-1]+f[i-k-1])%2111992;
    }
    cout<<f[n];
}
