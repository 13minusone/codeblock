#include <bits/stdc++.h>
using namespace std;
///define-zone
#define task "mst"
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
template <class val>
inline val gcd(val a, val b) { return (a ? gcd(b % a, a) : b); }
template <class val>
inline val fmul(val a, val b, val m)
{
    if (!b)
        return 0;
    if (!(b - 1))
        return a;
    if (b % 2)
        return (fmul(a, b / 2, m) * 2 + a) % m;
    else
        return (fmul(a, b / 2, m) * 2) % m;
}
template <class val>
inline bool getBit(val pos, val mask) { return ((mask >> pos) & 1); }
void fastio()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}
void init()
{
    freopen(task ".inp", "r", stdin);
    freopen(task ".out", "w", stdout);
}
const int N = 500005;
struct Edge
{
    int u, v, val, id;
    Edge(int _u = 0, int _v = 0, int _val = 0, int _id = 0)
    {
        u = _u;
        v = _v;
        val = _val;
        id = _id;
    }
};
bool cmp(const Edge &a, const Edge &b)
{
    return (a.val < b.val);
}
vec<Edge> edge;
int n, m, par[N];
int root(int u)
{
    if (par[u] == u)
        return u;
    else
        return par[u] = root(par[u]);
}
void join(int u, int v)
{
    par[root(u)] = root(v);
}
int ans[N];
int main()
{
    fastio();
    init();
    int t;
    cin >> t >> n >> m;
    edge.resize(m);
    if (t > 3)
        return 0;
    memset(ans, -1, sizeof(ans));
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        edge[i] = Edge(x, y, w, i);
    }
    sort(SZ(edge), cmp);
    for (int i = 0; i < m; i++)
    {
        for (int i = 1; i <= n; i++)
            par[i] = i;
        for (int j = 0; j < m; j++)
        {
            if (i == j)
                continue;
            join(edge[j].u, edge[j].v);
            if (root(edge[i].u) == root(edge[i].v))
            {
                ans[edge[i].id] = max(ans[edge[i].id], edge[j].val - 1);
                break;
            }
        }
    }
    for (int i = 0; i < m; i++)
        cout << ans[i] << ' ';
    return 0;
}
