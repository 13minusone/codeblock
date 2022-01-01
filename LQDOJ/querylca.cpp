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
typedef long long ll ;
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll maxsize = 300000;
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
ll up[maxsize+5][23],LOG=19,hi[maxsize+5];
vector<int>ed[maxsize+5];
int n,x,y,q;
void dfs(int u,int v)
{
    for(int i = 1 ; i <= LOG;i++)
        {
            up[u][i]=up[ up[u][i-1] ][ i-1 ];
        }
    for(int p : ed[u])
    {
        if(p==v)continue;
        up[p][0]=u;
        hi[p]=hi[u]+1;
        dfs(p,u);
    }
}
ll lca(int u ,int v)
{
    if(u==n+1)return v;
    else if(v==n+1)return u;
    if(hi[u]<hi[v])swap(u,v);
    ll dif=hi[u]-hi[v];
    for(int i = LOG;i>=0;--i)
    {
        if(dif&(1<<i))
        {
            u=up[u][i];
        }
    }
    if(u==v)return u;
    for(int i = LOG;i>=0;i--)
    {
        if(up[u][i]!=up[v][i])
        {
            u=up[u][i];
            v=up[v][i];
        }
    }
    return up[u][0];
}
ll st[maxsize*4+5];
void build(int id,int l,int r)
{
    if(l==r)
    {
        st[id]=l;
        return ;
    }
    int m=(l+r)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    st[id]=lca(st[id*2],st[id*2+1]);
}
ll get(int id,int l,int r,int u,int v)
{
    if(l>v||r<u||l>r)return n+1;
    else if(l>=u&&r<=v)return st[id];
    int m=(l+r)/2;
    return lca(get(id*2,l,m,u,v),get(id*2+1,m+1,r,u,v));
}
void nhap()
{
    hi[0]=0;
    cin >> n ;
    for(int i = 1 ; i < n ; i++)
    {
        cin >> x >> y;
        ed[x].push_back(y);
        ed[y].push_back(x);
    }
    dfs(1,-1);
    build(1,1,n);
    cin >> q;
    while(q--)
    {
        cin >> x >> y;
        cout << get(1,1,n,x,y) << endl;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}




