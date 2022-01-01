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
    freopen(task".out","w",stdout);
}
int n,m,l,r;
int maxx[N];
void nhap()
{
    cin >> m;
    for(int i = 1 ; i <= m ; i++)
    {
        cin >> l >> r;
        maximize(maxx[l],r);
    }
    for(int i = 1; i < N ; i++)
    {
        maximize(maxx[i],maxx[i-1]);
    }
    cin >> n;
    int val=1e5;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> l;
        minimize(val,l);
    }
    int ans = 0;
    if(val==1e5 && val == maxx[val] ){cout << 1 << endl;return;}
    while(val < 1e5)
    {
        ans++;
        val=maxx[val];
        if( val == 0){
            cout << -1;
            return;
        }
        if(val == maxx[val] && val!=1e5)
        {
            cout << -1 ;
            return;
        }
    }
    cout << ans ;
}
int main()
{

    fastio();
    // inti();
    nhap();
}




