#include <bits/stdc++.h>
using namespace std;
///define-zone
#define task "gianseq"
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
const int N = 2005;
int n, k, a[N];
ll dp[N];
bool check(ll r)
{
    for (int i = 1; i <= n; i++)
        dp[i] = i - 1;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j < i; j++)
            if (abs(a[i] - a[j]) <= ll(r * (i - j)))
                dp[i] = min(dp[i], dp[j] + (i - j - 1));
    }
    if (dp[n] <= k)
        return true;
    ll ans = k + 1;
    for (int i = 1; i <= n; i++)
        ans = min(ans, dp[i] + n - i);
    return (ans <= k);
}
int main()
{
    fastio();
    init();
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ll l = 0, r = 1e18, mid, res;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (check(mid))
        {
            res = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << res;
    return 0;
}
