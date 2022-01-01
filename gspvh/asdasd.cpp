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
const int N = int(1e6) + 1;
string a[3], b[3];
int sum1 = 0, sum2 = 0;
map<char, int> val;
char Max(char a, char b)
{
    if (val[a] > val[b])
        return a;
    return b;
}
void solve()
{
    char max1 = 'N', max2 = 'N';
    sum1 = 0;
    sum2 = 0;
    for (int i = 0; i < 3; i++)
    {
        cin >> a[i];
        max1 = Max(max1, a[i][1]);
        sum1 += (a[i][0] == 'A' ? 1 : a[i][0] - '0');
    }
    cin >> b[0];
    for (int i = 0; i < 3; i++)
    {
        cin >> b[i];
        max2 = Max(max2, b[i][1]);
        sum2 += (b[i][0] == 'A' ? 1 : b[i][0] - '0');
    }
    sum1 %= 10;
    sum2 %= 10;
    if (sum1 == 0)
        sum1 = 10;
    if (sum2 == 0)
        sum2 = 10;
    if (sum1 > sum2)
    {
        cout << "Yes ";
        return;
    }
    if (sum1 < sum2)
    {
        cout << "No ";
        return;
    }
    if (val[max1] > val[max2])
    {
        cout << "Yes ";
        return;
    }
    else if (val[max1] < val[max2])
    {
        cout << "No ";
        return;
    }
    int c1 = 1, c2 = 1;
    for (int i = 0; i < 3; i++)
        if (a[i][1] == max1)
            c1 = max(c1, (a[i][0] == 'A' ? 10 : a[i][0] - '0'));

    for (int i = 0; i < 3; i++)
        if (b[i][1] == max2)
            c2 = max(c2, (b[i][0] == 'A' ? 10 : b[i][0] - '0'));
    if (c1 > c2)
    {
        cout << "Yes ";
        return;
    }
    cout << "No ";
}
int main()
{
    fastio();
    init();
    int t;
    cin >> t;
    val['R'] = 4;
    val['C'] = 3;
    val['P'] = 2;
    val['N'] = 1;
    while (t--)
        solve();
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
