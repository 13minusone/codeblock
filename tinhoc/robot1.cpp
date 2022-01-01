#include <bits/stdc++.h>
using namespace std;
int a[100][100];
string f[100][100];
int n;

void nhap()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) cin>>a[i][j];
}
void giai()
{
    f[1][1]=char(a[1][1]+48);
    for(int i=2;i<=n;i++)
    {
        f[1][i]=f[1][i-1]+char(a[1][i]+48);
        f[i][1]=f[i-1][1]+char(a[i][1]+48);
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=n;j++)
        {
            f[i][j]=min(f[i-1][j],f[i][j-1])+char(a[i][j]+48);
        }
    }
    cout<<f[n][n];

}


int main()
{
    freopen("robot1.inp", "r", stdin);
    freopen("robot1.out", "w", stdout);
    nhap();
    giai();
 //   return 1;

}
