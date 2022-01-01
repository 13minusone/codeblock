#include<bits/stdc++.h>
using namespace std;
vector<int>a[100000];
long long n,m;
long long b[10000][10000];
long long cha[int(1e5)+1];
long long g[1001][1001],minn[1001][1001],f;
void dfs(long long s)
{
    for(int i=0;i<a[s].size();i++)
    {
        long long v=a[s][i];
if(cha[v]!=s)
            {cha[v]=s;

            g[0][v]=g[0][f]+b[v][f];
            minn[f][v]=max(minn[0][v],g[f][v]);

            dfs(v);}

    }
}
int main()
{
    //freopen("bai1.inp","r",stdin);
    //freopen("bai1.out","w",stdout);
    cin>>n>>m;
    long long x,y,z,l,k;
cha[1]=0;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y>>z;
        a[x].push_back(y);
        a[y].push_back(x);

        b[x][y]=z;
        b[y][x]=z;

    }
    cin>>f>>k;
    for(int i=1;i<=1000;i++)
    {
        for(int j=1;j<=1000;j++)
        {
            minn[i][j]=-100000;
        }
    }

    g[0][f]=0;
    dfs(f);
    cout<<minn[f][k];
}
