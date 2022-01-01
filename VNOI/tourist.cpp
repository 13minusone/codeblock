#include<bits/stdc++.h>
using namespace std;
#define task "thi"
#define pb push_back
#define ll long long
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define sz(x) s.size()
#define MASK(i) ((1LL)<<(i))
#define getbit(x,i) (((x)>>(i))&1)
#define turnoff(x,i) ((x)&(~(1<<i)))
#define CNTBIT(x) __builtin_popcount(x)
#define MAX int(2e5)+5
#define LOG 18
#define MASK(i) (1LL << (i))
const int mod = int(1e9)+7;
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
int dx[]={0,0,1,-1,1,1,-1,-1};
int dy[]={1,-1,0,0,1,-1,1,-1};
int n;
int sta[MAX], fin[MAX], distA[MAX], distB[MAX], par[MAX];
int lg2[MAX], fA[MAX][LOG+2], fB[MAX][LOG+2];
vector<int> adj[MAX];
int cnt=0, A, B;
void bfs(int dist[], int s)
{
    queue<int> q;
    dist[s] = 1;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v:adj[u])
        {
            if (dist[v]==0)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}
void dfs(int u)
{
    sta[u]=++cnt;
    fA[cnt][0] = distA[u];
    fB[cnt][0] = distB[u];
    for(int v:adj[u])
    {
        if (v!=par[u])
        {
            par[v] = u;
            dfs(v);
        }
    }
    fin[u] = cnt;
}
void RMQ()
{
    for(int j=1; j<=LOG; j++)
    {
        for(int i=1; i<=n-MASK(j)+1; i++)
        {
            fA[i][j] = max(fA[i][j-1], fA[i+MASK(j-1)][j-1]);
            fB[i][j] = max(fB[i][j-1], fB[i+MASK(j-1)][j-1]);
        }
    }
}
int get_dist(int l, int r, int f[MAX][LOG+2])
{
    if (l>r) return 0;
    int k = lg2[r-l+1];
    return max(f[l][k], f[r-MASK(k)+1][k]);
}
void read()
{
    cin >> n;
    for(int i=1; i<n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i=1; i<=n; i++)
    {
        while(MASK(lg2[i])<=i) lg2[i]++;
        lg2[i]--;
    }
    cin >> A >> B;
}
void sol()
{
    bfs(distA, A);
    bfs(distB, B);
    dfs(A);
    RMQ();
    int ans=0;
    while(true)
    {
        if (B==A) break;
        int res1 = get_dist(sta[B], fin[B], fB);
        int res2 = max(get_dist(1, sta[B]-1, fA), get_dist(fin[B]+1, n, fA));
        //cout << res1 << " " << res2 << "\n";
        ans = max(ans, min(res1, res2));
        B=par[B];
    }
    cout << ans;
}
int main()
{
    fastio();
    init();
    read();
    sol();
}
