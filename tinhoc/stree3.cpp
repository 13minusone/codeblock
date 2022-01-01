#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fu(i,a,b,c) for(int i=a;i<=b;i+=c)
#define fd(i,a,b,c) for(int i=a;i>=b;i+=c)
#define pb(i) push_back(i)
int arr[200001],n,u,m,v;
long long  st[800001];
void build(int id,int l,int r )
{
    if( l == r)
    {
        st[id]=arr[l];
        return;
    }

    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id]=st[id*2]+st[id*2+1];

}
void update(int id,int l,int r,int i, int v)
{
    if( l > i || r < i  )
    {
        return;
    }
    if( l == r)
    {
        st[id]=v;
        return;
    }

    int mid=(l+r)/2;
    update(id*2,l,mid,i,v);
    update(id*2+1,mid+1,r,i,v);
    st[id]=st[id*2]+st[id*2+1];
}
long long get(int id, int l,int r,int i,int v)
{
    if(v < l || r<i)
    {
        return 0;
    }
    if(i<=l&&r<=v)
    {
        return st[id];
    }
    int mid=(l+r)/2;
    return get(id*2,l,mid,i,v)+get(id*2+1,mid+1,r,i,v);
}
int main()
{
//    freopen("test1.inp","r",stdin);
//    freopen("test1.out","w",stdout);
    cin >> n >>m;
    for(int i = 1; i<=n; i++)
    {
        cin >> arr[i];
    }
    build(1,1,n);
    int x, y,z;
    for(int i = 1 ; i <=m; i++)
    {
        cin >> x>> y >>z;
        if(x==1)
        {
            update(1,1,n,y,z);
        }
        else
        {
            cout << get(1,1,n,y,z)<<endl;
        }
    }
}
