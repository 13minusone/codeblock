/// Do the solution on the paper first
#include <bits/stdc++.h>
using namespace std;
//template <class T> inline bool minn(T &A,T B){return A > B ? (A = B,1) : 0;}
//template <class T> inline bool maxx(T &A,T B){return A < B ? (A = B,1) : 0;}
#define int long long
#define rep(i, n) for(int i = 0;i < n;++i)
#define FOR(i, l, r) for(int i = l;i <= r;++i)
#define FOD(i, r, l) for(int i = r;i >= l;--i)
#define dem(x) __builtin_popcount(x)
#define endl '\n'
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define SZ(x) (int)((x).size())
#define fi first
#define se second
typedef pair<int,int> ii;
//const int dx[4] = {-1, 0, 1, 0};
//const int dy[4] = {0, -1, 0, 1};
//const int base = 311;
//const int mod = 1e9 + 7;
const int N = 3e4 + 5;
int n, dp[20][170][1500], f[1500];
vector<int> d;
int cal(int i, int x, int y, int ok){
    if(i == -1)
    {
        if(a[])
    }
    if(ok && dp[i][x][y] != -1)return dp[i][x][y];
    int res = 0, lim = max(ok*9, d[i]);
    FOR(j, 0, lim)
        res += cal(i-1, x+j, y*10+j, ok|(j < lim));
    if(ok)dp[i][x][y] = res;
    return res;
}
int solve(int x){
    d.clear();
    while(x)d.pb(x%10), x /= 10;
    return cal(SZ(d)-1, 0, 0, 0);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
//    freopen("c.inp", "r", stdin);
//    freopen("c.out", "w", stdout);
    f[0] = f[1] = 1;
    for(int i = 2;i < 1500;++i)if(!f[i])
        for(int j = i*i;j < 1500;j += i)f[j] = 1;
    memset(dp, -1, sizeof dp);
    int t; cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        cout << solve(b)  << " "<< solve(a-1) << endl;
    }
}
