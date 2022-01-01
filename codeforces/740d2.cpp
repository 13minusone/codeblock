/*
🛸　　　 　🌎　°　　🌓　•　　.°•　　　🚀 ✯
　　　★　*　　　　　°　　　　🛰 　°·　　                           🪐
.　　　•　° ★　•  ☄
______________________________________________________
    You are watching a code chep
        CODE kh dc WRITTEN BY 13MINUSONE
    This is a code chep
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
typedef long long ll ;
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll maxsize = 4000000+5;
const ll mod =1e9+9;
const ll base = 311;
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
int n,m;
int p[maxsize];
int g[maxsize];
void them(int &t, int c)
{
    t+=c;
    if(t>=m)
    {
        t-=m;
    }
}
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
void nhap()
{
    cin>>n>>m;
    p[n]=1;g[n]=1;
    for(int i=n-1;i>=1;i--)
    {
        them( p[i], ( g[i+1] - g[n+1] + m) % m);
        for(int k=2;k*i<=n;k++)
        {
            int le = i*k, ri = min(n,(i+1)*k-1);
            if(le > ri)
            {
                continue;
            }
            int ans = (g[le] - g[ri+1] + m ) % m ;
            them(p[i], ll(ans % m ) );
        }
        g[i] = g[i+1];
        them( g[i], p[i]);
    }
    cout<<p[1];
}
int main()
{
    fastio();
    //inti();
    nhap();
}
