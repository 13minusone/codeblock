#include <bits/stdc++.h>
using namespace std;
int s=0,f[101][101],a[101][101],m,n,d=0;
char g[1000001];
void nhap()
{
    cin>>m>>n;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++) cin>>a[i][j];
}

void truyvet(int i,int j)
{
    d=0;
    while (j>1)
    {
        if (f[i-1][j-1]+a[i][j]==f[i][j])
        {
            d++;g[d]='D';
            i--;j--;
        }
        else
        {
            if (f[i][j-1]+a[i][j]==f[i][j])
            {
                d++;g[d]='R';
                j--;
            }
            else
            {
                if (f[i+1][j-1]+a[i][j]==f[i][j])
                {
                    d++;g[d]='T';
                    i++;j--;
                }
            }
        }
        if (j==1) cout<<i<<" "<<j<<endl;
    }
    for (int i=d;i>=1;i--) cout<<g[i];
}

void xuli()
{
    int k1,k2;
    for (int j=1;j<=n;j++)
    {
        for (int i=1;i<=m;i++)
        {
            f[i][j]=max(max(f[i][j-1],f[i+1][j-1]),f[i-1][j-1])+a[i][j];
            if (s<f[i][j] && j==n)
            {
                s=f[i][j];
                k1=i;k2=j;
            }
            //cout<<f[i][j]<<endl;
        }
    }
    int imax=1;
    for(int i=2;i<=m;i++)
        if(f[i][n]>f[imax][n]) imax=i;
    cout<<f[imax][n]<<endl;
    truyvet(imax,n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("qbmax.inp","r",stdin);
    freopen("qbmax.out","w",stdout);
    nhap();
    xuli();
}
