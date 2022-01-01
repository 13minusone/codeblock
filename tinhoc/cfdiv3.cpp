#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int m,n,x;

void inti()
{
   freopen(".inp","r",stdin);
   freopen(".out","w",stdout);
}
ll snt(ll x)
{
    ll s=0;
    fu(i,1,int(sqrt(x)),1)
    {
        if(x%i==0)
        {
            s=s+i;
            s=s+x/i;
        }
    }
}
void nhap()
{

cin>>n>>m;
fu(i,1,n,1)cin>>x;
}
int main()
{
IOS
//inti()
nhap();

}

