#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fu(a,b,c) for(int i=a;i<=b;i=i+c)
#define m int(1e9)+7
ll n;
void nhap()
{

cin>>n;

}
unsigned ll a[1000001],f[1000001];

void dp(ll n)
{
    fu(7,n,1)
    {
        f[i]=(a[i-1]%m-a[i-7]%m)%m;
        a[i]=(a[i-1]+f[i]);

        //cout<<i<<" "<<f[i]<<" "<<a[i]<<'\n';
    }
    cout<<f[n]%m<<endl;
}
int main()
{
nhap();
a[1]=1;
f[1]=1;
a[0]=0;
fu(2,6,1)
{
    f[i]=a[i-1]+1;
    a[i]=a[i-1]+f[i];
}
dp(n);
}
