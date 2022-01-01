#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fu(a,b,c) for(int i=a;i<=b;i=i+c)
ll m,n;
ll a[1000],g[1000],f[101][100001];

void nhap()
{

cin>>n>>m;
fu(1,n,1)
{
    cin>>a[i]>>g[i];
}

}
void truyvet(long long n,long long m)
{
    ll d=0;
    ll ds[10000];
    while(f[n][m]>0)
    {
        if(f[n][m]!=f[n-1][m])
        {
            d++;
            ds[d]=n;
             m=m-a[n];


        }
          n--;

    }
    cout<<d<<'\n';
    for(int i=d;i>=1;i--)
    {
        cout<<ds[i]<<" ";
    }
}
int main()
{
    nhap();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]<=j)
            {
            f[i][j]=max(f[i-1][j-a[i]]+g[i],f[i-1][j]);

            }
            else
            {
                f[i][j]=f[i-1][j];
            }
        }
    }
    cout<<f[n][m]<<endl;
   //truyvet(n,m);
}
