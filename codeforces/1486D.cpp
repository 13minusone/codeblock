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
const ll N = 2e5+5;
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
int n , k;
int a[N],b[N];
bool check(int m)
{
    for(int i = 1; i <= n ; i++)
    {
        if(a[i] >= m)b[i]=b[i-1]+1;
        else b[i]=b[i-1]-1;
    }
    int maxx=b[k],minn=0;
    for(int i = k+1 ; i <= n ; i++)
    {
        minn=min(minn,b[i-k]);
        maxx=max(maxx,b[i]-minn);

    }
    if(maxx > 0)return true;
    return false;
}
void nhap()
{
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++)cin >> a[i];
    int l = 1 , r = n+1,ans=1;
    while(l+1 < r)
    {
        int mid=(l+r)>>1;
        if(check(mid)){
            ans=mid;
            l=mid;
            //cout << mid << endl;
        }else r=mid;

    }
    cout << ans;
}
int main()
{

    fastio();
    // inti();
    nhap();
}




