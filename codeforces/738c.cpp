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
int t, n, cha[int(1e4)+2];
vector<int> a[int(1e4)+2];
void truyvet(int s)
{
    vector<int> ans;
    while(s!=-1)
    {
        ans.pb(s);
        s=cha[s];
    }
    reverse(all(ans));
    for(int v: ans) cout << v << " ";
    cout << "\n";
}
void dfs(int u, int cnt)
{
    if (cnt==n+1)
    {
        truyvet(u);
        throw 1;
    }
    for(int v:a[u])
    {
        if (cha[v]==0)
        {
            cha[v]=u;
            dfs(v, cnt+1);
            cha[v]=0;
        }
    }
}
void sol()
{
    for(int i=1; i<=n+1; i++)
    {
        memset(cha, 0, sizeof cha);
        cha[i]=-1;
        try{
            dfs(i,1);
        } catch (...)
        {
            return;
        }
    }
    cout << -1 << "\n";
}
int main()
{
    fastio();
    //init();
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=1; i<n; i++)
        {
            a[i].clear();
            a[i].pb(i+1);
        }
        for(int i=1; i<=n; i++)
        {
            int x;
            cin >> x;
            if (x==0) a[i].pb(n+1);
            else a[n+1].pb(i);
        }
        sol();
    }
}
