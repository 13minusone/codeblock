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
     ll t,val;
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
    st[id].val=max(st[id<<1].val,st[id<<1|1].val);
}
void lazy(int id )
{
    ll v=st[id].t;
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
    st[id].val = max(st[id*2].val,st[id*2+1].val);
}
ll getsum(int id , int l ,int r,ll u,ll v )
{

     if (v < l || r < u)
    {
        return -1000000;
    }
    if (u <= l && r <= v)
    {

        return st[id].val;
    }
    int mid = (l + r) / 2;

    lazy(id);

    return max(getsum(id*2, l, mid, u, v),
    getsum(id*2+1, mid+1, r, u, v));
    st[id].val = max(st[id*2].val,st[id*2+1].val);
}
void nhap()
{
    int n,m ;

    cin >> n >> m;
    fu(i,1,n,1)
    {
        ll x;
        cin >> x;
        arr[i]=arr[i-1]+x;
        //cout << arr[i] << endl;
    }
    build(1,1,n);
    ll x,y,z,r;
    fu(i,1,m,1)
    {
        cin >> x>>z >> r;
        if(x==1)
        {

            update(1,1,n,z,n,r);
        }
        else
        {
            cout << getsum(1,1,n,z,r)-getsum(1,1,n,z-1,z-1) <<endl;
        }
    }
}
int main()
{
    fastio();
    //inti();
    nhap();
    /*
    8 4
1 2 -1 3 1 -5 1 4
2 2 6
1 4 -2
1 2 -1 1 1 -5 1 4
1 3 2 3 4 -1 0 4
2 2 6

2 3 4
*/
}
