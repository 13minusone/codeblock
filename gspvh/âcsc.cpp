#include <bits/stdc++.h>
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
const int N = int(3e5) + 1;
int n, q;
struct Edge
{
    int u, v, c;
    Edge(int _u = 0, int _v = 0, int _c = 0)
    {
        u = _u;
        v = _v;
        c = _c;
    }
};
vec<Edge> edge;
int res = 1;
map<int, int> a[N];
int main()
{
    fastio();
    init();
    int t;
    cin >> t >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        edge.pb(Edge(x, y, c));
        a[x][0]++;
        a[y][0]++;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u = edge[i].u;
        int v = edge[i].v;
        int c = edge[i].c;
        if (--a[u][0] > 0)
            ++res;
        if (--a[v][0] > 0)
            ++res;
        if (a[u][c] > 0)
            --res;
        if (a[v][c] > 0)
            --res;
        a[u][c]++;
        a[v][c]++;
    }
    cout << res << ' ';
    cin >> q;
    while (q--)
    {
        int x, k;
        cin >> x >> k;
        --x;
        if (edge[x].c == k)
        {
            cout << res << ' ';
            continue;
        }
        int u = edge[x].u;
        int v = edge[x].v;
        int c = edge[x].c;
        a[u][c]--;
        a[v][c]--;
        if (a[u][c] > 0)
            ++res;
        if (a[v][c] > 0)
            ++res;
        if (a[u][k] > 0)
            --res;
        if (a[v][k] > 0)
            --res;
        a[u][k]++;
        a[v][k]++;
        edge[x].c = k;
        cout << res << ' ';
    }
    return 0;
}
