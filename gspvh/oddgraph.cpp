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
int n,m;
int cha[N],deg[N];
bool check[N*10];
ll root(int u)
{
    return cha[u] < 0 ? u : (cha[u] = root(cha[u]));
}
bool join(int u,int v)
{
    if( (u = root(u)) == (v = root(v)) )return false;
    if(cha[v] < cha[u])swap(u,v);
    cha[u]+=cha[v];
    cha[v]=u;
    return true;
}
vector<ii>canh[N];
void dfs(int u,int pre,int id)
{
    for(ii v : canh[u])
    {
        if(v.fi != pre)
        {
            dfs(v.fi,u,v.se);
        }
    }
    if(id==-1)return;
    if(deg[u]&1)
    {
        check[id]=false;
    }
    else
    {
        deg[u]++;
        deg[pre]++;
        check[id]=true;
    }

}
int u,v;
void nhap()
{
    cin >> n >> m;
    for(int i = 1 ; i <=n  ; i++)cha[i]=-1;
    for(int i = 1 ; i <= m ; i++)
    {
        cin >> u >> v;
        check[i]=join(u,v);
        if(check[i]){
            canh[u].push_back(ii(v,i));
            canh[v].push_back(ii(u,i));
        }
    }
    for(int i = 1; i <= n ; i++)
    {
        if(i == root(i))
        {
            if( (-cha[i]) & 1){
                cout << "-1" ;
                return;
            }
            else
            {
                dfs(i,-1,-1);
            }
        }
    }
    for(int i = 1; i <= m ;i++)
        if(check[i] == true)cout << 1 ;
        else cout << 0;

}
int main()
{

    fastio();
    // inti();
    nhap();
}




