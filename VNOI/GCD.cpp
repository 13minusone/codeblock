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
#define mu2(x) ((1LL)<<(x))
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
int n,k;
ll gcd[N][20],a[N];
void nhap()
{
    cin >> n >> k;
    for(int i = 1; i <= n ; i++)
    {
        cin >> a[i];
        gcd[i][0]=a[i];
    }
    for(int i = 1; i <= 20 ; i++)
    {
        for(int j = 1 ; j <= n-mu2(i)+1 ; j++)
        {
            gcd[j][i]=__gcd(gcd[j][i-1],gcd[j+mu2(i-1)][i-1]);
        }
    }
    int m = log2(k);
    ll maxx=1;
    for(int i = 1; i <= n-k+1;i++)
    {
        ll u=__gcd(gcd[i][m],gcd[i+k-mu2(m)][m]);
        maximize(maxx,u);
    }
    cout << maxx << endl;

}
int main()
{

    fastio();
    // inti();
    nhap();
}




