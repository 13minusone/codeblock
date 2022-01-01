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
int n,k,x,goc;
vector<int>vec[2*N+5];
int up[2*N+5][18],a[2*N+5],Log=18;
int hi[2*N+5];
void dfs(int u,int v)
{

    for(int p : vec[u])
    {
        if(p==v)continue;
        hi[p]=hi[u]+1;
        up[p][0]=u;
         for(int i = 1 ; i<Log ; i++)
    {
        up[p][i]=up[up[p][i-1]][i-1];
    }
        dfs(p,u);
    }
}
ll lca(int u,int v)
{
    if(hi[u]<hi[v])swap(u,v);
    for(int i = Log-1;i>=0;i--)
    {
        if(hi[up[u][i]]>=hi[v])
        {
            u=up[u][i];
        }
    }
    if(u==v)return u;
    for(int i = Log-1 ; i >= 0 ; i--)
    {
        if(up[u][i]!=up[v][i])
        {
            v=up[v][i];
            u=up[u][i];

        }
    }
    return up[u][0];
}
vector<int>nhom[N+5];
void nhap()
{
    cin >> n >> k;
    for(int i = 1 ;i <= n ; i++)
    {
        cin >> a[i] >> x;
        if(x!=0)
        {
            vec[x].push_back(i);
            vec[i].push_back(x);
        }
        else
        {
            goc=i;
        }
        nhom[a[i]].push_back(i);
    }
    hi[goc]=0;
    dfs(goc,-1);
   // cout << hi[6] << " "<< hi[3] <<endl;
    for(int i = 1 ;i <= k ; i++)
    {
       int deep=nhom[i][0];
       for(int j = 1 ; j <SZ(nhom[i]);j++)
       {
           if(hi[nhom[i][j]]>hi[deep])
           {
               deep=nhom[i][j];
           }
       }
       //cout <<i << " "<<  deep << endl;
       ll maxx=0;
       for(int j :nhom[i])
       {
           int v=lca(deep,j);
           //cout <<i<< " "<<j << " "<< v <<endl;
           maxx=max(maxx,(ll)hi[deep]+hi[j]-2*hi[v]);
       }
       cout << maxx << endl;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}




