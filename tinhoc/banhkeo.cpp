#include<bits/stdc++.h>
using namespace std;
#define task "banhkeo"
#define fu(i,a,b,c) for(int i=a;i<=b;i+=c)
#define fd(i,a,b,c) for(int i=a;i>=b;i-=c)
#define ll long long
#define xu(a) cout<<a<<" ";
#define xuo(a) cout<<a<<endl;
void inti()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

}
int n,m,x,y,z,cha[100001],k,maxx=INT_MAX,s=0;
vector<int>a[100001];

void dfs(int f)
{
    for (int i=0; i<a[f].size(); i++)
    {
        int v=a[f][i];
        if(!cha[v])
        {
            cha[v]=1;
            dfs(v);
        }
    }
}
void solve()
{
    for (int i=1; i<=n; i++)
    {
        if(!cha[i])
        {
            dfs(i);
            s++;
        }
    }
    xuo(s);
}
void nhap()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1; i <= n; i++) cha[i] = 0;
    fu(i,1,k,1)
    {
        int g;
        scanf( " %d ", &g);
        maxx=min(maxx,g);
    }
    for (int i=1; i<=m; i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        if(z>=maxx)
        {
            a[x].push_back(y);
            a[y].push_back(x);
        }
    }
    solve();
}
int main()
{
    inti();
    nhap();
}
