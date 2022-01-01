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
#define task "TG01MAGIC"
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
char a[105][105];
ll n,m,k,f[105][105];
int dx[5]={0,1,0,-1,0};
int dy[5]={0,0,-1,0,1};
bool cango(int l,int r)
{
    if(l>n||r>m)return false;
    if(a[l][r]=='#')return false;
    return true;
}
void dfs(int i,int j)
{
    for(int o = 1 ; o <= 4 ; o++)
    {
        int i1 = i+dx[o],j1=j+dy[o];
        if(cango(i1,j1)==true)
        {
            if(f[i1][j1]>f[i][j]+1)
            {
                f[i1][j1]=f[i][j]+1;
                dfs(i1,j1);
            }
        }
    }
}
void nhap()
{
    ii x,y;
    int u,v;
    cin >> n >> m >> k;
    for(int i = 1; i <= n ; i++)
    {
        for(int j = 1; j <= m ; j++)
        {
            cin >> a[i][j];
            f[i][j]=N;
            if(a[i][j]=='S')
            {
                x.first=i;
                x.second=j;
            }
            if(a[i][j]=='F')
            {
                y.first=i;
                y.second=j;
            }
        }
    }
    for(int i = 1; i <= k ;i++)
    {
        cin >> u >> v;
    }
    f[x.first][x.second]=0;
    dfs(x.first,x.second);
    cout << f[y.first][y.second];
}
int main()
{

    fastio();
     inti();
    nhap();
}




