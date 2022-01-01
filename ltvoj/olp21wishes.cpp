#include<bits/stdc++.h>
using namespace std;
#define task "olp21wishes"
#define fu(i,a,b) for(int i=a; i<=b; i++)
#define fd(i,a,b) for(int i=a; i>=b; i--)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define rt return
#define ctn continue
const int mod = int(1e9)+7;
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
vector<int> a[int(1e5)+2];
int n,m;
int cha[int(1e5)+2], visit[int(1e5)+2];
void dfs(int u)
{
    int v;
    for(int i=0; i<a[u].size(); i++)
    {
        v=a[u][i];
        if (cha[v]==0)
        {
            cha[v]=1;
            dfs(v);
        }
    }
}
void sol()
{
    vector<int> k;
    int x,y,res=0;
    cin >> n >> m;
    fu(i,1,m)
    {
        cin >> x >> y;
        a[x].pb(y);
    }
    fu(i,1,n)
    {
        if (!cha[i])
        {
            k.pb(i);
            cha[i]=1;
            dfs(i);
        }
    }
    fu(i,1,n) cha[i]=0;
    fd(i,k.size()-1,0)
    {
        if (!cha[k[i]])
        {
            res++;
            cha[k[i]]=1;
            dfs(k[i]);
        }
    }
    cout << res;
}
int main()
{
    init();
    fastio();
    sol();
}
