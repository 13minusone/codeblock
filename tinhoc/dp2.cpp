#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll m,n,x[100001];

void inti()
{
   freopen(".inp","r",stdin);
   freopen(".out","w",stdout);
}
ll f[100001];
void nhap()
{

cin>>n;
fu(i,1,n,1)cin>>x[i];


fu(i,2,n,1)
{
    if(i<=2)
    {
        f[i]=f[i-1]+abs(x[i]-x[i-1]);
    }
    else
    {


    f[i]=min(f[i-1]+abs(x[i]-x[i-1]),f[i-2]+abs(x[i]-x[i-2]));}
    //cout<<f[i]<<" "<<i<<endl;
}
cout<<f[n];
}
int main()
{
IOS
//inti()
nhap();

}

