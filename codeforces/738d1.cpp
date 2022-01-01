#include<bits/stdc++.h>
using namespace std;
#define task "thi"
#define pb push_back
#define ll long long
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define sz(x) s.size()
#define getbit(x,i) (((x)>>(i))&1)
#define turnoff(x,i) ((x)&(~(1<<i)))
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
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool edge[1002][1002];
int n, m1, m2;
struct DSU
{
    int n;
    vector<int> par;
    DSU(int _n=0)
    {
        n=_n;
        par.assign(n+5, -1);
    }
    int root(int v)
    {
        return par[v]<0 ? v : (par[v]=root(par[v]));
    }
    bool join(int x, int y)
    {
        x=root(x);
        y=root(y);
        if (x==y) return false;
        if (par[y]<par[x]) swap(x,y);
        par[x]=x;
        par[y]=x;
        return true;
    }
};
void sol()
{
    cin >> n >> m1 >> m2;
    DSU dsu1(n);
    DSU dsu2(n);
    int x, y;
    for(int i=1; i<=m1; i++)
    {
        cin >> x >> y;
        dsu1.join(x,y);
    }
    for(int i=1; i<=m2; i++)
    {
        cin >> x >> y;
        dsu2.join(x,y);
    }
    vector<ii> ans;
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            //cout << i << " " << j << "\n";
            //cout << dsu1.root(i) << " " << dsu1.root(j) << " ";
            //cout << dsu2.root(i) << " " << dsu2.root(j) << "\n";
            if (dsu1.join(i,j) && dsu2.join(i,j))
            {
                ans.pb({i,j});
            }

        }
    }
    cout << ans.size() << "\n";
    for(ii res:ans) cout << res.fi << " " << res.se << "\n";
}
int main()
{
    fastio();
    //init();
    sol();
}
