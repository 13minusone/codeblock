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
map<int,bool>dd[N+5];
void inti()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
struct queries
{
    int u,v,z;
    queries(int x = 0 , int y = 0 ,int _z =0)
    {
        u=x;
        v=y;
        z=_z;
    }
};
vector<int>edge[N+5];
ll a[N+5];
vector<queries>vec;
void tomau(int u,int v,int d)
{
    if(dd[u][d]||d<0)return ;
    dd[u][d]=true;
    if(!a[u])a[u]=v;
    for(int i : edge[u])tomau(i,v,d-1);
}
void nhap()
{
    ll n,m,u,v,z,q;
    cin >> n >> m;
    for(int i = 1 ;i <= m ; i++)
    {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    cin >> q;
    for(int i = 1 ;i <= q ; i++)
    {
        cin >> u >> v >> z;
        vec.push_back(queries(u,v,z));
    }
    for(int i = q-1 ; i>=0 ;i--)
    {
        tomau(vec[i].u,vec[i].z,vec[i].v);
    }
    for(int i = 1 ; i <= n ; i++)
    {
        cout << a[i] << endl;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}




