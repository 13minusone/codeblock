#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool minn(T &A,T B){return A > B ? (A = B,1) : 0;}
template <class T> inline bool maxx(T &A,T B){return A < B ? (A = B,1) : 0;}
//#define int long long
#define rep(i, n) for(int i = 0;i < n;++i)
#define FOR(i, l, r) for(int i = l;i <= r;++i)
#define FOD(i, r, l) for(int i = r;i >= l;--i)
#define dem(x) __builtin_popcount(x)
#define endl '\n'
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define SZ(x) (int)((x).size())
#define fi first
#define se second
typedef pair<int,int> ii;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
//const int mod = 1e9 + 7;
const int N = 1e5 + 5;
int n, m, d1[N], d2[N], d[N];
vector<int> a[N], g[N];
int dfs(int u, int p){
    d1[u] = d[u];
    for(auto v : a[u])if(v != p){
        d[v] = d[u] + 1;
        int h = dfs(v, u);
        if(h > d1[u]){
            d2[u] = d1[u];
            d1[u] = h;
        }
        else maxx(d2[u], h);
    }
    return d1[u];
}
void DFS(int u, int p, int h){
    for(auto v : a[u])if(v != p){
        if(d1[v] == d1[u]){
            DFS(v, u, max(h+1, d2[u]-d[u]+1));
        }
        else{
            DFS(v, u, max(h+1, d1[u]-d[u]+1));
        }
        g[u].pb(d1[v] - d[u]);
    }
    g[u].pb(h);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
//    freopen("c.inp", "r", stdin);
    cin >> n >> m;
    rep(i, n-1){
        int u, v; cin >> u >> v;
        a[u].pb(v), a[v].pb(u);
    }
    dfs(1, 0);
    DFS(1, 0, 0);
    FOR(i, 1, n)sort(all(g[i]));
    while(m--){
        int x, t; cin >> x >> t;
        int pos = upper_bound(all(g[x]), t) - g[x].begin();
        cout << SZ(g[x]) - pos << endl;
    }
}
