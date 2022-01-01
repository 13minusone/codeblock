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
#define ll long long
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll maxsize = 100000;
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
ll poww(ll x,ll m)
{
    if(m==1)return x;
    if(m==0)return 1;
    if(m&1)
    {
        return ((((poww(x,m/2)%mod)*poww(x,m/2)%mod)%mod)*x%mod)%mod;
    }
    else
    {
        return ((poww(x,m/2)%mod)*(poww(x,m/2)%mod))%mod;
    }
}
void nhap()
{
    ll n , m,s=0;
    cin >> n >> m;
    s=n+m;
    n=min(n,m);
    m=s-n;
    ll g=1,res = 1 ;
    for(int i = 1 ; i < n ; i++)
    {
        g=((g%mod)*(i%mod))%mod;
        res=((res%mod)*(((g%mod)*(g%mod))%mod)%mod);
    }
    g=((g%mod)*(n%mod))%mod;
    res=((res%mod)*(poww(g,m-n+1)%mod)%mod);
    cout << res << endl;
}
int main()
{

    fastio();
    // inti();
    nhap();
}



