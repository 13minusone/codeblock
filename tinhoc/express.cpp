#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   ll k,n,x[100001];
void inti()
{
   freopen("express.inp","r",stdin);
   freopen("express.out","w",stdout);
}
void nhap()
{

cin>>n>>k;
fu(i,1,n,1)cin>>x[i];
sort(x+1,x+n+1);
ll s=x[n];
fd(i,n-1,1,1)
{
    if(k>0)
    {
        s=s+x[i];
        k--;

    }
    else
    {
        s=s-x[i];
    }
}
cout<<s;
}
int main()
{
IOS
inti();
nhap();

}

