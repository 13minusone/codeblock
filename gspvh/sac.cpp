#include<bits/stdc++.h>
using namespace std;
#define task "gcd-graph"
#define pb push_back
#define ll long long
#define fi first
#define se second
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
int n, k, q, b[int(1e6)+2], cha[int(1e6)+2], cnt=1;
vector<int> a[int(1e5)+2];
void read()
{
    cin >> n >> k >> q;
    for(int i=1; i<=n; i++)
    {
        cin >> b[i];
        for(int j=1; j<i; j++)
        {
            if (__gcd(b[i], b[j])>k)
            {
                a[i].pb(j);
                a[j].pb(i);
                //cout << i << " " << j << "\n";
            }
        }
    }
}
void dfs(int u)
{
    cha[u]=cnt;
    for(int v:a[u])
    {
        if (!cha[v]) dfs(v);
    }
}
void sol()
{
    int s, t;
    for(int i=1; i<=q; i++)
    {
        cin >> s >> t;
        if (!cha[s])
        {
            dfs(s);
            cnt++;
        }
        if (cha[s]==cha[t]) cout << "Y";
        else cout << "N";
    }
}
int main()
{
    init();
    fastio();
    read();
    sol();
}
