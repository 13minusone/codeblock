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
#define task "T1004PRE"
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
template<class T> void minimize(T &A, T B)
{
    A=min(A,B);
}
template<class T> void maximize(T &A, T B)
{
    A=max(A,B);
}
const ll N = 1e5;
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
vector<int>edge[N+5];
int u,v,hi[N+5],s=0;
void dfs(int u, int v)
{
    if(u!=1)
    {
        int p=1;
        while(p<SZ(edge[u]))
        {
            p*=2;
            s++;
        }
    }
    for(int i : edge[u])
    {
        if(i==v)continue;
        hi[i]=hi[u]+1;
        s++;
        dfs(i,u);
    }
}
void nhap()
{
    int n;
    cin >> n;
    for(int i = 1; i < n ; i++)
    {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1,-1);
    int p=1;
    while(p<SZ(edge[1])+1)
    {
        p*=2;
        s++;
    }
    cout << s << endl;
}
int main()
{

    fastio();
     inti();
    nhap();
}




