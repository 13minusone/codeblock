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
#define task "tree-distance"
#define ll long long
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
#define fi first
#define se second
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
const ll N = 3e5+5;
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
vector<int>vec[N];
ll hi[N],up[N][25],LOG=12,dd[3005][3005];
void dfs(int u,int y)
{
    for(int p : vec[u])
    {
        if(p==y)continue;
        up[p][0]=u;
        hi[p]=hi[u]+1;
        for(int i = 1 ; i <= LOG; i++)
        {
        up[p][i]=up[ up[p][i-1]][i-1];
        }
        dfs(p,u);
    }
}
int n,k,x,y,z,sub;
int lca(int u,int v)
{
    if(hi[u]<hi[v])swap(u,v);
    for(int i = LOG; i >= 0; i--)
    {
        if(hi[up[u][i]]>=hi[v])
        {
            u=up[u][i];

        }
    }
    if(u==v)
    {
        return u;
    }
    for(int i = LOG; i >= 0 ; i--)
    {
        if(up[u][i]!=up[v][i])
        {
            u=up[u][i];
            v=up[v][i];
        }
    }
    return up[u][0];
}
void nhap()
{
    cin >> sub;
    cin >> n >> k ;
    for(int i = 1 ; i < n ; i++)
    {
        cin >> x >> y ;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }

    if(sub==1)
    {
        ll s=0;
        dfs(1,-1);
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1; j <= n ; j++)
            {
                if(dd[i][j]!=0)continue;
                ll x=lca(i,j);
                dd[i][j]=x;
                if(hi[i]+hi[j]-2*hi[x]==k)
                {
                    //cout << i << " " << j << " "<< x << endl;
                    s++;
                }
            }
        }
        cout << s;
    }
    else
    {
        cout << n-k;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}
