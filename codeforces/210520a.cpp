#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b,c) for(int  i = a ; i <=b ;i+=c)
#define fd(i,a,b,c) for(int  i = a ; i >=b ;i-=c)
#define ll long long
#define SZ(c) c.size()
const ll maxsize = 200001;
int n;
ll f[maxsize];
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
    ll ma,mi;
}st[maxsize*4];
void build(int id,int l ,int r)
{
    if(l==r)
    {
        st[id].mi=f[l];
        st[id].ma=f[l];
        return ;
    }
    int mid=(l+r)/2;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    st[id].ma=max(st[id<<1].ma,st[id<<1|1].ma);
    st[id].mi=min(st[id<<1].mi,st[id<<1|1].mi);
}
node get(int id,int  l ,int r, int u, int v)
{
    if(l > v || r < u )
    {
        node y;
        y.ma=0;
        y.mi=INT_MAX;
        return y;
    }
    if(l >= u && r <= v)
    {
        return st[id];
    }
    int mid=(l+r)/2;
    node w = get(id<<1,l,mid,u,v);
    node q = get(id<<1|1,mid+1,r,u,v);
    node t;
    t.ma=max(w.ma,q.ma);
    t.mi=min(w.mi,q.mi);
    return t;
}
void nhap()
{
    cin >> n;
    fu(i,1,n,1)
    {
        ll x;
        cin >> x;
        f[x]=i;
    }
    build(1,1,n);

    fu(i,1,n,1)
    {
        node u=get(1,1,n,1,i);
                //cout << i << " " << u.mi << " " << u.ma << endl;
        if(u.ma-u.mi+1==i)
        {
        cout << 1;
        }
        else
        {
            cout << 0;
        }

    }

}
int main()
{
    fastio();
    nhap();
}

