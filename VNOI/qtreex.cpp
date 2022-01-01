/*
🛸　　　 　🌎　°　　🌓　•　　.°•　　　🚀 ✯
　　　★　*　　　　　°　　　　🛰 　°·　　                           🪐
.　　　•　° ★　•  ☄
______________________________________________________
    You are watching a brute force code
        CODE IS WRITTEN BY 13MINUSONE
*/
#include<bits/stdc++.h>
using namespace std;
#define task "c"
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
#define all(x) x.begin(),x.end()
#define endl '\n'
#define fi first
#define se second
typedef long long ll ;
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }
const ll N = 1e4+5;
const ll mod =1e9+9;
const ll base = 311;
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
vector<ii>edge[N];
ii canh[N];
int head[N],n,m,u,v,c,cnt=0,num[N],child[N],par[N],chainid[N],nchain=1,val[N],pos[N],hi[N];
void dfs(int u )
{
    child[u]=1;
    for(ii i : edge[u])
    {
        if(i.fi!=par[u]){
                hi[i.fi]=hi[u]+1;
                par[i.fi]=u;
                val[i.fi]=i.se;
            dfs(i.fi);
        child[u]+=child[i.fi];
        }
    }
}
void hld(int u)
{
    if(!head[nchain])head[nchain]=u;
    chainid[u]=nchain;
    num[u]=++cnt;
    pos[cnt]=u;
    int Bigchild=-1;
    for(ii i : edge[u])
    {
        if(i.fi!=par[u])
        {
            if(Bigchild == -1 || child[i.fi]>child[Bigchild])
            {
                Bigchild=i.fi;
            }
        }
    }
    if(Bigchild != -1 ) hld(Bigchild);
    for(ii i : edge[u])
    {
        if(i.fi!=par[u] && i.fi != Bigchild)
        {
            nchain++;
            hld(i.fi);
        }
    }
}
struct segtree
{
    vector<int>maxx,minn,lazy;
    int n;
    void SEG(int n_ = 0)
    {
        n=n_;
        maxx.assign(4*n,-mod);
        minn.assign(4*n,mod);
        lazy.assign(4*n,0);
        return;
    }
    void pushDown(int id)
    {
        int t = lazy[id];
        lazy[id<<1]+=t;
        lazy[id<<1|1]+=t;
        lazy[id]=0;
        return;
    }
    void build(int id,int l ,int r)
    {
        if(l==r)
        {
            if(l==1)maxx[id]=-mod,minn[id]=mod;
            else maxx[id]=minn[id]=val[pos[l]];
            return;
        }
        int mid=(l+r)>>1;
        build(id<<1,l,mid);build(id<<1|1,mid+1,r);
        maxx[id]=max(maxx[id<<1],maxx[id<<1|1]);
        minn[id]=min(minn[id<<1],minn[id<<1|1]);
    }
    void updlazy(int id,int l,int r,int u,int v)
    {
        if(l > v || r < u || l >r)return ;
        if(l >= u && r <= v)
        {
            lazy[id]+=1;
            return;
        }
        pushDown(id);
        int mid=(l+r)>>1;
        updlazy(id<<1,l,mid,u,v);
        updlazy(id<<1|1,mid+1,r,u,v);

    }
    void updval(int id,int l,int r,int x,int val)
    {
        if(l>x||r<x)return;
        if(l==x )
        {
             maxx[id]=minn[id]=val;
             return;
        }
        int mid=(l+r)>>1;
        updval(id<<1,l,mid,x,val);
        updval(id<<1|1,mid+1,r,x,val);
        maxx[id]=max(maxx[id<<1],maxx[id<<1|1]);
        minn[id]=min(minn[id<<1],minn[id<<1|1]);
    }
    ll getm(int id,int l,int r,int u,int v)
    {
        if(l>r||l>v||r<u)return -mod;
        if(l >= u && r <= v)
        {
            if(lazy[id]%2==1)return -minn[id];
            else return maxx[id];
        }
        pushDown(id);
        int mid=(l+r)>>1;
        int L = getm(id<<1,l,mid,u,v);
        int R = getm(id<<1|1,mid+1,r,u,v);
        return max(L,R);
    }
    ll getm(int u,int v)
    {
        return getm(1,1,n,u,v);
    }
    void updlazy(int u,int v)
    {
        updlazy(1,1,n,u,v);
    }
    void updval(int x,int val)
    {
        updval(1,1,n, x, val);
    }
};
segtree IT;
void lazy(int a,int b)
{
    while(chainid[a]!=chainid[b])
    {
        if(hi[a] < hi[b])swap(a,b);
        IT.updlazy(num[head[chainid[a]]],num[a]);
        a=par[head[chainid[a]]];
    }
    if(hi[a]<hi[b])swap(a,b);
    IT.updlazy(num[b]+1,num[a]);
}
ll getmax(int a,int b)
{
    ll maxx=-mod;
     while(chainid[a]!=chainid[b])
    {
        if(hi[a] < hi[b])swap(a,b);
        maxx=max(maxx,IT.getm(num[head[chainid[a]]],num[a]));
        //cout << maxx << endl;
        a=par[head[chainid[a]]];
    }
    if(hi[a]<hi[b])swap(a,b);
    maxx=max(maxx,IT.getm(num[b]+1,num[a]));
    return maxx;
}
int t;
void nhap()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1; i < n ; i++)
        {
            cin >> u >> v >> c;
            edge[u].push_back(ii(v,c));
            edge[v].push_back(ii(u,c));
            canh[i]=ii(u,v);
        }
        cnt=0;
        nchain=0;
        par[1]=1;
        dfs(1);
        hld(1);
        IT.SEG(cnt);
        IT.build(1,1,cnt);
        string s;
        while(cin >> s)
        {
            if(s=="DONE")break;
            cin >> u >> v;
            if(s=="CHANGE")
            {
                int x=canh[u].fi;
                int y=canh[u].se;
                if(hi[x] < hi[y])swap(x,y);
                IT.updval(num[x],v);
            }
            else if(s == "NEGATE")
            {
                lazy(u,v);
            }else
            {
                cout<< getmax(u,v)<<endl;
            }
        }
        for(int i = 1; i <= n ; i++)
        {
            edge[i].clear();
            head[i]=0;
            chainid[i]=0;
        }
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}




