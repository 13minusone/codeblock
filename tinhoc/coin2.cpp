#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fu(a,b,c) for(int i=a;i<=b;i=i+c)
ll m,n;
const long long mod= 1e9+7;
ll a[1001],f[1000005];
void nhap()
{
    cin>>n>>m;
    fu(1,n,1)
    {
        cin>>a[i];
    }
}

int main()
{
//    freopen("task.inp","r",stdin);
//    freopen("task.out","w",stdout);
    nhap();
    f[0]=1;
    for(int i=1;i<n;i++)
    {
        f[i]=0;
    }
    f[0]=1;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i>=a[j])
            {
                (f[i]+=f[i-a[j]])%=mod;
            }
        }
    }
    if((f[m]%mod)%n!=0)
    {
        cout<<(f[m]%mod)/n+1;
    }
    else
    {
         cout<<(f[m]%mod)/n;
    }

}
