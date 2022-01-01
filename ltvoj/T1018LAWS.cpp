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
#define task "T1018LAWS"
#define SZ(c) c.size()
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
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }
const ll N = 1e5+5;
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
int n,m,dd[N],cnt[N],u,v,check[N];
vector<int>edge[N];
void dfs(int u,int k)
{
    if(k>3)return;
    if(k==3 && dd[u]==1){
        cnt[u]+=1;
        return;
    }
    if(k== 3 && dd[u]==0)return;
    for(int i : edge[u])
    {
        if(i==u || i == 1)continue;
        if(check[i]==0){
                check[i]=1;
            dfs(i,k+1);
        check[i]=0;
        }
    }
}
void nhap()
{
    cin >> n >> m;
    for(int i = 1 ; i <= m ; i++)
    {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for(int i : edge[1])dd[i]=1;
    check[1]=1;
    dfs(1,0);
    ll res=0;
    for(int i = 1;  i<= n ; i++)
    {
        sort(all(edge[i]));
        edge[i].resize(unique(all(edge[i]))-edge[i].begin());
    }
    for(int i : edge[1])
    {
       res+= cnt[i] ;
    }
    cout << res;
}
int main()
{

    fastio();
    inti();
    nhap();
}




