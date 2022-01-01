//CODE IS WRITTEN BY 13MINUSONE
#include<bits/stdc++.h>
using namespace std;
#define task "c9"
#define SZ(c) (c).size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define __builtin_popcount __builtin_popcountll
#define all(x) (x).begin(),(x).end()
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define fi first
#define se second
#define For(i,l,r) for(int i = l ; i < r ;i++)
#define Fore(i,l,r) for(int i = l ; i <= r ; i++)
#define Ford(i,l,r) for(int i = l ; i >= r ; i--)
typedef long long ll ;
typedef pair<int,int> ii;
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
const ll N = 1e5 + 5;
const ll mod =1e9+9;
const ll base = 311;
const int block = 488;
int n,q,type;
ll x,y;
ll a[N];
struct IT
{
    int n;
    vector<ll>st;
    void start(int _n=0)
    {
        n=_n;
        st.assign(4*n+5,0);
        return;
    }
    void build(int id ,int l,int r)
    {
        if(l==r)
        {
            st[id]=a[l];
            return;
        }
        int m=(l+r)>>1;
        build(id<<1,l,m);
        build(id<<1|1,m+1,r);
        st[id] = st[id<<1]+st[id<<1|1];
    }
    void upd(int id,int l,int r,ll x,ll val)
    {
        if(l > x || r < x || l > r)return ;
        if(l == r)
        {
            st[id]=val;
            return;
        }
        int m=(l+r)>>1;
        upd(id<<1,l,m,x,val);
        upd(id<<1|1,m+1,r,x,val);
        st[id]=st[id<<1]+st[id<<1|1];
    }
    ll get(int id,int l,int r,ll u,ll v)
    {
        if(l > v || r < u || l > r)return 0;
        if(l >= u && r <= v)return st[id];
        int m=(l+r)>>1;
        return ll(get(id<<1,l,m,u,v)+get(id<<1|1,m+1,r,u,v));
    }
    void upd(int u,int v) {
        upd(1,1,n,u,v);
    }
    ll get(int u,int v){
        return get(1,1,n,u,v);
    }
};
IT tree;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> q;
    tree.start(n);
    while(q--)
    {
        cin >> type >> x >> y;
        if(type == 1)tree.upd(x,y);
        else cout << tree.get(x,y) << endl;
    }

}
