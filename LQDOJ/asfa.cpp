///KhoaHo///
#include<bits/stdc++.h>
using namespace std;
#define task "SUM213NCNT"

void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void init()
{
    freopen("SUM213NCNT.inp", "r", stdin);
    freopen("SUM213NCNT.out", "w", stdout);
}
int m;
pair<long long, long long> p[101];
int dp(long long i, int j = 1)
{
    if(i == 0) return 0;
    if(j > m) return 1;
    if(i < p[j].first) return 1;
    int ans = dp(i, j + 1);
    for(int k = 1; k <= p[j].second; k++)
    {
        if(i < p[j].first) break;
        i /= p[j].first;
        ans += dp(i, j + 1);
    }
    return ans;
}
int main()
{
    fastio();
    init();
    cin >> m;
    for(int i = 1; i <= m; i++) cin >> p[i].first >> p[i].second;
    sort(p + 1, p + m + 1);
    for(int i = 1; i <= 3; i++)
    {
        int A, B;
        cin >> A >> B;
        cout << dp( B ) - dp(A - 1) << '\n';
    }
    return 0;
}
