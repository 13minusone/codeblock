#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fu(a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(a,b,c) for(int i=a;i>=b;i=i-c)
    ll n,a[100000];
void nhap()
{

cin>>n;
fu(1,n,1)cin>>a[i];
}
ll f[100][50000];
int main()
{
    freopen("datcan.inp","r",stdin);
    freopen("datcan.out","w",stdout);
nhap();
f[1][5000+a[1]]=1;
f[1][5000-a[1]]=1;
f[1][5000]=1;

        for(int i=2;i<=n;i++)
{for(int j=-5000;j<=5000;j++)
    {
        //f[i][j]=f[i-1][j]

            f[i][j+5000]=f[i-1][j+5000]+f[i-1][j+5000+a[i]]+f[i-1][j+5000-a[i]];
        }
    }

cout<<f[n][5000]-1;
}
