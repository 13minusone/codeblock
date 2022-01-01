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
#define ll long long
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
#define fi first
#define se second
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll maxsize = 100000;
const ll mod =1e9+9;
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
vector<ii>vec[1005];
ll cha[1005],hi[1005],d[1005];
void dfs(int u)
{
    for(ii p : vec[u])
    {
        if(cha[u]!=p.fi)
        {
            cha[p.fi]=u;
            d[p.fi]=p.se;
            hi[p.fi]=hi[u]+1;
            dfs(p.fi);
        }
    }
}
ll solve(int u,int v)
{
    ll sum=0;
    while(hi[u]>hi[v])
    {
        sum+=d[u];
        u=cha[u];
    }
    while(hi[u]<hi[v])
    {
        sum+=d[v];
        v=cha[v];
    }
    while(u!=v)
    {
        sum+=d[u]+d[v];
        v=cha[v];
        u=cha[u];
    }
    return sum;
}
void nhap()
{
    int n,q,x,y,z;
    cin >> n >> q;
    for(int i = 1 ; i < n ; i++)
    {
        cin >> x >> y >> z;
        vec[x].push_back({y,z});
        vec[y].push_back({x,z});
    }
    dfs(1);
    for(int i = 1 ; i <= q ; i++)
    {
        cin >> x >> y;
        cout << solve(x,y) << endl;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}



