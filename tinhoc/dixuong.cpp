#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fu(a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(a,b,c) for(int i=a;i>=b;i=i-c)
    int m,n,x,t,maxx=0;
    int a[1000][1000],f[1000][1000];
void inti()
{
   freopen("dixuong.inp","r",stdin);
   freopen("dixuong.out","w",stdout);
}
void nhap()
{

cin>>n>>m;
fu(1,n,1)
{
    for(int j=1;j<=m;j++)
    {
        cin>>a[i][j];
    }
}
}
int main()
{
    inti();
nhap();
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=m;j++)
    {
        f[i][j]=max(f[i][j],max(max(f[i-1][j-1],f[i-1][j]),f[i-1][j+1])+a[i][j]);
    }
}
for(int i=1;i<=m;i++)
{
    maxx=max(maxx,f[n][i]);
}
cout<<maxx;
}
