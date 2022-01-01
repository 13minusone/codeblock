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
#define task "c9"
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
const int block = 488;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void inti()
{
        if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
}
vector<ii>queries[N];
vector<int>edge[N];
int n,q,v,l,k,cnt[N];
set<int>s[N];
struct segtree
{
    vector<int>st;
    int n;
    void reset(int _n)
    {
        n=_n;
        st.assign(4*n,0);
    }
    void update(int id,int l,int r,int x,int val)
    {
        if(l > x || r < x)return;
        if(l == r)
        {
            st[id] += val;
            return;
        }
        int m=(l+r)>>1;
        update(id<<1,l,m,x,val);
        update(id<<1|1,m+1,r,x,val);
        st[id]=st[id<<1]+st[id<<1|1];
    }
    ll get(int id,int l,int r,int u,int v)
    {
        if(l > v || r < u || l > r)return 0;
        if(l >= u && r <= v)return st[id];
        int m=(l+r) >> 1;
        return (get(id<<1,l,m,x,val) + get(id<<1|1,m+1,r,x,val));
    }
    void FIND(int id,int l,int r,)
};
void solve(int u , int pre)
{
    s[cnt[a[u]]].erase(a[u]);
    it.update(cnt[a[u]],-1);
    cnt[a[u]]++;
    s[cnt[a[u]]].push_back(a[u]);
    it.update(cnt[a[u]],1);
    for(int v : edge[u])
    {
        if(v!=pre)
        {
            solve(v,u);
        }
    }
}
void nhap()
{
    scanf("%d%d",&n&q);
    for(int i = 1 ; i <= n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i = 1; i < n ;i++)
    {
        cin >> v;
        edge[v].push_back(i);
    }
    for(int i = 1; i <= q ; i++)
    {
        cin >> v >> l >> k;
        queries[v].push_back({l,k,i});
    }
    solve();
    for(int i =1 ; i <=q ; i++)
    {
        cout << ans[i] << " ":
    }
    cout << "\n";
}
int main()
{

    fastio();
     inti();
    nhap();
}




