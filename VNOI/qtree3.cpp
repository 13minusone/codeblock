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
#define pb push_back
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
const ll N = 1e5+5;
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
vector<int>edge[N];
int head[N],n,m,u,v,cnt=0,num[N],child[N],par[N],chainid[N],nchain=1,val[N],hi[N];
void dfs(int u )
{
    child[u]=1;
    for(int i : edge[u])
    {
        if(i!=par[u]){
                hi[i]=hi[u]+1;
                par[i]=u;
            dfs(i);
        child[u]+=child[v];
        }
    }
}
void hld(int u)
{
    if(!head[nchain])head[nchain]=u;
    chainid[u]=nchain;
    num[u]=++cnt;
    val[cnt]=u;
    int Bigchild=-1;
    for(int i : edge[u])
    {
        if(i!=par[u])
        {
            if(Bigchild == -1 || child[i]>child[Bigchild])
            {
                Bigchild=i;
            }
        }
    }
    if(Bigchild != -1 ) hld(Bigchild);
    for(int i : edge[u])
    {
        if(i!=par[u] && i != Bigchild)
        {
            nchain++;
            hld(i);
        }
    }
}
set<ii>id[N];
ll query(int u)
{
    ll minn =-1;
    int cur= chainid[u];
    while(true)
    {
       if(!id[cur].empty())
       {
           auto it=id[cur].begin();
           if(it->fi<=hi[u])
           {
               minn=it->se;
           }

       }
       if(cur == 1) return minn;
       u=par[head[cur]];
       cur=chainid[u];
    }
}
void nhap()
{
    cin >> n >> m ;
    for(int i = 1 ; i < n ; i++)
    {
        cin >> u >> v;
        edge[u].pb(v); edge[v].pb(u);
    }
    par[1]=1;
    dfs(1);
    hld(1);
    int type,x;
    while(m--)
    {
        cin >> type >> x;
        if(type==0)
        {
            int Cur = chainid[x];
            auto it = id[Cur].lower_bound(ii(hi[x], x));
            if (it != id[Cur].end() && *it == make_pair(hi[x], x))
                id[Cur].erase(it);
            else
                id[Cur].insert(ii(hi[x], x));
        }
        else{
            ll s=query(x);
            cout << s<< endl;
        }

    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}



