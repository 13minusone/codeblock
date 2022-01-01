#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("bacthang1.inp","r",stdin);
   // freopen("bacthang1.out","w",stdout);
    long long n,f[100000];
    cin>>n;
    f[3]=2;
    f[2]=1;
    for(int i=4;i<=n;i++)
    {
        f[i]=f[i-1]+f[i-2];
    }
    cout<<f[n];
}
