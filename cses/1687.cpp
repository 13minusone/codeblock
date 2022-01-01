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
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll N = 2e5;
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
int n ,q,a,x;
vector<int>edge[N+5];
int hi[N+5],up[N+5][20],Log=18;
void dfs(int u ,int v)
{
    for(int  i : edge[u])
    {
        if(i==v)continue;
        hi[i]=hi[u]+1;
        up[i][0]=u;
        for(int j = 1 ; j <= Log ; j++)
        {
            up[i][j]=up[up[i][j-1]][j-1];
        }
        dfs(i,u);
    }
}
int lca(int a,int x)
{
    if(hi[a]<hi[x])swap(a,x);
    for(int j = Log ;j>=0;j--)
    {
        if(hi[up[a][j]]>=hi[x])
        {
            a=up[a][j];
        }
    }
    if(a==x)return a;
    for(int j = Log ; j>= 0 ; j--)
    {
        if(up[a][j]!=up[x][j])
        {
            a=up[a][j];
            x=up[x][j];
        }
    }
    return up[a][0];
}
void nhap()
{
    cin >> n >> q;
    for(int i = 2; i <= n ; i++)
    {
        cin >> a;
        edge[i].push_back(a);
        edge[a].push_back(i);
    }
    dfs(1,-1);
    while(q--)
    {
        cin >> a >> x;
        if(a==1||x==1)cout << 1 << endl;
        //cout << hi[a] << endl;
        else cout << lca(a,x) << endl;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}




