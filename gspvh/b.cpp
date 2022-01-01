#include<bits/stdc++.h>
using namespace std;
#define task "quanho"
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
const ll MOD=1e12 + 7;
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
int n,m,cha[int(1e5)+2];
ll cake[int(1e5)+2];
vector<int> a[int(1e5)+5];
vector<ll>  w[int(1e5)+5];
ll d[int(1e5)+5];
struct ii
{
    int u, d;
};
struct cmp
{
    bool operator()(ii a, ii b)
    {
        return a.d>b.d;
    }
};
priority_queue<ii, vector<ii>,cmp> h;
void push(int u)
{
    ii y;
    y.u=u;
    y.d=d[u];
    h.push(y);
}
void read()
{
    int x, y;
    ll z;
    cin >> n;
    fu(i,1,n) cin >> cake[i];
    cin >> m;
    fu(i,1,m)
    {
        cin >> x >> y >> z;
        a[x].pb(y);
        a[y].pb(x);
        w[x].pb(z);
        w[y].pb(z);
    }
    fu(i,1,n) d[i]=LLONG_MAX;
    d[1]=0;
    cha[1]=-1;
}
void dij(int u)
{
    push(u);
    while (!h.empty())
    {
        ii x = h.top();
        h.pop();
        int u=x.u;
        for (int i=0; i<a[u].size(); i++)
        {
            int v = a[u][i];
            if (d[v]>d[u]+w[u][i])
            {
                d[v]=d[u]+w[u][i];
                push(v);
                cha[v]=u;
            }
        }
    }
}
void truyvet()
{
    ll res=0, s=0;
    cout << d[n] << " ";
    while (n!=-1)
    {
        res+=cake[n];
        //res.push_back(n);
        n=cha[n];
    }
    cout << res;
    //for (int i=res.size()-1; i>=0; i--) cout << res[i] << " ";
}
int main()
{
    init();
    fastio();
    read();
    dij(1);
    if (d[n]==LLONG_MAX) cout << "impossible";
    else truyvet();
}
