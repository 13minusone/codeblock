#include <bits/stdc++.h>
using namespace std;
///define-zone
#define task "a2round2"
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
const int N = int(8e5) + 1;
const int mod = int(1e9) + 7;
void add(int &a, const int &b)
{
    a += b;
    if (a >= mod)
        a -= mod;
}
int dp[N], n, pos[N];
string s;
void sol()
{
    for (int i = 0; i < n; i++)
        dp[i] = 0;
    char cur = s[0];
    int curPos = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == 'F' || cur == s[i] || cur == 'F')
        {
            dp[i] = dp[i - 1];
            if (s[i] != 'F')
            {
                cur = s[i];
                curPos = i;
            }
            continue;
        }
        int k = 0;
        add(k, curPos);
        add(k, dp[curPos] + 1);
        add(dp[i], k);
        curPos = i;
        cur = s[i];
    }
    int res = 0;
    for (int i = 0; i < n; i++)
        add(res, dp[i]);
    cout << res << '\n';
}
int main()
{
    init();
    fastio();
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        cout << "Case #" << tc << ": ";
        cin >> n >> s;
        sol();
    }
    return 0;
}
/*
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡠⠤⢒⡲⠭⠭⠝⠋⣉⣙⣛⣉⡩⣍⣓⠒⠒⠲⢄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡠⠖⢋⠵⠒⠚⣋⣀⠤⠖⠊⠉⠁⠀⠀⠀⠀⠀⠈⠉⠋⠙⠒⠲⢭⡓⢄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢠⠤⠤⠤⡤⢤⣀⣴⢫⠼⠓⢁⣀⡤⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠲⡀⡀⠈⠑⢦⣱⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⡠⡮⠿⣍⠭⡿⠚⠛⠛⢿⡃⠀⡠⠋⠀⠀⠀⠀⡰⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠰⡄⠘⣌⠢⡀⠀⠙⢿⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠸⡔⣇⠤⢴⡄⢹⠀⠀⠀⠀⠘⣿⠀⠀⠀⠀⠀⢰⠃⡸⠀⠀⠀⠀⢸⡀⡇⠀⠀⠀⠀⠀⠀⢱⠀⡘⣆⠙⢦⠀⠀⠙⢧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⢠⣁⠿⣄⣠⣃⣼⠀⠀⠀⠀⢀⡟⠀⠀⠀⠀⠀⡟⠀⡇⠀⢠⠀⢀⣸⡇⢣⠀⠀⠀⠀⠀⠀⠀⣇⢇⢻⣧⡄⣷⡀⠀⠉⢇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⣦⣽⣀⣀⣀⣀⣇⠀⠀⠀⢀⣾⠃⠀⠀⠀⠀⢰⡇⣠⡧⠖⢺⠁⠀⠸⡇⢸⠀⢠⠀⠀⠀⠀⠀⢸⢼⡽⡿⣾⣾⣧⠀⠀⠘⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠈⢳⡈⠁⠀⠈⠙⣄⠀⣠⣾⠇⠀⠀⠀⠀⠀⣾⣟⣽⡇⠀⢸⠀⠀⠀⣿⡀⣇⢸⡀⠀⠀⠀⠀⢸⣸⡇⡇⠈⢿⡿⡆⣟⢒⢿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠉⠓⣶⣶⣶⣿⡍⠓⡿⠀⠀⠀⠀⠠⠊⣿⣿⡇⡇⠀⠸⡆⠀⠀⣯⢧⠸⡀⣧⠀⠀⠀⠀⢸⣿⢿⡇⠀⠈⢻⣷⠘⢆⠙⢧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⣿⠋⣾⣿⢻⢦⡏⠀⠀⠀⠀⠀⠀⣿⡿⠀⢷⢠⣀⣇⣀⣄⣹⠘⣤⣳⣸⣔⣄⣆⣤⣼⠾⠿⠻⠷⢶⣌⣿⡄⢈⠇⣸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣼⡇⢀⣿⡏⣏⣧⡇⠀⠀⠀⠀⠀⠀⣿⢁⣴⠿⠛⢛⣙⣛⠛⠉⠁⠀⠀⠀⠀⠀⠀⠈⢡⣄⣹⣿⣷⣄⠙⣿⣧⢸⠰⣻⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⣸⠃⡗⣸⣿⢧⠘⣿⡇⠀⠀⠀⠀⠀⠀⣷⡟⠁⢀⡈⣻⣿⣿⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⡿⣿⡄⠸⣇⠵⠞⢹⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⣿⢸⣷⡏⢸⡝⠲⣿⡇⠀⠀⠀⠀⠀⠀⣿⠀⠀⢸⣿⣿⣿⣿⠛⢿⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⡙⠛⠁⣽⠃⠀⠻⣄⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠘⡿⢻⠃⢸⡟⠳⠛⣧⠀⠀⠀⠀⠀⠀⡟⠀⠀⠸⣿⡙⠛⠋⢀⡟⠀⠀⠀⠀⠀⠀⠀⠄⠀⠈⠛⠿⠟⠋⢀⢀⠀⠘⣆⢸⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⢀⡇⡿⡆⢸⠹⣄⠀⢿⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⠉⡛⡚⠒⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⡱⢣⢏⣞⡆⢹⣼⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⣼⣸⠁⣷⢸⡆⢹⣷⣼⡄⠀⠀⠀⠀⠀⣿⠀⢠⢎⠞⡼⡱⠱⠁⠀⠀⠀⠀⣀⣠⣤⣤⣤⣄⡀⠀⠀⠀⠁⠋⠘⠀⠀⢸⣿⡿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⢠⣿⡇⠀⣿⡆⣧⢸⣿⣿⣇⠀⠀⠀⠀⠀⣿⠀⠀⠋⠘⠈⠁⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⢿⠁⠀⠀⠀⠀⠀⠀⠀⢀⣼⣿⡇⢻⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⣼⣿⠀⢠⣿⣧⢸⡄⣿⣿⣿⡄⠀⠀⠀⠀⢸⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⢿⣿⣿⡿⠯⠋⠀⠀⠀⠀⠀⠀⠀⣠⣾⡿⢓⡇⠸⡇⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⢰⣿⠇⠀⢸⣿⠻⠀⢷⣿⣿⣿⣇⠀⠀⠀⠀⢸⣧⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣴⣾⣿⣿⠁⢨⡇⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⣸⣿⠀⠀⡾⡁⠀⠀⣸⣿⣿⣿⣿⡄⠀⠀⠀⠈⣿⣿⣿⣶⣦⣤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣤⣴⣶⣿⣿⣿⣿⣿⡟⠀⣿⡇⠀⢻⡇⠀⠀⠀⠀⠀⠀⠀
⠀⠀⣿⡿⣆⢰⠇⠀⠀⠀⣿⣿⣿⣿⣿⣷⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⡻⠧⠥⣄⣀⡀⣎⢿⣿⣿⣿⢿⣿⣿⣿⣿⣿⣿⣿⡇⢸⢹⠇⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀
⠀⠀⢿⢷⠈⡿⡀⠀⠀⢰⣿⣿⣿⣿⣿⣿⣇⠀⠀⠀⢹⣿⣿⡿⠛⠻⣧⣧⣤⡄⠀⠠⢽⣇⡈⣹⣿⠻⣿⣿⣿⣿⣿⣿⣿⣿⡇⣾⢸⠀⠀⣸⡇⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠘⣾⣶⢧⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⡄⠀⠀⠘⣿⣿⣀⡠⠞⣿⠽⢯⣬⣷⣚⠛⢿⣏⣥⡾⠳⣽⣿⣿⣿⣿⣿⣿⣿⢳⣿⣾⠀⠀⡏⡇⠀⠀⠀⠀⠀⠀⠀
*/
