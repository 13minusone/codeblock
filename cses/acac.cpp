#include<bits/stdc++.h>
using namespace std;
#define task "c"
typedef long long ll;
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B)
{
    A=min(A,B);
}
template<class T> void maximize(T &A, T B)
{
    A=max(A,B);
}
const ll maxsize = 200000;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void inti()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
#define cal(i,j) ((i+j)*(j-i+1)/2)
struct node
{
    ll t,s;
} st[maxsize*4+5],b[maxsize*4+5];
void lazycnt(int id,int l,int r )
{
    ll k=st[id].t;
    int mid=(l+r)/2;
    st[id<<1].t+=k;
    st[id<<1|1].t+=k;
    st[id<<1].s+=cal(ll(l),ll(mid))*k;
    st[id<<1|1].s+=cal(ll(mid+1),ll(r))*k;
    st[id].t=0;
    return;
}
void updcnt(int id,int l,int r,int u,int v,int x)
{
    if(l>v||r<u)
    {
        return;
    }
    if(l>=u&&r<=v)
    {
        st[id].s+=(cal(ll(l),ll(r))*x);
        st[id].t+=x;
        return;
    }
    lazycnt(id,l,r);
    int m=(l+r)/2;
    updcnt(id<<1,l,m,u,v,x);
    updcnt(id<<1|1,m+1,r,u,v,x);
    st[id].s=st[id<<1].s+st[id<<1|1].s;
}
ll getcnt(int id,int l,int r,int u,int v)
{
    if(l>v||r<u)return 0;
    if(l>=u&&r<=v)
    {
        return st[id].s;
    }
    int m=(l+r)/2;
    lazycnt(id,l,r);
    return getcnt(id<<1,l,m,u,v)+getcnt(id<<1|1,m+1,r,u,v);
}
void lazyb(int id,int l,int r)
{
    ll k=b[id].t;
    int mid=(l+r)/2;
    b[id<<1].t+=k;
    b[id<<1|1].t+=k;
    b[id<<1].s+=(mid-l+1)*k;
    b[id<<1|1].s+=(r-mid)*k;
    b[id].t=0;
    return ;
}

void updb(int id,int l,int r,int u,int v,int x)
{
    if(l>v||r<u)return;
    if(l>=u&&r<=v)
    {
        b[id].s+=(r-l+1)*x;
        b[id].t+=x;
        return;
    }
    lazyb(id,l,r);
    int m=(l+r)/2;
    updb(id<<1,l,m,u,v,x);
    updb(id<<1|1,m+1,r,u,v,x);
    b[id].s=b[id<<1].s+b[id<<1|1].s;
}
ll getb(int id,int l,int r,int u,int v)
{
    if(l>v||r<u)return 0 ;
    if(l>=u&&r<=v)return b[id].s;
    lazyb(id,l,r);
    int m=(l+r)/2;
    return (getb(id<<1,l,m,u,v)+getb(id<<1|1,m+1,r,u,v));
}
ll a[maxsize+5];
void nhap()
{
    ll n,q,l,r,t,x;
    cin >> n >> q;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> x;
        a[i]=a[i-1]+x;
    }
    a[n+1]=a[n]+x;
    for(int i = 1 ; i <= q ; i++)
    {
        cin >> t >> l >> r;
        if(t==1)
        {
            updb(1,1,n,l,r,l-1);
            updcnt(1,1,n,l,r,1);
        }
        else
        {
            ll k = a[r]-a[l-1]-getb(1,1,n,l,r)+getcnt(1,1,n,l,r);
            //cout << getb(1,1,n,l,r) << " "<< getcnt(1,1,n,l,r) << endl;
            cout << k << endl;
        }
    }

}
int main()
{

    fastio();
    // inti();
    nhap();
}
