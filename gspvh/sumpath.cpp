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
#define task "sumpath"
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
ll f[2212][2212],s[2212][2212];
int a[2212][2212];
string x;
int dx[6]= {1,0,1};
int dy[6]= {0,1,1};
bool cango(int x,int y)
{
    if(x > n || y > m || y < 1 || x < 1)return false;
    else return true;
}
void add(ll &a,ll b)
{
    a+=b;
    if(a>=mod)a-=mod;
}
void nhap()
{
    cin >> n >> m;
    for(int i =1 ; i <= n ; i++){
        cin >> x;
        for(int j = 0; j < m ; j++)
        {
            a[i][j+1]=int(x[j]-'0');
        }
    }
    f[1][1]=1;
    s[1][1]=a[1][1];
    for(int i = 1 ; i <= n; i++)
        for(int j = 1 ; j <= m ; j++)
        {
            for(int k = 0; k <= 2 ; k++)
            {
                    int x=i+dx[k];
                    int y=j+dy[k];
                    if(cango(x,y) == true)
                    {
                        add(f[x][y],f[i][j]);
                        add(s[x][y],(s[i][j]+(f[i][j]*a[x][y])%mod)%mod);
                    }
            }
        }
    cout << s[n][m] ;
}
int main()
{

    fastio();
    // inti();
    nhap();
}





