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
#define task "pie"
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
template<class T> void minimize(T &A, T B)
{
    A=min(A,B);
}
template<class T> void maximize(T &A, T B)
{
    A=max(A,B);
}
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
int n,m,a[305][305];
ll f[305][305];
void nhap()
{
    cin >> n >> m;
    memset(f,mod,sizeof f);
    f[0][0]=0;
    for(int i = 1; i <= n ; i++)
    {
        for(int j = 1 ; j <= m ; j++)
        {
            cin >> a[i][j];
        }
        sort(a[i]+1,a[i]+1+m);
        for(int j=1; j<=n; j++)
        {
            int s=0;
            for(int k=1; k<=m; k++)
            {
                s+=a[i][k];
                if(j-i-k+1>=0)
                {
                    minimize(f[i][j],min( f[i-1][j], f[i-1][j-k]+s+k*k));
                }
            }
        }
    }
    cout << f[n][n];
}
int main()
{

    fastio();
    inti();
    nhap();
}




