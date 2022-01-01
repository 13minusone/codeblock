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
#define task "dienbien"
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
const ll N = 1e5 + 5;
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
    //freopen(task".out","w",stdout);
}
int t,n = 0 ,k = 0,u,v;
bool check[23],a[23],b[23],te=true;
vector<int>edge[23];
void dfs(int u,int pre)
{
    if(te==false)return;
    for(int v : edge[u])
    {
        if(v!=pre)
        {
            if(a[v] == false)
            {
                te=false;
                return;
            }
            dfs(v,u);
        }
    }
}
void ktra()
{
    for(int i = 1 ; i <= k ; i++)
    {
        dfs(b[i],-1);
        if(te == false)return ;
    }
    return;
}
vector<int>vec;
ll sub1(int n,int k)
{
    vec.clear();
    int minn =50;
        memset(a,true,sizeof a);
        for(int i = 1 ;i <= k;i++)
        {
                cin >> b[i];
                a[ b[i] ]=false;
        }
        for(int i = 1 ;i <= n ; i++)
        {
            if(a[i] == true )vec.push_back(i);
            edge[i].clear();
        }
        for(int i = 1 ; i < n ; i++)
        {
            cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        int s=0;
        for(int i = 1 ; i < mu2(n-k) ; i++)
        {
            memset(check,true,sizeof check);
            te=true;
            for(int j = 0 ; j <n-k;j++)
            {
                if(getbit(i,j)==1){
                    check[vec[j]]=false;
                s++;
                }
            }
            ktra();
        if(te==true)minimize(minn,s);
        }
        return minn;
}
void nhap()
{
    cin >> t;
    while(cin)
    {
        cin >> n >> k;
        if(n == -1)return;
        cout << sub1(n,k) << endl;
    }
}
int main()
{

    fastio();
    inti();
    nhap();
}




