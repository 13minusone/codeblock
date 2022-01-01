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
typedef pair<ll,ll> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll N = 1e5;
const ll mod =1e18+9;
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
ll a[5005],b[5005],pre[5005][5005],n,maxx=-mod;
ll f[10005];
void nhap()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++)cin >> a[i];
    for(int i = 1; i <= n ; i++)cin >> b[i];
    for(int i =1-n+5000;i<=5000+n-1;i++)
    {
        f[i]=mod;
    }
    for(int i = 1; i <= n ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            pre[i][j]=pre[i-1][j-1]+a[i]*b[j];
            if(f[i-j+5000]==mod){
                maxx=max(maxx,pre[i][j]);
            }
            else maxx=max(maxx,pre[i][j]-f[i-j+5000]);
            minimize(f[i-j+5000],pre[i][j]);

        }
    }
    cout << maxx << endl;
}
int main()
{

    fastio();
    // inti();
    nhap();
}



