#include<bits/stdc++.h>
using namespace std;
#define task ""
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
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
vector<ll>a[25];
ll b[25],cha[25][25];
void dfs(ll n )
{
    for(int v:a[n])
    {
        if(cha[v]!=0)
        {
            b[v]+=b[n];
            cha[v]=n;
            dfs(v);
        }
    }
}
void nhap()
{

    ll n,m,x,y;
    cin >> n >> m;
    for(int i=1 ; i<=m ; ++i)
    {
        cin >>x >> y;
        a[x].push_back(y);
    }
    b[1]=1;
    dfs(1);
    cout << b[n];
}
int main()
{

    fastio();
    // inti();
    nhap();
}


