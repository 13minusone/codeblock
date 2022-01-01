#include <bits/stdc++.h>
using namespace std;
int h[100001],n,k,f[100001];
void nhap()
{
    cin>>n>>k;
    int a;
    for (int i=1;i<=k;i++)
    {
        cin>>a;
        h[a]=1;
    }
}

void xuli()
{
    if(h[2]==1) f[2]=0;
    else f[2]=1;
    if(h[3]==1) f[3]=0;
    else
        if(h[2]==1) f[3]=1;
        else f[3]=2;

    //tinh f[n]
    for (int i=4;i<=n;i++)
    {
        if (h[i]==1) f[i]=0;
        else f[i]=(f[i-1]+f[i-2])%14062008;
        //cout<<f[i]<<" "<<i<<endl;
    }
    cout<<f[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("vsteps.inp","r",stdin);
    freopen("vsteps.out","w",stdout);
    nhap();
    xuli();
}
