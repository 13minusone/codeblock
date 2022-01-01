#include<bits/stdc++.h>
using namespace std;
#define task "thi"
#define pb push_back
#define ll long long
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define sz(x) s.size()
#define getbit(x,i) (((x)>>(i))&1)
#define turnoff(x,i) ((x)&(~(1<<i)))
#define CNTBIT(x) __builtin_popcount(x)
#define MAX int(1e5)+5
const ll mod = int(1e9)+7;
const int base = 311;
typedef pair<int, int> ii;
void init()
{
    if (fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
}
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
vector<ii> adj[MAX];
int n, q;
void read()
{
    cin >> n >> q;
    for(int i=1; i<n; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        adj[x].pb(ii(y,c));
        adj[y].pb(ii(x,c));
    }
}
vector<int> res;
bool vis[2005];
void dfs(int u, int val)
{
    for(ii tmp:adj[u])
    {
        int v=tmp.fi, c=max(tmp.se, val);
        if (vis[v]) continue;
        vis[v]=true;
        res.pb(c);
        dfs(v,c);
    }
}
void sub1()
{
    for(int i=1; i<=n; i++)
    {
        memset(vis, false, sizeof vis);
        vis[i]=true;
        dfs(i,-1);
    }
    sort(all(res));
    vector<int> tmp;
    int i=0, l, r;
    while(q--)
    {
        cin >> l >> r;
        int k1=lower_bound(all(res), l) - res.begin();
        int k2=upper_bound(all(res), r) - res.begin();
        cout << (k2-k1)/2 << "\n";
    }
}
void sub2()
{
    for(int i=1; i<=q; i++) cout << 1LL*n*(n-1)/2 << "\n";
}
void sol()
{
    if (n<=4000) sub1();
    else sub2();
}
int main()
{
    fastio();
    init();
    read();
    sol();
}
