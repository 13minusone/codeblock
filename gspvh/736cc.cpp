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
int dem[int(2e5)+2], n, m, q;
int main()
{
    fastio();
    int u, v;
    cin >> n >> m;
    int res=n;
    for(int i=1; i<=m; i++)
    {
        cin >> u >> v;
        if (!dem[min(u,v)]) res--;
        dem[min(u,v)]++;
    }
    int p;
    cin >> q;
    for(int i=1; i<=q; i++)
    {
        cin >> p;
        if (p<=2)
        {
            cin >> u >> v;
            if (p==1)
            {
                if (!dem[min(u,v)]) res--;
                dem[min(u,v)]++;
            }
            if (p==2)
            {
                if (dem[min(u,v)]==1) res++;
                dem[min(u,v)]--;
            }
            continue;
        }
        cout << res << "\n";
    }
}
