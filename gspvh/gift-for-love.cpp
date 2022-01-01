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
#define task "gift-for-love"
#define ll long long
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
#define fi first
#define se second
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
const ll N = 3e5+5;
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
vector<int>vec[N];
int hi[N],up[N][25],LOG=20,w,q,n,m,u,v,sub,tin[N+5],tout[N+5],cnt=0;
void dfs(int u,int y)
{
    tin[u]=++cnt;
    up[u][0]=y;
     for(int i = 1 ; i <= LOG; i++)
        {
            up[u][i]=up[ up[u][i-1]][i-1];
        }
    for(int p : vec[u])
    {
        if(p==y)continue;
        hi[p]=hi[u]+1;
        dfs(p,u);
    }
    tout[u]=cnt;
}
bool is(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
int lca(int u,int v)
{
     if (is(u, v))
        return u;
    if (is(v, u))
        return v;
    for (int i = LOG; i >= 0; --i)
    {
        if (!is(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

int seed;
int answer(int x,int y,int z)
{
    int l = lca(x,y);
    if (is(z, l))
        return l;
    if (!is(l, z))
        return l;
    int u = lca(x,z);
    int v = lca(y,z);
    if (u == l)
        return v;
    return u;
}
int getRandom(void)
{
    seed = (1997LL * seed + 227) % 1000003;
    return seed;
}
void nhap()
{
    cin >> sub;
    cin >> n >> m ;
    for(int i = 1 ; i <=m ; i++)
    {
        cin >> u >> v  >> w;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    cin >> q >> seed;
    dfs(1,1);
    int res = 0;
    for (int i = 1; i <= q; i++)
    {
        int z = getRandom() % n + 1;
        int l = getRandom() % n + 1;
        int s = getRandom() % n + 1;
        int x;
        if (z == l || l == s || s == z) x = 22071997;
        else x = answer(z, l, s);

        res = ((1LL * res << 30) ^ x) % 998244353;
    }
    cout << res << endl;
}
int main()
{

    fastio();
    // inti();
    nhap();
}
