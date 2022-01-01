#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fu(a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(a,b,c) for(int i=a;i>=b;i=i-c)
    ll m,n,x;
    int a[1000][1000],f[1000][1000],maxx=0;
void nhap()
{

cin>>n;
fu(1,n,1)
{
    for(int j=1;j<=i;j++)
    {
        cin>>a[i][j];
    }
}
}
int main()
{
    freopen("triangle.inp","r",stdin);
    freopen("triangle.out","w",stdout);
nhap();
fu(1,n,1)
{
    for(int j=1;j<=i;j++)
    {
        f[i][j]=max(f[i][j],max(f[i-1][j],f[i-1][j-1])+a[i][j]);
    }
}
//for(int i=1;i<=n;i++)
//{
//    for(int j=1;j<=i;j++)
//    {
//        cout<<i<<" " <<j<<" " <<f[i][j]<<'\n';
//    }
//}
for(int i=1;i<=n;i++)
{
    maxx=max(f[n][i],maxx);
}
cout<<maxx;
}
