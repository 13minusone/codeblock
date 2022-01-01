#include<Bits/stdc++.h>
using namespace std;
long long g[10000000],n,m,k=0;
long long a[10000000];
int main()
{
    freopen("CB20DVALUES.INP","r",stdin);
    freopen("CB20DVALUES.OUT","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>m;
        g[m+1000]++;
        if(g[m+1000]==1)
        {
            a[k]=m;
            k++;
        }
    }
    sort(a,a+k);
    for(int i=k-1;i>=0;i--)
    {
        cout<<a[i]<<" ";
    }
}
