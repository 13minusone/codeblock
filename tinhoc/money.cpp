#include <bits/stdc++.h>
using namespace std;
int n,  a[101],s;
int f[101][100005];
vector<int>p;
void nhap()
{
    scanf("%d",&n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &a[i]);
        s=s+a[i];
    }
}

void giai()
{
    for(int i=0;i<=n;i++) f[i][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=s;j++)
        {
            f[i][j]=f[i-1][j];
            if(j>=a[i])
            {
                if(f[i-1][j-a[i]]==1)
                    f[i][j]=1;
            }
        }
    }
    int d=0;
    for(int i=1;i<=s;i++)
    {
        if(f[n][i]==1)
           p.push_back(i);
    }
    cout<<p.size()<<endl;;
    for(int i=0;i<p.size();i++)
    {
        cout<<p[i]<<" ";
    }
}

int main()
{
    //freopen("market.inp", "r", stdin);
    //freopen("market.out", "w", stdout);
    nhap();
    giai();
}

