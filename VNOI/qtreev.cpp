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
ll n,m;
ll a[N],trace[N];
double p[N];
int u,v;
vector<int>edge[N];
ll mul(ll a,ll b)
{
    if(b==0)return 0;
    ll t = mul(a,b>>1);
    if(b&1) return (t + t + a)%m;
    else return (t+t)%m;
}
void dfs(int u,int pre)
{
    double maxx=0;
    if(SZ(edge[u]) == 1){
        p[u]=log10(a[u]);
        return;
    }
    for(int v : edge[u])
    {
        if(v == pre) continue;
        dfs(v,u);
        //cout << v << endl;
       if(p[v] > maxx)
       {
           trace[u]=v;
            maxx=p[v];
            //cout << v << endl;
       }
    }
    p[u]=maxx+log10(a[u]);
}
void nhap()
{
    cin >> n >> m;
    for(int i = 1;  i<= n ; i++)cin >> a[i];
    for(int i = 1; i < n; i++)
    {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1,-1);
    vector<int>vec;
    int k=1;
   while(k!=0)
   {
       vec.push_back(k);
       k=trace[k];
       //cout << k << endl;
   }
   ll res = 1;
   for(int i = SZ(vec)-1 ; i >= 0 ; i--)
   {
        //cout << a[vec[i]] << endl;
        res= mul(res ,a[vec[i]]);
   }
   cout << res;
}
int main()
{

    fastio();
    // inti();
    nhap();
}




