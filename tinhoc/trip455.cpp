#include <bits/stdc++.h>
#define name "TRIP455"
using namespace std;
int n,i;
long long  k,s=0,d,D,p,a[100000000],w,w1,w2;
long long  f[10000008];
void nhap()
{
    cin>>n>>p;
    for(i=1;i<=n;i++)
    {
        cin>>k;
        k=k%p;
        a[i]=k;
    }
}
void tinh_f()
{
    f[0]=0;
    for(i=1;i<=n;i++) f[i]=f[i-1]+a[i];
}
void tim_tong_tg()
{
    s=1e18;
    for(i=1;i<=n;i++)
    {
        w1=i*a[i]-f[i];
        w2=(n-i)*(a[i]+p)-f[n]+f[i];
        w=w1+w2;
        s=min(s,w);
    }
    cout<<s;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);
    nhap();
    sort(a+1,a+n+1);
    tinh_f();
    tim_tong_tg();
}
