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
const ll N = 1e6+6;
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
    //freopen(task".out","w",stdout);
}
int r[N],l[N];
ll a[N],pref[N];
void nhap()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n ; i++)
    {
        cin >> a[i];
        pref[i]=pref[i-1]+a[i];
    }
    queue<int>qu;
    r[n]=n;
    qu.push(n);
    for(int i = n -1 ; i >= 1; i--)
    {
        while(!qu.empty() && a[qu.front()]<= a[i])qu.pop();
        if(qu.empty())r[i]=i;
        else r[i]=qu.front();
        qu.push(i);
    }
    while(!qu.empty())qu.pop();
    qu.push(1);
    l[1]=1;
    for(int i = 2 ; i <= n; i++)
    {
        while(!qu.empty() && a[qu.front()]<= a[i])qu.pop();
        if(qu.empty())l[i]=i;
        else l[i]=qu.front();
        qu.push(i);
    }
    ll cnt=0;
    ll maxx=0;
    for(int i = n; i>=1 ; i--)
    {
       // cout << i << " "<< l[i] << " "<< r[i] << endl;
       ll x=min(a[l[i]],a[r[i]]);
       cnt+=(x-a[i]);
    }
    cout << cnt << endl;
    //cnt=250850070730;
    for(int i = 1; i <= n ; i++)
    {
        if(l[i]  < i && r[i] > i)continue;
        ll x=cnt;
        if(a[r[i]] >= a[i]+1 && i==l[i])x+=(r[i]-i-1);
        if(a[l[i]] >= a[i]+1 && i==r[i])x+=(i-l[i]-1);
        cout << i << " "<< x<<endl;
        maxx=max(maxx,x);
    }
    cout << maxx ;
}
int main()
{

    fastio();
     inti();
    nhap();
}
