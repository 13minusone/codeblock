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
#define task "c9"
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
const ll N = 2e5 + 5;
const ll mod =1e9+9;
const ll base = 311;
const int block = 488;
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
int n,child[N],x,y;
ll ans=0,in[N],out[N];
vector<int>edge[N];
void dfs(int u,int pre)
{
    child[u]=1;
    for(int v : edge[u])
    {
        if(v!=pre)
        {
            dfs(v,u);
            in[u]+=in[v];
            child[u]+=child[v];
        }
    }
    in[u]+=child[u];
}
void DFS(int u,int pre)
{
    ans=max(ans,in[u]);
    for(int v : edge[u])
    {
        if(v!=pre)
        {
            in[u]-=(in[v]+child[v]);
            in[v]+=(in[u]+n-child[v]);
            DFS(v,u);
            in[v]-=(in[u]+n-child[v]);
            in[u]+=(in[v]+child[v]);
        }
    }
}
void nhap()
{
    cin >> n ;
    for(int i = 1; i < n ; i++)
    {
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    dfs(1,-1);
    DFS(1,-1);

    cout << ans;

}
int main()
{

    fastio();
     inti();
    nhap();
}




