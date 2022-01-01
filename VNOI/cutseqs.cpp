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
ll a[N+5],f[N+5];
void nhap()
{
    ll n,m;
    cin >> n >> m;
    for(int i = 1 ;i <= n ; i++)
    {
        cin >> a[i];
        if(a[i]>m)
        {
            cout << -1 << endl;
            return;
        }
    }
    memset(f,mod,sizeof f);
    f[0]=0;
    for(int i = 1 ; i <= n;i++)
    {
        ll s=0,maxx=0;
        for(int j = i ; j >= 1 ; j--)
        {
            s+=a[j];
            maxx=max(maxx,a[j]);
            if(s>m)break;
            f[i]=min(f[i],f[j-1]+maxx);
        }
    }
    cout << f[n] <<endl;
}
int main()
{

    fastio();
    // inti();
    nhap();
}




