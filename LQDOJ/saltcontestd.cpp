#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b,c) for(int  i = a ; i <=b ;i+=c)
#define fd(i,a,b,c) for(int  i = a ; i >=b ;i-=c)
#define ll long long
#define SZ(c) c.size()
const ll maxsize = 100000;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void inti()
{
    freopen(".inp","r",stdin);
    freopen(".our","w",stdout);
}
vector<ll>a[5*maxsize+5];
ll b[5*maxsize+5],d[maxsize*5+5],cha[maxsize*5+5],kt=0,ans=0;
void dfs(ll u)
{
    if(b[u]) d[u]=1;
    fu(i,0,SZ(a[u])-1,1)
    {
        ll v=a[u][i];
        if(v!=cha[u])
        {
            if(b[u]*b[v]!=0)
            {
                kt=1;
                return ;
            }
            cha[v]=u;
            dfs(v);
            d[u]+=d[v];
        }


    }
    if(d[u]>1)
    {
        if(b[u])
        {
            ans+=d[u]-1;
            d[u]=1;
        }
        else
        {
            ans++;
            d[u]=0;
        }
    }
}
void nhap()
{
    ll n,m,x,y;
    cin >> n >> m;
    fu(i,1,n-1,1)
    {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    fu(i,1,m,1)
    {
        cin >> x;
        b[x]=1;

    }
    dfs(1);
    if(kt==1)
    {
        cout << "-1" ;
    }
    else
    {
        cout << ans;
    }

}
int main()
{
    fastio();
    nhap();
}

