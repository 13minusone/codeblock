//CODE IS WRITTEN BY 13MINUSONE
#include<bits/stdc++.h>
using namespace std;
#define task "c9"
#define SZ(c) (c).size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define __builtin_popcount __builtin_popcountll
#define all(x) (x).begin(),(x).end()
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define fi first
#define se second
#define For(i,l,r) for(int i = l ; i < r ;i++)
#define Fore(i,l,r) for(int i = l ; i <= r ; i++)
#define Ford(i,l,r) for(int i = l ; i >= r ; i--)
typedef long long ll ;
typedef pair<int,int> ii;
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
const ll N = 1e5 + 5;
const ll mod =1e9+9;
const ll base = 311;
const int block = 488;
int n, m, hi1[N], hi2[N], hi[N];
vector<int> edge[N], vec[N];
int dfs(int u, int p){
    hi1[u] = hi[u];
    for(int v : edge[u])
        if(v != p){
        hi[v] = hi[u] + 1;
        int h = dfs(v, u);
        if(h > hi1[u]){
            hi2[u] = hi1[u];
            hi1[u] = h;
        }
        else maximize(hi2[u], h);
    }
    return hi1[u];
}
void DFS(int u, int p, int h){
    for(int v : edge[u])
        if(v != p){
        if(hi1[v] == hi1[u]){
            DFS(v, u, max(h+1, hi2[u]-hi[u]+1));
        }
        else{
            DFS(v, u, max(h+1, hi1[u]-hi[u]+1));
        }
        vec[u].push_back(hi1[v] - hi[u]);
    }
    vec[u].push_back(h);
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int u, v;
    cin >> n >> m;
    For(i,1, n){
        cin >> u >> v;
        edge[u].push_back(v), edge[v].push_back(u);
    }
    dfs(1, 0);
    DFS(1, 0, 0);
    Fore(i, 1, n)sort(all(vec[i]));
    int x, t;
    while(m--){
         cin >> x >> t;
        int pos = upper_bound(all(vec[x]), t) - vec[x].begin();
        cout << SZ(vec[x]) - pos << endl;
    }
}
