#include <bits/stdc++.h>
using namespace std;

vector<int> a[1000];
int s,f,cha[1000]={0},k=0,d=0,g[1000]={0};
void dfs(int u)
{

 g[u]=1;
    for(int i=0;i<a[u].size();i++)
    {
        int v = a[u][i];
	   if(g[v]==0)
        {

           g[v]=u;
            dfs(v);
        }
    }
}


long long n,m;
void nhap()
{
    int u,v;

    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        a[u].push_back(v);
a[v].push_back(u);
    }

}
void check()
{
      nhap();


if(m==n-1)
{

s=1;
      for(int i=1;i<=n;i++)
      {
          dfs(i);
          if(g[i]!=0)
          {
              cout<<"0"<<endl;
              break;
          }
      }
}
else
    {
        cout<<"0"<<endl;
    }
}
int main()
{

    freopen("kttree.inp","r",stdin);
    freopen("kttree.out","w",stdout);
long long t;
cin>>t;
for(int i=1;i<=t;i++)
{

    check();

g[1000]={0};
vector<int> a[1000];
k=0;
d=0;
}

}
