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
const ll N = 2e5 + 5;
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
struct edge
{
    int u,v,w,id;
    edge(int _u=0 , int _v=0,int _w = 0 ,int _id = 0)
    {
        u=_u;
        v=_v;
        w=_w;
        id=_id;
    }
};
int n,m,cha[N], x,y,w,dd[N],up[N][25],LOG=19,a[N],hi[N];
ll maxx[N][20];
vector<edge>vec;
vector<ii>canh[N];
int root(int u)
{
    if(u==cha[u])return u;
    else return cha[u]=root(cha[u]);
}
bool in_dsu(int u,int v)
{
    u=root(u);
    v=root(v);
    if(u == v)return false;
    if(u>v)swap(u,v);
    cha[v]=u;
    return true;
}
bool check(edge u,edge v)
{
    return u.w < v.w;
}
void dfs(int u,int v)
{
    for(ii i : canh[u])
    {
        if(i.fi == v)continue;
        hi[i.fi]=hi[u]+1;
        up[i.fi][0]=u;
        maxx[i.fi][0]=i.se;
        dfs(i.fi,u);
    }
}
vector<edge>goc;
ll getmax(int u,int v)
{
    ll maxxi=0;
    //maxxi=max(maxx[u][0],maxx[v][0]);
    if(hi[u] < hi[v])swap(u,v);

    for(int j = LOG;  j >=0 ; j--)
    {
        if(hi[up[u][j]] >= hi[v])
        {
            maxxi=max(maxxi,maxx[u][j]);
            u=up[u][j];
        }
    }
    if(u==v)return maxxi;
    for(int j = LOG;  j >=0; j--)
    {
        if(up[u][j] != up[v][j])
        {
            maxxi=max(maxxi,maxx[u][j]);
            maxxi=max(maxxi,maxx[v][j]);
            u=up[u][j];
            v=up[v][j];
        }
    }
    maxxi=max(maxxi,max(maxx[u][0],maxx[v][0]));
    return maxxi;
}
void nhap()
{
    cin >> n >> m;
    for(int i = 1 ; i <= m ; i++)
    {
        cin >> x >> y >> w;
        goc.push_back(edge(x,y,w,i));
        vec.push_back(edge(x,y,w,i));
    }
    for(int i = 1; i <= n ; i++)cha[i]=i;
    ll s=0;
    sort(all(vec),check);
    for(int j= 0 ; j < m ; j++)
    {
        edge i =vec[j];
        if(in_dsu(i.u,i.v)){
                //cout << i.u << " " << i.v << " "<< i.w << endl;
            s+=i.w;
            dd[i.id]=1;
            canh[i.u].push_back(ii(i.v,i.w));
            canh[i.v].push_back(ii(i.u,i.w));
        }
    }
    dfs(1,1);
     for(int j = 1 ; j<=LOG; j++)
    {
        for(int i = 1 ; i <= n ; i++)
        {
            up[i][j]=up[ up[i][j-1] ][j-1];
            maxx[i][j]=max(maxx[up[i][j-1]][j-1],maxx[i][j-1]);

        }
    }
    for(int i = 0 ; i < m ; i++)
    {
        if(dd[i+1]==1)cout << s << endl;
        else
        {
            edge j = goc[i];
            ll o=getmax(j.u,j.v);
            cout << ll(s-o+j.w) << endl;
        }
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}




