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
const ll N = 1e6 + 5;
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
ll f[N][8],dp[N];
void sang()
{
    for(int i = 2 ; i <= N ; i++)
    {
        if(dp[i] == 0)
        {
            for(int j = 2 * i ; j <= N ; j+=i)
            {
                dp[j]+=1;
            }
            dp[i]=1;
        }
    }
    for(int i = 1 ; i <= N ; i++)
    {
        for(int j = 1 ; j <= 7 ; j++)f[i][j]=f[i-1][j];
        f[i][dp[i]]+=1;
    }
}
int a,b,k;
void nhap()
{
    int n;
    cin >> n ;
    sang();
    while(n--)
    {
        cin >> a >> b >> k;
        cout << f[b][k]-f[a-1][k] << endl;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}




