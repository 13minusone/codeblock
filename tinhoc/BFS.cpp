#include<bits/stdc++.h>
using namespace std;
vector< vector < int > > a;
queue<int>bdd;
int g[100000],n,u,v,m;
int ds[10000];
void truyvet(long long u,long long v)
{
    if(g[v]==0){cout<<"-1"<<endl;}
    else
    {
        int d=0;
        while (v != u){
            ds[++d] = v;
            v = g[v];
        }
        ds[++d] = u;
        cout<<d<< '\n';
        for (int i = d; i > 0; i--) cout << ds[i] << ' ';

    }
}
void bfs(int s)
{
    bdd.push(s);

    while(!bdd.empty())
    {
        int u=bdd.front();
        bdd.pop();
        if (u == v) break;
        for(int i=0;i<a[u].size();i++)
        {
            int f=a[u][i];
            if(g[f]==0)
            {
                bdd.push(f);
                g[f]=u;
            }
        }
    }
    truyvet(u, v);
}

int main()
{
    freopen("BFS.inp", "r", stdin);
    freopen("BFS.out", "w", stdout);
    cin>>n>>m>>u>>v;
    a.resize(n + 1);
    int x,y;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);

    }
    bfs(u);

}
