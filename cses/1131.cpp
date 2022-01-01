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
const ll maxsize = 200000;
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
int n,x,y,f[maxsize+5],cha[maxsize+5],maxx=0;;
vector<int>vec[maxsize+5];
vector<int>b[maxsize+5];
void dfs(int u )
{
    for(int v : vec[u])
    {
        if(cha[v]==0)
        {
            cha[v]=u;
            dfs(v);
            //cout << u << " "<< v << " "<< f[v] << endl;
            b[u].push_back(f[v]+1);
            f[u]=max(f[u],f[v]+1);
        }
    }
    sort(b[u].begin(),b[u].end(),greater<int>());
    if(b[u].size()==0)
    {
        return;
    }
    if(b[u].size()==1)
    {
        maxx=max(maxx,b[u][0]);
    }
    else
    {
        maxx=max(maxx,b[u][0]+b[u][1]);
    }
}
void nhap()
{
    cin >> n;
    for(int i = 1 ; i <= n-1 ; i++)
    {
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    cha[1]=1;
    dfs(1);
    cout << maxx << endl;
}
int main()
{

    fastio();
    // inti();
    nhap();
}



