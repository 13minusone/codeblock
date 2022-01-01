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
typedef long long ll ;
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B)
{
    A=min(A,B);
}
template<class T> void maximize(T &A, T B)
{
    A=max(A,B);
}
const ll N = 1e5;
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
int n,m,u,v,Log=17,c;
int up[N+5][20],sta[N+5],en[N+5],cnt=0,hi[N+5],type[N+5],ans[N+5];
vector<int>color[N+5],edge[N+5];
struct que
{
    int x,y,z;
    que(int u,int v,int c)
    {
        x=u;
        y=v;
        z=c;
    }
};
vector<que> queries[N+5];
void dfs(int u,int v)
{
    sta[u]=++cnt;

    for(int i : edge[u])
    {
        if(i==v)continue;
        up[i][0]=u;
        hi[i]=hi[u]+1;
        for(int j = 1 ; j <= Log; j++)
        {
            up[i][j]=up[up[i][j-1]][j-1];
        }
        dfs(i,u);
    }
    en[u]=cnt;
}
ll st[N*4+5];
ll lca(int u,int v)
{
    if(hi[u]<hi[v])swap(u,v);
    //cout << u <<endl;
    //cout << up[u][1] << endl;
    for(int i = Log; i>=0; i--)
    {

        if(hi[up[u][i]]>=hi[v])
        {
            //cout << u <<endl;
            u=up[u][i];
        }
    }
    //cout << u <<endl;
    if(u==v)return u;
    for(int i = Log ; i >= 0 ; i--)
    {
        if(up[u][i]!=up[v][i])
        {
            v=up[v][i];
            u=up[u][i];

        }
    }
    return up[u][0];
}
void update(int id,int l,int r,int x,int val)
{
    if(r<x||l>x)return;
    if(l==x&&l==r)
    {
        st[id]+=val;
        return;
    }
    int m=(l+r)/2;
    update(id*2,l,m,x,val);
    update(id*2+1,m+1,r,x,val);
    st[id]=st[id*2]+st[id*2+1];
}
ll get(int id,int l,int r,int u,int v)
{
    if(l>v||r<u||l>r)return 0;
    if(u<=l && r <= v)return st[id];
    int m=(l+r)/2;
    return get(id*2,l,m,u,v)+get(id*2+1,m+1,r,u,v);
}
void nhap()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> u;
        type[i]=u;
        color[u].push_back(i);
    }
    for(int i = 1 ; i <n ; i++)
    {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    //up[1][0]=0;
    hi[1]=0;
    dfs(1,-1);
    //cout << hi[4] << endl;
    for(int i = 1 ; i <= m ; i++)
    {
        cin >> u >> v >> c;
        queries[c].push_back(que(u,v,i));
    }
    //cout << lca(5,4) <<endl;
    //return;
    cout << endl;
    memset(st,0,sizeof st);
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j : color[i])
        {
            update(1,1,n,sta[j],1);
            update(1,1,n,en[j]+1,-1);
        }
        for(que j : queries[i])
        {
            int x=j.x;
            int y=j.y;
            int anc=lca(x,y);
           // if(anc==0)anc++;
           // cout << x << " "<< y << " "<< anc << endl;
            if(type[anc]==i)
            {
                ans[j.z]=1;
                continue;
            }
            int sum=get(1,1,n,1,sta[x])+get(1,1,n,1,sta[y])-2*get(1,1,n,1,sta[anc]);
            if(sum>0)ans[j.z]=1;
        }
        for(int j : color[i])
        {
            update(1,1,n,sta[j],-1);
            update(1,1,n,en[j]+1,1);
        }
    }
    for(int i = 1 ; i <= m ; i++)
    {
        cout << ans[i];
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}



