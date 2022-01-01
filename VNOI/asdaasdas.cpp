///KhoaHo///
#include<bits/stdc++.h>
using namespace std;
///define-zone
#define task "test"
#define vec vector
#define priq priority_queue
#define pf push_front
#define pb push_back
#define popb pop_back
#define popf pop_front
#define SZ(a) a.begin(), a.end()
#define SZZ(a, begin, end) a + begin, a + begin + end
#define fi first
#define se second
#define BIT(n) (1 << n)


///typedef-zone
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldb;
typedef double db;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

///code-mau
template<class val> inline val gcd(val a, val b){ return (a ? gcd(b%a, a): b);}
template<class val> inline val fmul(val a, val b, val m){ if (!b) return 0; if (!(b-1)) return a; if (b%2) return (fmul(a, b/2, m)*2+a)%m; else return (fmul(a, b/2, m)*2)%m; }
template<class val> inline bool getbit(val pos, val mask) {return ((mask >> pos)&1);}
void fastio()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}
void init()
{
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
}
const int N = int(1e5) + 1;
const int logg = 20;
vec<vec<ii> > adj(N);
int par[N][logg], minn[N][logg], maxx[N][logg], depth[N];
int NumNodes, Querries;
void dfs(int u, int p)
{
    for(ii v : adj[u])
    {
        if(v.se == p) continue;
        depth[v.se] = depth[u] + 1;
        par[v.se][0] = u;
        maxx[v.se][0] = v.fi;
        minn[v.se][0] = v.fi;
        dfs(v.se, u);
    }
}
int lca(int x, int y)
{
    if(depth[x] < depth[y]) return lca(y, x);
    for(int i = 19; i >= 0; i--) if(depth[par[x][i]] >= depth[y])
    {
        x = par[x][i];
    }
    if(x == y) return x;
    for(int i = 19; i >= 0; i--) if(par[x][i] != par[y][i])
    {
        x = par[x][i];
        y = par[y][i];
    }
    return par[x][0];
}
int getmaxx(int u, int cha)
{
    int Max = 0;
    for(int i = 19; i >= 0; i--)
    {
        if((par[u][i] > 0)&&(depth[par[u][i]] >= depth[cha]))
        {
            Max = max(Max, maxx[u][i]);
            u = par[u][i];
        }
    }
    return Max;
}
int getminn(int u, int cha)
{
    int Min = 1e9;
    for(int i = 19; i >= 0; i--)
    {
        if((par[u][i] > 0)&&(depth[par[u][i]] >= depth[cha]))
        {
            Min = min(Min, minn[u][i]);
            u = par[u][i];
        }
    }
    return Min;
}
int main()
{
    fastio();
    ///init();
    cin >> NumNodes;
    for(int i = 2; i <= NumNodes; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        adj[x].pb(ii(c, y));
        adj[y].pb(ii(c, x));
    }
    depth[0] = -1;
    depth[1] = 0;
    dfs(1, -1);
    for(int i = 1; i < 20; i++)
    {
        for(int u = 1; u <= NumNodes; u++)
        {
            int t = par[u][i - 1];
            par[u][i] = par[t][i - 1];
            maxx[u][i] = max(maxx[u][i - 1], maxx[t][i - 1]);
            minn[u][i] = min(minn[u][i - 1], minn[t][i - 1]);
        }
    }
    cin >> Querries;
    while (Querries--)
    {
        int x, y;
        cin >> x >> y;
        int cha = lca(x, y);
        //cout << cha << '\n';
        int maxx1 = getmaxx(x, cha);
        int maxx2 = getmaxx(y, cha);
        int minn1 = getminn(x, cha);
        int minn2 = getminn(y, cha);
        cout << min(minn1, minn2) << " " << max(maxx1, maxx2) << '\n';
    }
    return 0;
}
