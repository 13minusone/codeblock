#include<bits/stdc++.h>
using namespace std;
#define task "thi"
#define fu(i,a,b) for(int i=a; i<=b; i++)
#define fd(i,a,b) for(int i=a; i>=b; i--)
#define pb push_back
#define popb pop_back
#define ll long long
#define ull unsigned long long
#define rt return
#define ctn continue
#define fi first
#define se second
const int mod = int(1e9)+7;
typedef pair<int, int> ii;
void init()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int n, m, ans=0, d[int(5e5)+2];
vector<int> a[int(5e5)+2];
bool kt=1, b[int(5e5)+1];
void read()
{
    int x, y;
    cin >> n >> m;
    fu(i,1,n-1)
    {
        cin >> x >> y;
        a[x].pb(y);
        a[y].pb(x);
    }
    fu(i,1,m)
    {
        cin >> x;
        b[x]=1;
    }
}
void dfs(int u, int p)
{
    if (b[u]) d[u]=1;
    for(int i=0; i<a[u].size(); i++)
    {
        int v=a[u][i];
        if (v!=p)
        {
            if (b[u]==1 && b[v]==1) kt=0;
            dfs(v, u);
            d[u]+=d[v];
        }
    }
    if (d[u]>1)
    {
        if (b[u])
        {
            ans+=d[u]-1;
            d[u]=1;
        }
        else
        {
            ans++;
            d[u]=0;
        }
    }
}
void sol()
{
    dfs(1,1);
    if (!kt) cout << -1;
    else cout << ans;
}
int main()
{
    init();
    fastio();
    read();
    sol();
}
