#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fu(a,b,c) for(int i=a;i<=b;i=i+c)
ll m,n;
ll a[1001],g[100001],f[1001][100001];

void nhap()
{

cin>>n>>m;
fu(1,n,1)
{
    cin>>a[i];
}
fu(1,n,1)
{
    cin>>g[i];
}

}
void truyvet(long long n,long long m)
{
    ll d=0;
    ll ds[10000];
    while(n!=0)
    {
        if(f[n][m]=f[n-1][m])
        {
            n=n-1;

        }
        else
        {
            d++;
            ds[d]=n;
            n=n-1;
            m=m-g[n];
        }
    }
    cout<<d<<'\n';
    for(int i=d;d>=1;d--)
    {
        cout<<ds[i]<<" ";
    }
}
int main()
{
   //freopen("task.inp","r",stdin);
    //freopen("task.out","w",stdout);
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

