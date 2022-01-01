#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int maxxn 100005;
#define endl '\n'
int m,n,x;
void inti()
{
   freopen("lis.inp","r",stdin);
   freopen("lis.out","w",stdout);
}
int st[4*maxxn];
void update(int id ,int l ,int r, int u, int v)
{
    if( l > u || r < u )
    {
        return ;

    }
    if( l == u && r == u)
    {
        st[id]=v;
        return;
    }
    int mid=(l+r)/2;
    update(id<<1,l,mid,u,v);
    update(id<<1|1,mid+1,r,u,v);
    st[id]=max(st[id<<1],st[id<<1|1]);
}
void getm(int id,int l ,int r,int u)
{
    if( l > u || r < u )
    {
        return ;

    }
    if( l == u && r == u)
    {
        return st[id];

    }
    int mid=(l+r)/2;
    getm(id<<1,l,mid,u,v);
    getm(id<<1|1,mid+1,r,u,v);
    st[id]=max(st[id<<1],st[id<<1|1]);
}
void nhap()
{

cin>>n;
fu(i,1,n,1)
{
    cin>>x;

}
}
int main()
{
IOS
//inti()
nhap();

}

