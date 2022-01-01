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
const int N = 5005;
int r, c, m, n;
int a[N][N];
int main()
{
    fastio();
    //init();
    string s;
    cin >> r >> c >> m >> n;
    for (int i = 0; i <= r + 1; i++)
    {
        for (int j = 0; j <= c + 1; j++)
            a[i][j] = 0;
    }
    for (int i = 1; i <= r; i++)
    {
        cin >> s;
        int cnt = 0;
        for (char x : s)
        {
            int nu = 0;
            if ('0' <= x && x <= '9')
                nu = x - '0';
            else if ('A' <= x && x <= 'Z')
                nu = x - 'A' + 10;
            else if ('a' <= x && x <= 'z')
                nu = x - 'a' + 36;
            else if (x == '#')
                nu = 62;
            else
                nu = 63;
            for (int j = 1; j <= 6 && cnt <= c; j++)
            {
                a[i][++cnt] = getBit(j - 1, nu);
            }
            if (cnt > c)
                break;
        }
    }

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }
    int res = 0;
    for (int i = 1; i + m - 1 <= r; i++)
    {
        for (int j = 1; j + n - 1 <= c; j++)
        {
            res = max(res, a[i + m - 1][j + n - 1] - a[i + m - 1][j - 1] - a[i - 1][j + n - 1] + a[i - 1][j - 1]);
        }
    }
    cout << res;
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
