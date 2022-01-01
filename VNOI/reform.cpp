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
const ll N = 2e5 + 5;
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
int brigde = 0, n , m,low[N],num[N],khop[N],cnt=0,child[N],tplt=0,child1 = 0;
vector<int> egde[N];
void dfs(int u ,int pre)
{
    if(tplt == 1)child1++;
    child[u]=1;
    num[u]=low[u]=++cnt;
    for(int i : egde[u])
    {
        if(i == pre )continue;
        if(!num[i])
        {
            dfs(i,u);
            low[u]=min(low[u],low[i]);
            if(low[i] == num[i])brigde++;
            child[u]+=child[i];
        }
        else low[u]=min(low[u],num[i]);
    }
}
void nhap()
{
    int u,v;
    cin >> n >> m;
    for(int i = 1 ; i <= m ; i++)
    {
        cin >> u >> v;
        egde[u].push_back(v);
        egde[v].push_back(u);
    }
     tplt = 0;
    for(int i = 1; i <= n ; i++)
    {

        if(!num[i])
        {
            tplt++;
            dfs(i,i);
        }
        //cout << i << " "<< num[i] <<" " << low[i] <<endl;
    }
    //cout << brigde << endl;
    ll res;
    if(tplt>2)res=0 ;
    else if(tplt == 2)
    {
        //cout << child1;
        res = 1LL * (m - brigde) * child1 * (n-child1) ;
    }
    else
    {
        res=1LL * (m-brigde) * (1LL*n*(n-1)/2-m);
        for(int i =  2 ; i <= n ; i++)
            if(low[i] == num[i])
            {
                res += 1LL *child[i]*(n-child[i]) - 1 ;
            }
    }
    cout <<res << endl;

}
int main()
{

    fastio();
    // inti();
    nhap();
}



