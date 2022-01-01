/*
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
const ll N = 1e5 + 5;
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
const int LOG=19;
int n,minn[N],par[N][21],hi[N],q,type,node,u,v;
vector<int>edge[N];
vector<int>queries;
void dfs(int u ,int pre)
{
    for(int i = 1 ; i <= LOG; i++)
        par[u][i] = par[ par[u][i-1] ][ i-1];
    for(int  v : edge[u])
    {
        if(v!=pre)
        {
            hi[v]=hi[u]+1;
            minn[v]=hi[v];
            par[v][0]=u;
            dfs(v,u);
        }
    }
}
ll get_lca(int u ,int v)
{
    if(hi[u] < hi[v])swap(u,v);
    for(int i = LOG; i >= 0 ; i--)
    {
        if(hi[par[u][i]] >=hi[v])u=par[u][i];
    }
    if(u == v)return u;
    for(int i = LOG;i>=0;i--)
    {
        if(par[u][i]!=par[v][i])
        {
            u=par[u][i];
            v=par[v][i];
        }
    }
    return par[u][0];
}
void reset()
{
    queue<int>q;
    for(int v : queries){
        q.push(v);
        minn[v]=0;
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v : edge[u])
        {
            if(minn[v] > minn[u]+1)
            {
                minn[v]=minn[u]+1;
                q.push(v);
            }
        }
    }
}
void nhap()
{
    cin >> n >> q;
    for(int i =1 ;i < n ;i++)
    {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    minn[1]=0;
    dfs(1,-1);
    while(q--)
    {
        cin >> type >> node;
        if(type == 1)
        {
            queries.push_back(node);
            if(SZ(queries) == 318)
            {
                reset();
                queries.clear();
            }
        }
        else
        {
            ll res=minn[node];
            for(int i : queries)
            {
                int u = get_lca(node,i);
                int s=hi[node]+hi[i]-2*hi[u];
                minimize(res,s);
            }
            cout << res << endl;
        }
    }
}
int main()
{

    fastio();
     inti();
    nhap();
}




