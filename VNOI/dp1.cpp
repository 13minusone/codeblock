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
typedef long long ll ;
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll N = 1e5;
const ll mod =1e9+7;
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
ll dp[N+5][3];
int n,u,v;
vector<int>edge[N+5];
void dfs(int u,int v)
{
    dp[u][0]=dp[u][1]=1;
    for(int i : edge[u])
    {
        if(i==v)continue;
        dfs(i,u);
        dp[u][0] = (dp[u][0] * (dp[i][0] + dp[i][1]))%mod;
        dp[u][1] = (dp[u][1] * dp[i][0]) % mod;
    }

}
void nhap()
{
    cin >> n;
    for(int i = 1 ; i < n ; i++)
    {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1,-1);
    cout << (dp[1][0]+dp[1][1])%mod ;
}
int main()
{

    fastio();
    // inti();
    nhap();
}




