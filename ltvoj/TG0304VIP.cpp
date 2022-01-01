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
#define task "TG0304VIP"
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
#define all(x) x.begin(),x.end()
#define endl '\n'
typedef long long ll ;
typedef pair<ll,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
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
int n,m,k,u,v,w,q[305],p[305],dd[305];
ll dist[305][305];
int my[305];
bool vy[305];
vector<ii>ans[305];
void pre()
{
    for(int i = 1; i <= n ; i++)dist[i][i]=0;
    for(int k = 1; k <= n ; k++)
    for(int  i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            minimize(dist[i][j],dist[i][k]+dist[k][j]);
        }
    }
}
 ll res=1e9+5;
bool dfs(int s, int lim) {
    for(int u = 0; u < k; ++u) if(!vy[u] && dist[p[s]][q[u]] <= lim) {
        vy[u] = true;
        if(my[u] == -1 || dfs(my[u], lim)) return my[u] = s, true;
    }
    return false;
}
void nhap()
{
    cin >> n >> m >> k;
    memset(dist,mod,sizeof dist);
    for(int i = 1 ; i <= m ; i++)
    {
        cin >> u >> v >> w;
        dist[u][v]=w;
        dist[v][u]=w;
    }
    pre();
    //cout << dist[1][3] << endl;
    for(int i = 0 ; i < k ; i++)cin >> p[i];
    for(int i = 0 ; i < k ; i++)cin >> q[i];
    int l=0,h=1e9;
   while(l < h) {
        memset(my, -1,sizeof my); int mid = (l + h) / 2; bool ok = true;
        for(int i = 0; memset(vy, 0,sizeof vy), i < k && ok; ++i) ok &= dfs(i, mid);
        if(ok) h = mid; else l = mid + 1;
    }


    cout << l;

}
int main()
{

    fastio();
    inti();
    nhap();
}




