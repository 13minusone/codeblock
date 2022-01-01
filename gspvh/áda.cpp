///KhoaHo///
#include <bits/stdc++.h>
using namespace std;
///define-zone
#define task "olympics"
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
inline bool getbit(val pos, val mask) { return ((mask >> pos) & 1); }
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
string a = "";
int doiso(string x)
{
    int ret = 0;
    for (int i = 0; i < x.size(); i++)
        ret = ret * 10 + int(x[i] - '0');
    return ret;
}
char x;
int main()
{
    fastio();
   //init();
    cin >> x;
    while (x != '.')
    {
        a += x;
        cin >> x;
    }
    int yr = doiso(a);
    a = "";
    cin >> x;
    while (x != '.')
    {
        a += x;
        cin >> x;
    }
    int mon = doiso(a);
    cin >> a;
    int d = doiso(a);
    int res = 0;
    if (yr != 2021)
    {
        int k = d;
        int p = mon;
        int cnt = 0;
        for (int y = yr; y <= 2020; y++)
        {
            for (int m = p; m <= 12; m++)
            {
                if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
                {
                    for (int i = k; i <= 31; i++)
                        ++cnt;
                }
                else if (m == 4 || m == 6 || m == 11 || m == 9)
                {
                    for (int i = k; i <= 30; i++)
                        ++cnt;
                }
                else if (m == 2)
                {
                    if ((y % 4 == 0 && y % 100 != 0) || (y % 100 == 0 && y % 400 == 0))
                    {
                        for (int i = k; i <= 29; i++)
                            ++cnt;
                    }
                    else
                        for (int i = k; i <= 28; i++)
                            ++cnt;
                }
                k = 1;
            }
            p = 1;
        }
        for (int i = 1; i <= 7; i++)
        {
            if (i == 2)
            {
                for (int j = 1; j <= 28; j++)
                    ++res;
            }
            else if (i == 1 || i == 3 || i == 5)
            {
                for (int j = 1; j <= 31; j++)
                    ++res;
            }
            else if (i == 7)
                for (int j = 1; j <= 22; j++)
                    ++res;
            else
                for (int j = 1; j <= 30; j++)
                    ++res;
        }
        cout << cnt + res;
    }
    else
    {
        int res = 0;
        if (mon == 7)
        {
            for (int i = d; i <= 22; i++)
                ++res;
            cout << res;
        }
        else if (mon == 6)
        {
            for (int i = d; i <= 30; i++)
                ++res;
            cout << res + 22;
        }
        else
        {
            int k;
            if (mon == 1 || mon == 3 || mon == 5)
                k = 31;
            else if (mon == 2)
                k = 28;
            else
                k = 30;
            for (int i = d; i <= k; i++)
                ++res;
            for (int i = mon + 1; i <= 6; i++)
            {
                if (i == 1 || i == 3 || i == 5)
                    k = 31;
                else if (i == 2)
                    k = 28;
                else
                    k = 30;
                for (int j = 1; j <= k; j++)
                    ++res;
            }
            cout << res + 22;
        }
    }
    return 0;
}
