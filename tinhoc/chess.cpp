#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fu(a,b,c) for(int i=a;i<=b;i=i+c)
#define k 1000000000
ll f[1001][1001],a[1001][1001]={1};
ll m,n,x,y;
void nhap()
{

cin>>n>>m;

}
int main()
{
    freopen("chess.inp","r",stdin);
    freopen("chess.out","w",stdout);
    nhap();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            a[i][j]=1;
        }
    }
fu(1,m,1)
{
    cin>>x>>y;
    a[x][y]=0;
}
    f[1][1]=1;

for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=n;j++)
       {
if(a[i][j]==1)
           {

               f[i][j]=f[i][j]+f[i-1][j]+f[i][j-1];
               f[i][j]=f[i][j]%k;

           }
       else
       {
           f[i][j]=0;

   }

       }}cout<<f[n][n];
}

