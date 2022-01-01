#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int LIM = 111;

int n, k;
string a[111];
int cost[111][111];

string u, v;
int f[111][111];

/// Solve for each pair
int calc(int i = 0, int j = 0)
{
    if (i >= u.size()) return int(v.size()) - j; /// da xoa het (u), con lai (|v| - j) ki tu cua (v)
    if (j >= v.size()) return int(u.size()) - i; /// tuong tu nhu tren

    int &res = f[i][j];
    if (res != -1) return res;
    res = +INF;

    res = min(calc(i + 1, j), calc(i, j + 1)) + 1;
    if (u[i] == v[j])
        res=min(res, calc(i + 1, j + 1) + 1);

    return res;
}

int g[1 << 22];
/// Solve for all pairs
int solve(int i = 1, int mask = 0)
{
    if (i > n) return 0;
    if (mask >> i & 1) return solve(i + 1, mask);

    int &res = g[mask];
    if (res != -1) return res;
    res = +INF;

    for (int j = i + 1; j <= n; ++j)
    {
        if (mask >> j & 1) continue; /// (j) is used
        res=min(res, max(solve(i + 1, mask | (1 << j)), cost[i][j]));
    }

    return res;
}

int main()
{
    /// Input
    cin >> n;
    k = 1 * n;
    n = 2 * n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    /// Precalculating
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            u = a[i];
            v = a[j];
            memset(f, -1, sizeof(f));
            cost[i][j] = cost[j][i] = calc();
        }
    }

    /// Solving
    memset(g, -1, sizeof(g));
    cout << solve();
    return 0;
}
