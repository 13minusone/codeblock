#include<bits/stdc++.h>
using namespace std;
#define task "select"
#define ll long long
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll maxsize = 1000000;
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
struct node{
    ll s , t;
};
node st[maxsize*4+5];
void lazy(int id)
{
    int k=st[id].t;
    st[id<<1].s+=k;
    st[id<<1].t+=k;
    st[id<<1|1].s+=k;
    st[id<<1|1].t+=k;
    st[id].t=0;

}
void upd(int id,int l,int r,int u,int v,int x)
{
    if(l>v||r<u)
    {
        return ;
    }
    if(l>=u&&r<=v)
    {
        st[id].s+=x;
        st[id].t+=x;
        return;
    }
    lazy(id);
    int m=(l+r)/2;
    upd(id<<1,l,m,u,v,x);
    upd(id<<1|1,m+1,r,u,v,x);
    st[id].s=min(st[id<<1].s,st[id<<1|1].s);
}
ll get(int id,int l,int r)
{
    if(l==r)
    {
        return l;
    }
    lazy(id);
    int m=(l+r)/2;
    if(st[id<<1|1].s<0)
    {
        return get(id<<1|1,m+1,r);
    }
    if(st[id<<1].s<0)
    {
        return get(id<<1,l,m);
    }
    return -1;
}

int a[3000005],b[3000005],n,m,q,t,l,r;
void nhap()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
        upd(1,1,maxsize,1,a[i],-1);
    }
    for(int i = 1 ; i<= m ; i++)
    {
        cin >> b[i];
        upd(1,1,maxsize,1,b[i],1);
    }
    cin >> q;
    for(int i = 1 ; i <= q ; i++)
    {
        cin >> t >> l >> r;
        if(t==1)
        {
            upd(1,1,maxsize,1,a[l],1);
            a[l]=r;
            upd(1,1,maxsize,1,a[l],-1);
        }
        else
        {
            upd(1,1,maxsize,1,b[l],-1);
            b[l]=r;
            upd(1,1,maxsize,1,b[l],1);
        }
        cout << get(1,1,maxsize) << endl;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}



