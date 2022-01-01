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
const ll N = 1e6 + 5;
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
ll minn[4*N],maxx[4*N],a[N];
void build(int id,int l,int r)
{
    maxx[id]=-mod;
    minn[id]=mod;
    if(l>r)return;
    if(l==r)
    {
        minn[id]=a[l];
        maxx[id]=a[l];
        return;
    }
    int m=(l+r)>>1;
    build(id<<1,l,m);
    build(id<<1|1,m+1,r);
    minn[id]=min(minn[id<<1],minn[id<<1|1]);
    maxx[id]=max(maxx[id<<1],maxx[id<<1|1]);
}
ii check(int id,int l,int r,int u,int v)
{
    if(l > v || r < u || l > r)return ii(-mod,mod);
    if(l >= u && r <= v) return ii(maxx[id],minn[id]);
    int m=(l+r)>>1;
    ii a=check(id<<1,l,m,u,v);
    ii b= check(id<<1|1,m+1,r,u,v);
    return ii(max(a.fi,b.fi),min(a.se,b.se));
}
void nhap()
{
    int n,m,c;
    cin >> n >> m >> c;
    for(int  i = 1; i <= n ; i++)
    {
        cin >> a[i];
    }
    build(1,1,n);
    m=min(m,n);
    bool te=false;
    for(int i = 1;  i <= n-m+1 ; i++)
    {
        ii a=check(1,1,n,i,i+m-1);
        if(a.fi-a.se <= c)
        {
            cout << i << endl;
            te=true;
        }
    }
    if(te==false)cout << "NONE";
}
int main()
{

    fastio();
    // inti();
    nhap();
}




