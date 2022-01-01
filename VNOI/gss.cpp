#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b,c) for(int  i = a ; i <=b ;i+=c)
#define fd(i,a,b,c) for(int  i = a ; i >=b ;i-=c)
#define ll long long
#define SZ(c) c.size()
const ll maxsize = 50001;
const ll inf=7500000000;
ll  n ,arr[maxsize],a[maxsize+5];
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void inti()
{
    freopen(".inp","r",stdin);
    freopen(".our","w",stdout);
}
struct node
{
    ll le,ri,be;
}st[4*maxsize+5];
node cong(node u ,node v)
{
    ll f=min(u.le,v.le);
    ll g=max(u.ri,v.ri);
    ll s=v.ri-u.le;
    s=max(s,max(u.be,v.be));
    node re;
    re.le=f;
    re.ri=g;
    re.be=s;
    return re ;
}
void build(int id,int l,int r)
{
    if(l==r)
    {
        st[id].le=arr[l-1];
        st[id].be=a[l];
        st[id].ri=arr[l];
        return ;
    }
    int mid=(l+r)/2;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    st[id]=cong(st[id<<1],st[id<<1|1]);
}
 node get(int id , int l, int r,int u,int v)
 {
     if(l > v || r < u )
     {
         node t;
         t.le=inf;
         t.be=-inf;
         t.ri=-inf;
         return t;
     }
     if(l >= u && r <= v)
     {
         return st[id];
     }
     int mid=(l+r)/2;
     return cong(get(id<<1,l,mid,u,v),get(id<<1|1,mid+1,r,u,v));
 }
void nhap()
{
    cin >> n;
    ll x;

    fu(i,1,n,1)
    {
        cin >> a[i];
        arr[i]=arr[i-1]+a[i];

    }
    arr[0]=inf;

    build(1,1,n);
    // <<st[1].le << " " <<st[1].be << " " << st[1].ri << endl;
   ll  m;
    cin >> m;
    fu(i,1,m,1)
    {
        ll x,y;
        cin >> x >> y;
        cout << get(1,1,n,x,y).be<< endl;
    }
}
int main()
{
    fastio();
    nhap();
}

