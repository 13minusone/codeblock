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
typedef long long ll ;
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll N = 1e5;
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
int u,v;
struct IT
{
    vector<ll>st,lazy;
    int n;
    void segment(int _n)
    {
        n=_n;
        lazy.assign(4*n+5,0);
    }
    void down(int id)
    {
        ll t=lazy[id];
        lazy[id<<1]+=t;
        lazy[id<<1|1]+=t;
        lazy[id]=0;
        return;
    }
    void upd(int id,int l,int r,int u,int v,int val)
    {
        if(l > r|| r < u || l > v )return ;
        if(l>=u&&r<=v){
            lazy[id]+=val;
            return;
        }
        down(id);
        int m=(l+r)/2;
        upd(id<<1,l,m,u,v,val);
        upd(id<<1|1,m+1,r,u,v,val);
    }
    ll get(int id,int l,int r,int x)
    {
        if(l > x || r < x)return 0;
        if(l==r)return lazy[id];
        int m=(l+r)/2;
        down(id);
        return get(id<<1,l,m,x)+get(id<<1|1,m+1,r,x);
    }
    void upd(int l,int r,int c)
    {
        upd(1,1,n,l,r,c);
    }
    ll get(int x)
    {
        return get(1,1,n,x);
    }
};
ll sta[N+5],en[N+5],cnt=0,hi[N+5],depth[5*N+5],high=0;
vector<ll>ed[N+5],open[5*N+5],close[5*N+5];
void dfs(int u,int v)
{
    sta[u]=++cnt;
    for(int i :ed[u])
    {
        if(i==v)continue;
        hi[i]=hi[u]+1;
        high=max(high,hi[i]);
        dfs(i,u);
        depth[hi[i]]++;
        open[hi[i]].push_back(sta[i]);
        close[hi[i]].push_back(en[i]);
    }
    en[u]=cnt;
}
void nhap()
{
    int n,q,x,y;
    cin >> n;
    for(int i = 1 ; i < n ; i++)
    {
        cin >> u >> v;
        ed[u].push_back(v);
        ed[v].push_back(u);
    }
    dfs(1,-1);
    IT tree[high+5];
    depth[0]=1;
    for(int i = 0 ; i <= high;i++)
    {
        tree[i].segment(depth[i]);
    }
    hi[1]=0;
    open[0].push_back(0);
    close[0].push_back(0);
cin >> q;
   while(q--)
        {
        cin >> v >> u;
        if(v==1)
        {
           cin >> x >> y;
            int k=lower_bound(all(open[hi[u]+x]),sta[u])-open[hi[u]+x].begin()+1;
            int f=upper_bound(all(close[hi[u]+x]),en[u])-close[hi[u]+x].begin();
            tree[hi[u]+x].upd(k,f,y);
        }
        else
        {
            int k=lower_bound(all(open[hi[u]]),sta[u])-open[hi[u]].begin()+1;
            cout << tree[hi[u]].get(k) << endl;
       }
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}




