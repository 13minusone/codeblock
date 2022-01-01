#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define maxxn 100005
struct node
{
    int ma ;
    int mi ;

};
    int m,n,arr[100005];
    node st[4*maxxn];
void build(int id ,int l,int r)
{
    if(l == r)
    {
        st[id].ma=arr[l];
        st[id].mi=arr[r];
        return;

    }
    int mid = ( l + r )/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id].ma=max(st[id*2].ma,st[id*2+1].ma);
    st[id].mi=min(st[id*2].mi,st[id*2+1].mi);

}
ll getmin(int id , int l ,int r ,int u ,int v)
{
    if(l > v ||r < u )
    {
        return INT_MAX;

    }
   if(l >= u && r <= v)
   {
       return st[id].mi;
   }
   int mid = ( l+r )/2;
   return min(getmin(id*2,l ,mid,u,v),getmin(id*2+1,mid+1,r,u,v));

}
ll getmax(int id , int l ,int r ,int u ,int v)
{
    if(l > v ||r < u )
    {
        return -1;

    }
   if(l >= u && r <= v)
   {
       return st[id].ma;
   }
   int mid = ( l+r )/2;
   return max(getmax(id*2,l ,mid,u,v),getmax(id*2+1,mid+1,r,u,v));

}
void inti()
{
   freopen("nklineup.inp","r",stdin);
   freopen("nklineup.out","w",stdout);
}
void nhap()
{

cin>>n>>m;
fu(i,1,n,1)cin>>arr[i];
build(1,1,n);
int l,r;
fu(i,1,m,1)
{

    cin >> l >> r;
    cout << getmax(1,1,n,l,r)-getmin(1,1,n,l,r)<<endl;
}
}
int main()
{
IOS
//inti();
nhap();

}

