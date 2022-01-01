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
#define fi first
#define se second
typedef long long ll ;
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class X, class Y>
bool minimize(X &x, const Y &y)
{
    X eps = 1e-9;
    if (x > y + eps)
    {
        x = y;
        return true;
    }
    else return false;
}
template<class X, class Y>
bool maximize(X &x, const Y &y)
{
    X eps = 1e-9;
    if (x + eps < y)
    {
        x = y;
        return true;
    }
    else return false;
}
template<class T>
T Abs(const T &x)
{
    return (x < 0 ? -x : x);
}
const ll N = 1e5 + 5;
const ll mod =998244353;
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
int n,m;
ll f[2212][2212][6];
int a[2212][2212];
char x;
int dx[6]= {1,0,1,1,2};
int dy[6]= {0,1,1,2,1};
bool cango(int x,int y)
{
    if(x > n || y > m || y < 1 || x < 1 || a[x][y] == 1)return false;
    else return true;
}
void add(ll &a,ll b)
{
    a+=b;
    if(a>=mod)a-=mod;
}
ll minu(ll a,ll b)
{
    a-=b;
    if(a<=0)a+=mod;
    return a;
}
void nhap()
{
    cin >> n >> m;
    for(int i =1 ; i <= n ; i++)
        for(int j = 1; j <= m ; j++)
        {
            cin >> x;
            if(x=='#')a[i][j]=1;
            else a[i][j]=0;
        }
    for(int i = 1 ; i <= n; i++)
        for(int j = 1 ; j <= m ; j++)
            if(a[i][j] == 0)
            {
                ll s=0;
                for(int l = 0 ; l <= 4 ; l++)add(s,f[i][j][l]);
                for(int k = 0; k <= 4 ; k++)
                {
                    int x=i+dx[k];
                    int y=j+dy[k];
                    if(cango(x,y) == true)
                    {
                            if(i == 1&& j ==1)
                            {
                                add(f[x][y][k],1);
                            }
                            else add(f[x][y][k],minu(s,f[i][j][k]));
                    }
                }
            }
    ll s=0;
    for(int i = 0 ; i <= 4 ; i++)add(s,f[n][m][i]);
    cout << s ;
}
int main()
{

    fastio();
    // inti();
    nhap();
}




