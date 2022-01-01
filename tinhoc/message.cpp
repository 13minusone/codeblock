#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b,c) for(int i= a; i <=b; i+=c)
#define fd(i,a,b,c) for(int i = a ; i  >=b ;i-=c)
#define ll long long
vector <ll> a[100005];
long long s[100005],q[100005],f[100005];
long long n,m,u,v,res=0;
void inti()
{
    freopen("message.inp","r",stdin);
    freopen("message.out","w",stdout);
}
long long bfs(long long x)
{
    s[x]=2;
    ll l=1,r=1;
    q[1]=x;
    while(l<=r)
    {
        u=q[l];
        l++;
        int m1=a[u].size()-1;
        fu(i,0,m1,1)
        {
            v=a[u][i];
            if(s[v]==0)
            {
                r++;
                q[r]=v;
                s[v]=1;
            }
        }
    }
}
long long bfs1(long long x)
{
    f[x]=2;
    ll l=1,r=1;
    q[1]=x;
    while(l<=r)
    {
        u=q[l];
        l++;
        int m2=a[u].size()-1;
        fu(i,0,m2,1)
        {
            v=a[u][i];
            if(f[v]==0)
            {
                r++;
                q[r]=v;
                f[v]=1;
            }
        }
    }
}
void nhap()
{
    cin>>n>>m;
    for(ll i=1; i<=m; i++)
    {
        cin>>u>>v;

        a[u].push_back(v);


    }
    fu(i,1,n,1)
    {
        if(s[i]==0)
        {
            bfs(i);
        }
    }
    fd(i,n,1,1)
    {
        if(s[i]==2&&f[i]==0)
        {
            bfs1(i);
            res++;
        }
    }
    cout<<res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //inti();
nhap();
}
