#include<bits/stdc++.h>
using namespace std;
#define task "DDNN2"

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int n,m,s,f;
vector<int> a[int(1e5)+5], w[int(1e5)+5];
int d[int(1e5)+5], cha[int(1e5)+5];
struct ii
{
    int u, d;
};
struct cmp
{
    bool operator() (ii a, ii b)
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
    int x,y,z;
    cin >> n >> m ;
    for (int i=1; i<=m; i++)
    {
        cin >> x >> y;
        a[x].push_back(y);
        w[x].push_back(1);
    }
    for (int i=1; i<=n; i++) d[i]=LONG_MAX;
    d[1]=0;
    cha[1]=-1;
}
void dijkstra()
{
    push(1);
    while (!h.empty())
    {
        ii x = h.top();
        h.pop();
        int u=x.u;
        //if (x.d!=d[u]) continue;
        for (int i=0; i<a[u].size(); i++)
        {
            int v=a[u][i];
            if (d[v]>d[u]+w[u][i])
            {
                push(v);
                cha[v]=u;
                d[v]=d[u]+w[u][i];
            }
        }
    }
}

int main()
{


    read();
    dijkstra();
    if (d[n]==LONG_MAX) cout << -1;
    else cout<<d[n];
}

