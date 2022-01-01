#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    unsigned ll m,n,x,f[101][1000001],l;
void inti()
{
   freopen("bonus1212.inp","r",stdin);
   freopen("bonus1212.out","w",stdout);
}
ll solve(int i,int j,int l,int r)
{
    ll s=0;
  ll o=f[l][r];
  ll g=f[l][j-1];
  ll h=f[i-1][r];
  ll k=f[i-1][j-1];

    s=s+o-g+k-h;
    return s;

}
void nhap()
{

cin>>n>>m>>l;
ll p=0;
fu(i,1,n,1)
{
    ll o=0;
    fu(j,1,m,1)
    {
        cin>>x;

o=o+x;

        f[i][j]=f[i-1][j]+o;
    }
}
fu(i,1,l,1)
{
    ll q,w,e,r;
    cin>>q>>w>>e>>r;
    cout<<solve(q,w,e,r)<<endl;
}

}
int main()
{
IOS
inti();
nhap();

}

