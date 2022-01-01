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
const ll N = 1e6+6;
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
    //freopen(task".out","w",stdout);
}
ll r;
ll l[N];
ll a[N],pref[N];
void nhap()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n ; i++)
    {
        cin >> a[i];
        l[i] = max(l[i - 1], a[i]);
    }
    ll cnt=0;
    ll maxx=0;
    for(int i = n; i >=1; i--)
    {
       ll k = max(a[i], min(l[i - 1], (ll)r));

        cnt += k - a[i];
        a[i] = k;

        r = max(r, a[i]);
    }
    maxx = cnt;

    int pre = 1;
    for(int i = 2;i <= n; i++)
        if (a[i] != a[i - 1] && a[i] > a[pre]) {
            maximize(maxx, cnt + i - pre - 1);
            pre = i;
        }

    pre = n;
    for(int i= n -1 ; i >=1 ; i--)
        if (a[i] != a[i + 1] && a[i] > a[pre]) {
            maximize(maxx, cnt+ pre - i - 1);
            pre = i;
        }

    cout << maxx;
}
int main()
{

    fastio();
     //inti();
    nhap();
}

