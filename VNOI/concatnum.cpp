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
#define task "c"
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
const ll N = 1e5 + 5;
const ll mod =1e9+9;
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
ll t, n, l, r;
ll a[120000], pow1[20];

long digit(long n) {
    long cnt = 0;
    while(n) {
        n /= 10;
        cnt++;
    }
    return cnt;
}
void nhap()
{
    cin >> t;
    pow1[0] = 1;
    for(long i = 1; i < 17; i++)  pow1[i] = pow1[i - 1] * 10;
    while(t--)
    {
        cin >> n >> l >> r;
        for(long i = 1; i <= n; i++)cin >> a[i];
        long long cnt = 0;
        sort(a + 1, a + n + 1);
        for(long i = 1; i <= n; i++) {
            long len = digit(a[i]);
            ll le = (l - a[i] + pow1[len] - 1) / pow1[len];
            ll ri = (r - a[i]) / pow1[len];
            if(le <= ri) cnt += (upper_bound(a + 1, a + n + 1, ri) - lower_bound(a + 1, a + n + 1, le));
        }
        cout << cnt <<"\n";
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}




