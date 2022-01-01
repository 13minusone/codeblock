#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("ndccard.inp","r",stdin);
    freopen("ndccard.out","w",stdout);
    long long n,a[100000],m,maxx=-10000;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
       scanf("%d",&a[i]);
    }
    for(int i=1;i<=n-2;i++)
    {
        for(int j=i+1;j<=n-1;j++)
        {
            for(int f=j+1;f<=n;f++)
            {
                if(a[i]+a[f]+a[j]<=m)
                {
                    maxx=max(maxx,a[i]+a[f]+a[j]);
                }
            }
        }
    }
    cout<<maxx;
}
