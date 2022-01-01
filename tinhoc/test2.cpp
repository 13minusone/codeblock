#include<bits/stdc++.h>
using namespace std;
#define task "TAITRONG"
#define fu(i,a,b) for(int i=a; i<=b; i++)
#define fd(i,a,b) for(int i=a; i>=b; i--)
#define pb push_back
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
int n,m,s,t;
int w[1003][1003], minn[1005], cha[1005];
queue<int> q;
vector<int> a[1005];
void read()
{
    int x,y,z;
    cin >> n >> m >> s >> t;
    fu(i,1,m)
    {
        cin >> x >> y >> z;
        a[x].pb(y);
        a[y].pb(x);
        w[x][y]=z;
        w[y][x]=z;
    }
    fu(i,1,n) minn[i]=INT_MAX;
}
void bfs(int s)
{
    int u,v;
    q.push(s);
    cha[s]=-1;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        fu(i,0,a[u].size()-1)
        {
            v=a[u][i];
            if (cha[v]==0)
            {
                cha[v]=u;
                q.push(v);
                minn[v]=min(w[u][v],minn[u]);
                //cout << v << " " << u << " " << minn[v] << "\n";
            }
            else
            {
                if (minn[v]<minn[u])
                {
                    minn[v]=max(minn[v],min(minn[u],w[u][v]));
                    if (v!=t) q.push(v);
                    //cout << v << " " << u << " " << minn[v] << "\n";
                }
            }
        }
    }
}
int main()
{
    init();
    fastio();
    read();
    bfs(s);
    cout << minn[t];
    return 0;
}
