#include <bits/stdc++.h>
#define maxn 60001
using namespace std;
int n;
int a[maxn], it[5*maxn];
void update(int id, int l, int r, int u, int v, int val)
{
    if(v<l||r<u) return;
    if(u<=l&&r<=v)
    {
        it[id]+=val;
        return;
    }
    int mid=(r+l)/2;
    update(2*r,l,mid,u,v,val);
    update(2*r+1,mid+1,r,u,v,val);
    it[id]=it[2*id]+it[2*id+1];
}
int get(int id, int l, int r, int u, int v)
{
    if(v<l||r<u) return 0 ;
    if(u<=l&&r<=v)
    {
        return it[id];
    }
    int mid=(r+l)/2;
    return (get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v));
}
int main()
{
    cin>>n;
    int m=0;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        m=max(m, a[i]);
    }
    int ds=0;
    for(int i=n; i>=1; i--)
    {
        int t=get(1,1,m,1,a[i]-1);
        ds=ds+t;
        update(1,1,m,a[i],a[i],1);
    }
    cout<<ds;
}
