#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b,c) for(int  i = a ; i <=b ;i+=c)
#define fd(i,a,b,c) for(int  i = a ; i >=b ;i-=c)
#define ll long long
const ll maxsize = 200000;
ll arr[maxsize];
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void inti()
{
    freopen("cses.inp","r",stdin);
    freopen("cses.out","w",stdout);
}
struct node
{
    unsigned ll t,val;
} st[4*maxsize+2];

void build(int id,int l,int r)
{
    if(l==r)
    {
        st[id].val=arr[l];
        return ;
    }
    int mid =( l+ r )/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    st[id].val=st[id<<1].val+st[id<<1|1].val;
}
void lazy(int id )
{
    unsigned ll v=st[id].t;
    st[id*2].t+=v;
    st[id<<1|1].t+=v;
    st[id*2].val+=v;
    st[id<<1|1].val+=v;
    st[id].t=0;

}
void update(int id, int l, int r, int u, int v, int val)
{
    if (v < l || r < u)
    {
        return ;
    }
    if (u <= l && r <= v)
    {
        st[id].val+=val;
        st[id].t+=val;
        return ;
    }
    int mid = (l + r) / 2;

    lazy(id);

    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid+1, r, u, v, val);
    st[id].val = st[id*2].val+st[id*2+1].val;
}
unsigned ll getsum(int id , int l ,int r, int a,int v )
{
    if(l >v||r < a)
    {
        return 0;
    }
    if(l >= a && r <=v)
    {
        return st[id].val;
    }
    int mid=(l+r)/2;
    lazy(id);
   return getsum(id<<1,l,mid,a,v)+getsum(id<<1|1,mid+1,r,a,v);
}
void nhap()
{
    int n,m ;
    cin >> n >> m;
    fu(i,1,n,1)
    {
        cin >> arr[i];
    }

build(1,1,n);
    int x,y,z,r;
    fu(i,1,m,1)
    {
        cin >> x>> y >>z;
        if(x==1)
        {

            update(1,1,n,y,y,z);
        }
        else
        {
            cout << getsum(1,1,n,y,z) <<endl;
        }
    }

}
int main()
{
    fastio();
    //inti();
    nhap();
}
