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
const ll N = 2e5+5;
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
int n,u,v,hi[N+5],ho[N+5],sufmax[N],premax[N];
vector<int>edge[N];
void disin(int u ,int v)
{
    int maxx=-1;
    for(int i :edge[u])
    {
        if(i==v)continue;
        disin(i,u);
        maxx=max(maxx,hi[i]);
    }
    hi[u]=maxx+1;
}
void disout(int u , int v)
{
    for(int i = 0 ; i < SZ(edge[u]) ; i++)
    {
        if(edge[u][i]==v)continue;
        if(i==0)premax[i]=0;
        else if(edge[u][i-1]!=v) premax[i]=max(premax[i-1],hi[edge[u][i-1]]);
        else if(i-2 >=0) premax[i]=max(premax[i-2],hi[edge[u][i-2]]);
        else premax[i]=0;
    }
     for(int i = SZ(edge[u])-1 ; i >=0  ; i--)
    {
        if(edge[u][i]==v)continue;
        if(i==SZ(edge[u])-1)sufmax[i]=0;
        else if(edge[u][i+1]!=v) sufmax[i]=max(sufmax[i+1],hi[edge[u][i+1]]);
        else if(i+2 <=SZ(edge[u])-1) sufmax[i]=max(sufmax[i+2],hi[edge[u][i+2]]);
        else sufmax[i]=0;
    }

    for(int i = 0 ; i < SZ(edge[u]) ; i++)
    {
        if(edge[u][i] == v)continue;
        if(SZ(edge[u])>1)ho[edge[u][i]]=max({ho[u]+1,sufmax[i]+2,premax[i]+2});
        else ho[edge[u][i]]= ho[u]+1;
    }
    for(int i :edge[u])
    {
        if(i==v)continue;
        disout(i,u);
    }
}
void nhap()
{
    cin >> n;
    for(int i = 1;  i < n ; i++)
    {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    disin(1,-1);
    disout(1,-1);
    for(int i = 1;  i <= n ; i++)cout << max(hi[i],ho[i]) << " ";
}
int main()
{

    fastio();
    // inti();
    nhap();
}



