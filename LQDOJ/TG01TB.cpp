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
#define task "TG01TB"
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
ii a[51];
ll x,m,n,k,y;
void nhap()
{
    cin >> m >> n >> k;
    for(int i = 1 ; i <= k ; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    ll su=0;
    for(int i = 1; i <= m ;i++)
    {
        cin >> x>> y;
        ll maxx=mod;
        for(int i = 1 ;i <= k ; i++)
        {
            ll s=0;
            if(a[i].first> x || a[i].second < x)
            {
               s+=min(abs(a[i].first-x),abs(a[i].second-x));
            }
             if(a[i].first> y || a[i].second < y)
            {
               s+=min(abs(a[i].first-y),abs(a[i].second-y));
            }
            maxx=min(maxx,s);
        }
        su+=maxx;
    }
    cout << su << endl;
}
int main()
{

    fastio();
    inti();
    nhap();
}




