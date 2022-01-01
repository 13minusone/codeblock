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
#define task "TTTS"
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
const ll N = 5e4 + 5;
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
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
}
int n,k,a[N];
ll in[N][505],out[N][505];
int x,y;
vector<int>edge[N];
void dfs(int u,int pre)
{
    in[u][0]=1;
    for(int v : edge[u])
    {
        if(v != pre)
        {
            dfs(v,u);
            for(int i = 0; i < k ; i++)
                in[u][i+1]+=in[v][i];
        }
    }
}
void DFS(int u,int pre)
{
    out[u][0]=1;
    vector<int>sum(505,0);
    for(int i = 0 ; i < k ; i++)for(int v : edge[u])if(v!=pre) sum[i+2]+=in[v][i];
     //cout << sum[2] << " "<< u << endl;
    for(int v : edge[u])
    {
        if(v != pre)
        {
            for(int i = 0 ; i <=k ;i++)
            {
                out[v][i+1]+=out[u][i];
                if(i>=2)out[v][i]+=(sum[i]-in[v][i-2]);
            }
            DFS(v,u);
        }
    }
}
void nhap()
{
    cin >> n >> k;
    for(int i = 1; i < n ; i++)
    {
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    dfs(1,-1);
    DFS(1,-1);
    ll ans=0;
    for(int i = 1 ; i <= n ; i++)
    {
        ans+= (in[i][k]+out[i][k]);
    }
    cout << ans/2;
}
int main()
{

    fastio();
    inti();
    nhap();
}




