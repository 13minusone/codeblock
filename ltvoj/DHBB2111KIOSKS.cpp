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
#define task "DHBB2111KIOSKS"
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) ((1LL) << x)
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
vector<int>edge[10005];
ll f[10004],a[10004];
bool check[10005],dd[10005];
int n,k,x,y;
void dfs(int u,int v)
{
    f[u]=1;
    for(int i : edge[u])
    {
        if(!dd[i]&& i!=v)
        {
            check[i]=true;
            dfs(i,u);
            f[u]=f[u]*(f[i]+1)%mod;
        }
    }
}
void them(int &a, int y)
{
    a+=y;
    if(a>=mod)a-=mod;
}
void tru(int &a,int y)
{
    a-=y;
    if(a<0)a+=mod;

}
ll dem(int m)
{
    memset(dd,false,sizeof dd);
    memset(check,false,sizeof check);
    for(int i = 1 ; i <= n ; i++)
        if(a[i] <= k && getbit(m,a[i]-1))dd[i]=true;
    for(int i = 1 ; i <= n ; i++)
    {
        if(!check[i]&&!dd[i])
        {
            dfs(i,-1);
        }
    }
    int s=0;
    for(int i = 1 ; i <= n ; i++)
    {
        if(!dd[i])
        {
            them(s,f[i]);
        }
    }
    return s;
}
void nhap()
{

    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++)cin >> a[i];
    for(int i = 1 ; i < n ; i++)
    {
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    int res=0;
    //cout << k << endl;
    for(int i = 0 ; i < mu2(k); i++)
    {
        if(__builtin_popcount(i)&1)
        {

            tru(res,dem(i));
        }
        else
        {
            them(res,dem(i));
        }
        //cout << res << endl;
    }
    cout << res << endl;
}
int main()
{

    fastio();
     inti();
    nhap();
}



