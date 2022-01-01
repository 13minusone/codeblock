/*
🛸　　　 　🌎　°　　🌓　•　　.°•　　　🚀 ✯
　　　★　*　　　　　°　　　　🛰 　°·　　                           🪐
.　　　•　° ★　•  ☄
______________________________________________________
    You are watching a brute force code
        CODE IS WRITTEN BY 13MINUSONE
*/
#include<bits/stdc++.h>
using namespace std;
#define task "T1007GIFT"
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
#define all(x) x.begin(),x.end()
#define endl '\n'
#define fi first
#define se second
typedef long long ll ;
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }
const ll N = 3005;
const ll mod =1e9+7;
const ll base = 311;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void inti()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
void add(int &a,int b)
{
    a+=b;
    if(a>=mod)a-=mod;
}
int n, f[2][2*N][2];
vector<ii> a;
void nhap()
{
    cin >> n;
    ii x;
    for (int i = 0; i < n; i++)
    {
        cin >> x.fi;
        x.se = 0;
        a.push_back(x);
    }
    for(int i = 0; i < n; i++)
    {

        cin >> x.fi;
        x.se = 1;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    f[0][0][0] = 1;
    for (int i = 0; i < 2 * n; i++)
    {
        int s1 = i % 2;
        int s2 = (i + 1) % 2;
        memset(f[s2], 0, sizeof(f[s2]));
        if (a[i].se == 0)
        {
            for (int j = 0; j < n; j++)
            {
                add(f[s2][j + 1][0], f[s1][j][0]);
                add(f[s2][j + 1][1], f[s1][j][1]);
                add(f[s2][j][1], f[s1][j][0]);
                add(f[s2][j][1], f[s1][j][1]);
            }
        }
        else
        {
            for (int j = 0; j < n; j++)
            {
                if (j >= 1)
                {
                    add(f[s2][j - 1][0], (1LL * f[s1][j][0] * j) % mod);
                    add(f[s2][j - 1][1], (1LL * f[s1][j][1] * j) % mod);
                }
                add(f[s2][j][0], f[s1][j][0]);
            }
        }
        // cout << f[0][0][0] << " " << f[0][0][1] << '\n';
    }
    cout << ((f[0][0][0] % mod) + (f[0][0][1] % mod)) % mod;
}
int main()
{

    fastio();
    inti();
    nhap();
}




