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
#define task "tongghep"
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
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
}
ll a[N],pow10[N],s=0,ans=0,n,s10=0;
void add(ll &a,ll b)
{
    a+=b;
    if(a>=mod)a-=mod;
}
ll minu(ll a,ll b)
{
    a-=b;
    if(a<0)a+=mod;
    return a;
}
void nhap()
{
    cin >> n;
    for(int i = 1; i <= n ;i++)
    {
        cin >> a[i];
        add(s,a[i]);
    }
    pow10[0]=1;
    for(int i = 1; i <= 10 ; i++)
    {
        pow10[i]=(pow10[i-1]*10)%mod;
    }

    for(int i = 1; i <= n ; i++)
    {
        ll y=log10(a[i]);
        add(s10,pow10[y+1]);
    }
    for(int i = 1; i <= n ; i++)
    {
        ll y=log10(a[i]);
        ll x=( a[i] * minu(s10,pow10[y+1]) )%mod;
        add(x,minu(s,a[i]));
        add(ans,x);
    }
    cout << ans;

}
int main()
{

    fastio();
     inti();
    nhap();
}




