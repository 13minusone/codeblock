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
#define task "T1010JUMP"
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
ll s=0;
map<ii,int>d;
int a[105],n,dd[105];
void truyvet(ll i ,ll j,int k)
{
    if(k==n+1)return;
    for(int o =  1 ; o <= n ; o++)
    {
        if(dd[o]==0)
        {

            for(ll  p = i ; p <= i + a[o] ; p++)
            {
                if(d[ii(p,j)]==0)s++,d[ii(p,j)]=1;
            }
            for(ll p = j ; p <= j +a[o] ; p++)
            {
                if(d[ii(i,p)]==0)s++,d[ii(i,p)]=1;
            }
        dd[o]=1;
        truyvet(i+a[o],j,k+1);
        truyvet(i,j+a[o],k+1);
        dd[o]=0;
        }
    }
}
void nhap()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++)cin >> a[i];
    truyvet(0,0,1);
    for(int i = 6 ; i >= 0 ; i--)
    {
        for(int j = 6 ; j >= 0 ; j--) cout << d[ii(i,j)] << " ";
        cout << endl;
    }
    cout << s << endl;
}
int main()
{

    fastio();
     //inti();
    nhap();
}




