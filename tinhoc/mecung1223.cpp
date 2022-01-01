#include <bits/stdc++.h>
using namespace std;
long long m,f[71];
int n;
void xuli()
{
    f[1]=1;f[2]=2;f[3]=4;
    for (int i=4;i<=n;i++)
        f[i]=f[i-1]+f[i-2]+f[i-3];
    if (m>=f[n]) cout<<m-f[n];
    else cout<<"0";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("mecung1223.inp","r",stdin);
    freopen("mecung1223.out","w",stdout);
    cin>>m>>n;
    xuli();
}
