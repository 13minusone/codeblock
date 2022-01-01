#include<bits/stdc++.h>
using namespace std;

int cha[100005],f[100005];
int n,m,s;
vector<int> a[100005];

int k=0;
void truyvet(int r)
{
   vector<int>vec;
    int h=r;
    vec.push_back(r);
    r=cha[r];
    while(r!=h)
    {
        k++;
        vec.push_back(r);
        r=cha[r];
    }

    cout<<vec.size()+1<<endl;
    cout<<h<<" ";
    for(int i=vec.size()-1; i>=0; i--)cout << vec[i] << " ";


}


void dfs(int u,int d)
{
    if(k>0) return;
    for(int i=0; i<a[u].size(); i++)
    {
        int v=a[u][i];
        if(v==d)continue;
        if(cha[v]!=0)
        {
            cha[v]=u;
            if(k==0)truyvet(v);
           // cout<<u<<" "<<v<<endl;
           return;
        }
        if(cha[v]==0)
        {
            cha[v]=u;
            dfs(v,u);
        }
    }
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
    for(int i = 1 ; i<=n ; i++)
    {
        if(cha[i]==0)
        {
            cha[i]=n+1;
            dfs(i,i);
        if(k!=0)
        {
            return;
        }
        }
    }
    if(k==0) cout<<"IMPOSSIBLE";
}
int main()
{
//    freopen("ctdon.inp","r",stdin);
//   freopen("ctdon.out","w",stdout);
    nhap();
    giai();
}


