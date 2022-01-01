include <bits/stdc++.h>
using namespace std;
int n, in[200005], out[200005], p[200005], res;
int j, x, y, mx[18][300005], my[18][300005];
vector<int> adj[200005], d1(2e5+5, 0), d2(2e5+5, 0);
void DFS(int u){
    in[u] = ++j;
    mx[0][j] = d1[u];
    my[0][j] = d2[u];
    for(auto v : adj[u])if(v != p[u])
        p[v] = u, DFS(v);
    out[u] = j;
}
void bfs(int u,vector<int> &d){
    d[u] = 1; queue<int> q; q.push(u);
    while(!q.empty()){
        int i = q.front(); q.pop();
        for(auto j : adj[i])if(!d[j])
            d[j] = d[i] + 1, q.push(j);
    }
}
int getx(int l,int r){
    if(l > r)return 0;
    int LOG = log2(r - l + 1);
    return max(mx[LOG][l], mx[LOG][r-(1<<LOG)+1]);
}
int gety(int l,int r){
    if(l > r)return 0;
    int LOG = log2(r - l + 1);
    return max(my[LOG][l], my[LOG][r-(1<<LOG)+1]);
}
void trace(int u){
    if(u == x)return;
    int x1 = max(getx(1, in[u]-1), getx(out[u]+1, n));
    int x2 = gety(in[u], out[u]);
    res = max(res, min(x1, x2));
    trace(p[u]);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
//    freopen("c.inp","r",stdin);
    cin >> n;
    for(int i = 1;i < n;++i){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> x >> y;
    bfs(x, d1), bfs(y, d2);
    DFS(x);
    for(int i = 1;i <= 17;++i)for(int j = 1;j + (1<<i) - 1 <= n;++j){
        mx[i][j] = max(mx[i-1][j], mx[i-1][j+(1<<(i-1))]);
        my[i][j] = max(my[i-1][j], my[i-1][j+(1<<(i-1))]);
    }
    trace(y);
    cout << res;
}
