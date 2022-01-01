#include<bits/stdc++.h>
using namespace std;

int cha[100001],xoa[100001];
int n,m,s;
vector<int> a[100005];

int k=0;
void truyvet(int f)
{
    int q[100005];
	//q[1]=p;
	while(f!=n+1)
    {
        k++;
        q[k]=f;//cha[p];
        f=cha[f];
    }

    cout<<k<<endl;
    for(int i=k;i>=1;i--) printf("%d ",q[i]);
    cout<<s<<" ";

}


void dfs(int u)
{
    if(k>0) return;
    //cout<<u<<endl;
    for(int i=0; i<a[u].size(); i++)
    {
        int v=a[u][i];
        if(v==s&&cha[u]!=s)
        {
            if(k==0) truyvet(u);
            return;
            //cout<<u<<" "<<cha[u]<<" "<<v<<endl;
        }
        if(cha[v]==0)
        {
            cha[v]=u;
            dfs(v);
        }
    }
}
void nhap()
{
    scanf("%d %d %d",&n,&m,&s);
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
    cha[s]=n+1;
    dfs(s);
    if(k==0) cout<<0;
}
int main()
{
//    freopen("ctdon.inp","r",stdin);
//    freopen("ctdon.out","w",stdout);
    nhap();
    giai();
}

