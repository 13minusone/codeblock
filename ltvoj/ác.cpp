#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int jump[25][70005], d[70005], pos[70005];
int ma[25][70005], mi[25][70005], j, n, m;
vector<int> a[70005];
void DFS(int u){
    ma[0][u] = mi[0][u] = ++j; pos[j] = u;
    for(int i = 1;1<<i <= n;++i)jump[i][u] = jump[i-1][jump[i-1][u]];
    for(int v : a[u])if(v != jump[0][u]){
        jump[0][v] = u;
        d[v] = d[u] + 1;
        DFS(v);
    }
}
int lca(int u,int v){
    if(d[u] < d[v])swap(u,v);
    int diff = d[u] - d[v];
    for(int i = 16;i >= 0;--i)if(diff>>i&1)u = jump[i][u];
    if(u == v)return u;
    for(int i = 16;i >= 0;--i)if(jump[i][u] != jump[i][v]){
        u = jump[i][u];
        v = jump[i][v];
    }
    return jump[0][u];
}
int maxx(int l,int r){
    int LOG = log2(r - l + 1);
    return max(ma[LOG][l], ma[LOG][r-(1<<LOG)+1]);
}
int minn(int l,int r){
    int LOG = log2(r - l + 1);
    return min(mi[LOG][l], mi[LOG][r-(1<<LOG)+1]);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
//    freopen("c.inp","r",stdin);
    cin >> n ;
    for(int i = 1;i < n;++i){
        int u, v; cin >> u >> v;
        a[u].pb(v); a[v].pb(u);
    }
    DFS(1);
    for(int i = 1;i <= log2(n);++i)for(int j = 1;j+(1<<i)-1 <= n;++j){
        ma[i][j] = max(ma[i-1][j], ma[i-1][j+(1<<(i-1))]);
        mi[i][j] = min(mi[i-1][j], mi[i-1][j+(1<<(i-1))]);
    }
    cin >> m;
    while(m--){
        int l, r; cin >> l >> r;
        int u = maxx(l, r);
        int v = minn(l, r);
        cout << lca(pos[u], pos[v]) << endl;
    }
}
