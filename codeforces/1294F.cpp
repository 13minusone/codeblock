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
#define task "c9"
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
const int block = 488;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void inti()
{
        if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
}
int maxx=0,res=0,n,x,y,hi1[N],hi2[N],hi3[N],par[N],d[N];
vector<int>edge[N];
void dfs(int u,int pre,int hi[])
{
    if(hi[u] > maxx){
        res=u;
        maxx=hi[u];
    }
    for(int v : edge[u])
    {
        if(v!=pre)
        {
            hi[v]=hi[u]+1;
            par[v]=u;
            dfs(v,u,hi);
        }
    }
}
void dfs2(int u,int pre)
{
    for(int v : edge[u])
        if(v!=pre)
        {
            if(d[v] ==1)hi3[v]=0;
            else hi3[v]=hi3[u]+1;
            dfs2(v,u);
        }
}
void dfs3(int u,int pre)
{
    memset(d,0,sizeof d);
    while(u!=pre)
    {
        //dfs2(u,-1,hi3);
        d[u]=1;
        u=par[u];
        //cout << u << endl;
    }
    dfs2(x,-1);
}
void nhap()
{
    cin >> n;
    for(int i = 1; i < n ; i++)
    {
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    dfs(1,-1,hi1);
    maxx=0;
    x=res;
    dfs(x,-1,hi2);
    y=res;
    if(hi2[y] == n-1)
    {
        for(int i = 1 ; i <= n ; i++)
            if(i!=x && i!=y){
                cout << n-1<< endl;
                cout << x << " " << y << " " << i ;
                break;
            }
    }
    else
    {
        maxx=0;
        dfs3(y,x);
        ll z=0;
        maxx=0;
        for(int i = 1; i <= n ; i++)
        {
            if(hi3[i] > maxx && i !=x && i !=y){
                    maxx=hi3[i];
                    z=i;
            }
        }
        cout << hi2[y]+hi3[z]<< endl;
        cout << x << " "<< y << " " << z;
    }
}
int main()
{

    fastio();
     inti();
    nhap();
}




