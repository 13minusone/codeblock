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
#define task "DUT02STREET"
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
const ll N = 20000 + 5;
const ll mod =1e17+9;
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
int a,b,n;
ll arr[N],sum[N];
ll minn=mod;
void solve(int id,int team,ll s)
{
    if(team >b)return;
    if(id == n+1 && team >= a)
    {
        minn=min(minn,s);
        //cout << minn << " " << id << " "<< team<<endl;
        return;
    }
    for(int j = id;j<= n ;j++)
    {
        //cout <<s << " " << team << " ";
        ll d=s|(sum[j]-sum[id-1]);
        //cout << j << " "<< d << " "<< sum[j] - sum[id-1] << endl;
        solve(j+1,team+1,d);
    }
}
void nhap()
{
    cin >> n >> a >> b;
    sum[0]=0;
    for(int i = 1; i<= n ; i++)
    {
        cin >> arr[i];
        sum[i]=sum[i-1]+arr[i];
    }
    solve(1,0,0);
    cout << minn;
}
int main()
{

    fastio();
    inti();
    nhap();
}




