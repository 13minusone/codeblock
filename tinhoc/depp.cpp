#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
vector<int>vec[1000001];

    int m,n,x,s,t,y,cha[1000001];
/*
-----------------AUTHOR-----------------------
--------------Parth Mangal--------------------
----------------------------------------------

██████╗░██╗░░░░░███████╗░█████╗░░██████╗███████╗  ██████╗░░█████╗░███╗░░██╗██╗████████╗
██╔══██╗██║░░░░░██╔════╝██╔══██╗██╔════╝██╔════╝  ██╔══██╗██╔══██╗████╗░██║╚█║╚══██╔══╝
██████╔╝██║░░░░░█████╗░░███████║╚█████╗░█████╗░░  ██║░░██║██║░░██║██╔██╗██║░╚╝░░░██║░░░
██╔═══╝░██║░░░░░██╔══╝░░██╔══██║░╚═══██╗██╔══╝░░  ██║░░██║██║░░██║██║╚████║░░░░░░██║░░░
██║░░░░░███████╗███████╗██║░░██║██████╔╝███████╗  ██████╔╝╚█████╔╝██║░╚███║░░░░░░██║░░░
╚═╝░░░░░╚══════╝╚══════╝╚═╝░░╚═╝╚═════╝░╚══════╝  ╚═════╝░░╚════╝░╚═╝░░╚══╝░░░░░░╚═╝░░░

░██╗░░░░░░░██╗░█████╗░████████╗░█████╗░██╗░░██╗  ███╗░░░███╗██╗░░░██╗  ░█████╗░░█████╗░██████╗░███████╗
░██║░░██╗░░██║██╔══██╗╚══██╔══╝██╔══██╗██║░░██║  ████╗░████║╚██╗░██╔╝  ██╔══██╗██╔══██╗██╔══██╗██╔════╝
░╚██╗████╗██╔╝███████║░░░██║░░░██║░░╚═╝███████║  ██╔████╔██║░╚████╔╝░  ██║░░╚═╝██║░░██║██║░░██║█████╗░░
░░████╔═████║░██╔══██║░░░██║░░░██║░░██╗██╔══██║  ██║╚██╔╝██║░░╚██╔╝░░  ██║░░██╗██║░░██║██║░░██║██╔══╝░░
░░╚██╔╝░╚██╔╝░██║░░██║░░░██║░░░╚█████╔╝██║░░██║  ██║░╚═╝░██║░░░██║░░░  ╚█████╔╝╚█████╔╝██████╔╝███████╗
░░░╚═╝░░░╚═╝░░╚═╝░░╚═╝░░░╚═╝░░░░╚════╝░╚═╝░░╚═╝  ╚═╝░░░░░╚═╝░░░╚═╝░░░  ░╚════╝░░╚════╝░╚═════╝░╚══════╝
*/
void truyvet(int v)
{
    int d = 0,ds[100001];
    while(v!=INT_MAX)
    {
        d++;
        ds[d]=v;
        v=cha[v];

    }

    fd(i,d,1,1)
    {
        cout << ds[i] << " ";
    }
}
void dfs(int v)
{
    if(v==t)
    {
        truyvet(v);
        return;
    }
    fu(i,0,vec[v].size()-1,1)
    {
        int u=vec[v][i];

        if(cha[u]==0)
        {
            cha[u]=v;
            dfs(u);
        }

    }
}
void inti()
{
   freopen("test1.inp","r",stdin);
   freopen("test1.out","w",stdout);
}

void nhap()
{

cin >> n >> m >> s >> t;
fu(i,1,m,1)
{
    cin >> x >> y;
    vec[x].pb(y);
    vec[y].pb(x);
}
fu(i,1,n,1)
{
    sort(vec[i].begin(),vec[i].end());
}
cha[s]=INT_MAX;
dfs(s);
}
int main()
{
IOS
inti();
nhap();

}


