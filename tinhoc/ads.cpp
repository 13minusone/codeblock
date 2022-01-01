#include<bits/stdc++.h>
using namespace std;

int cha[100001],xoa[100001];
int n,m,s;
vector<int> a[100005];

int res=0;

void dfs(int u)
{
    //cout<<u<<endl;
    for(int i=0; i<a[u].size(); i++)
    {
        int v=a[u][i];

        if(cha[v]>0&&cha[u]!=v&&xoa[v]==0)
        {
            res++;
            //cout<<u<<" "<<cha[u]<<" "<<v<<endl;
        }
        if(cha[v]==0)
        {
            cha[v]=u;
            dfs(v);
        }
    }
    xoa[u]=1;
}
void nhap()
{
    scanf("%d %d",&n,&m);
    int x,y;
    for(int i=1; i<=m; i++)
    {
        scanf("%d %d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }

}
void giai()
{
    for(int i=1;i<=n;i++)
    {

        if(cha[i]==0)
        {
            cha[i]=n+1;
            dfs(i);
        }
    }
    cout<< res;
}
int main()
{
    freopen("ads.inp","r",stdin);
    freopen("ads.out","w",stdout);
    nhap();
    giai();
}
