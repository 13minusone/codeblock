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
#define task "DUT01EQUA"
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
const ll N = 1e7;
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
int t;
ll a,b;
int  check(ll a,ll b)
{
    ll x=a*a-4*b;
    ll o=sqrt(x);
    if(o*o != x)return 0;
    ll y1=(a+o)/2;
    ll y2=(a-o)/2;
    int s=0;
    if(y1 > 0 && y1 < a && (a+o)%2==0)s++;
    if(y2 > 0 && y2 < a && (a-o)%2==0)s++;
    if(y1 == y2 )s--;
    return s;
}
double x,y;
ll ans=0,u,v;
void nhap()
{
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        vector<int>vec;
        ll x=(a*b)*(a*b);
        ans=0;
        ll i = 2;
        while(x>0)
        {
          if(x%i == 0)
          {
              while(x%i==0)
              {
                  ans+=1;
                  x/=i;
              }
            i++;
          }
        }
        cout << ans << endl;
    }
}
int main()
{

    fastio();
     inti();
    nhap();
}




