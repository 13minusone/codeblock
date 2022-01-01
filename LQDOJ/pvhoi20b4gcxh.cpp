/*
🛸　　　 　🌎　°　　🌓　•　　.°•　　　🚀 ✯
　　　★　*　　　　　°　　　　🛰 　°·　　                           🪐
.　　　•　° ★　•  ☄
______________________________________________________
    You are watching a brute force code
        CODE IS WRITTEN BY 13MINUSONE
*/
#include<bits/stdc++.h>
using namespace std;
#define task "c"
#define SZ(c) (int)c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
#define all(x) x.begin(),x.end()
#define endl '\n'
#define fi first
#define se second
typedef long long ll ;
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B)
{
    A=min(A,B);
}
template<class T> void maximize(T &A, T B)
{
    A=max(A,B);
}
const ll N = 3e5+5;
const ll mod =998244353;
const ll base = 311;
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
ll powe(ll a,ll n)
{
    ll ret = 1;
    while (n)
    {
        if (n & 1)
        {
            ret *= a;
            ret %= mod;
        }
        a *= a;
        a %= mod;
        n /= 2;
    }
    return ret%mod;
}
int n,m,sub,low[N],num[N],cnt,dd[N],child[N],cntdinh[N],goclon[N],u,v,cha[N];
ll k;
ii canh[N];
vector<int>vec[N];
vector<ii>edge[N];
map<ii,int>mp;
void add(ll &a,ll b)
{
    a+=b;
    if(a>=mod)a-=mod;
}
void dfs(int u,int v,int pre)
{

    num[u]=low[u]=++cnt;
    for(ii i : edge[u])
    {
        if(i.fi==v)continue;
        if(!num[i.fi])
        {
            dfs(i.fi,u,pre);
            child[u]+=(child[i.fi]+1);
            low[u]=min(low[u],low[i.fi]);
            if(low[i.fi]==num[i.fi])dd[i.se]=1;
            vec[u].push_back(i.fi);
            goclon[u]=pre;
            if(u==v)
            {
                if(SZ(vec[u])>1)cntdinh[u]=1;
            }
            if(low[i.fi]>=num[u])cntdinh[u]=1;
        }
        else low[u]=min(low[u],num[i.fi]);
    }
}
ll dfs1(int u)
{
    int sum=0;
    for(ii i : edge[u])
    {
        if(cha[i.fi]==0)
        {
            cha[i.fi]=u;
            sum+=dfs1(i.fi);
        }
    }
    return sum+1;
}
ll sub2(int i)
{
    memset(cha,0,sizeof cha);
    int g=0,sum[N];
    cha[i]=-1;
    for(ii u : edge[i])
    {
        if(cha[u.fi]==0)
        {
            cha[u.fi]=-1;
            int x=dfs1(u.fi);
            g+=x;
            sum[u.fi]=x;
            //cout << x << " " << u.fi << endl;
        }
    }
    ll p=0;
    for(ii u : edge[i])
    {
        if(cha[u.fi]==-1)
        {
            add(p,(1LL*sum[u.fi]*(g-sum[u.fi]))%mod);
        }
    }
    //cout << i << " " << g-1 << " ";
    cout << ((p%mod)*(k%mod))%mod << " " ;
}
void sub3(int i)
{
    ll sum=0;
    for(int v : vec[i])
    {
        sum+=(child[v]+1);
        cout <<v << " "<<  child[v] << endl;
    }
    int x=child[goclon[i]]-sum;
    sum+=x;
    ll p=0;
    for(int v : vec[i])
    {
        add(p,(1LL*(child[v]+1)*(sum-(child[v]+1))%mod));
    }
    add(p,(1LL*x*(sum-x))%mod);
    cout <<((p%mod)*(k%mod))%mod<< endl;
}
void nhap()
{
    cin >> sub;
    cin >> n >> m;
    for(int i = 1; i <= m ; i++)
    {
        cin >> u >> v;
        if(u>v)swap(u,v);
        if(mp[ii(u,v)]==0)
        {
            edge[u].push_back(ii(v,i));
            edge[v].push_back(ii(u,i));
            canh[i]=ii(u,v);
            mp[ii(u,v)]=1;
        }
    }
    k=powe(2,mod-2);
    for(int i = 1 ; i <= n ; i++)if(num[i]==0)dfs(i,i,i);
    for(int i = 1 ; i <= n ; i++)
    {

        if(cntdinh[i]==1)
        {
            if(m<=3000)sub2(i);
            else sub3(i);
        }
        else cout << 0 <<" " ;
    }
    cout << endl;
    for(int i = 1; i <= m ; i++)
    {
        if(dd[i]==1)
        {
            int u=canh[i].fi,v=canh[i].se;
            if(num[u]>num[v])swap(u,v);
            int x=child[goclon[u]]-child[v];
            ll p=(1LL*x*(child[v]+1))%mod;
            cout <<  p << " " ;
        }
        else cout << 0 <<  " ";
    }


}
int main()
{

    fastio();
    // inti();
    nhap();
}




