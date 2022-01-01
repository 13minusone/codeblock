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
const ll mod =1e9+7;
const ll base = 311;
const int block = 488;
int n,type,x,y,q;
ll s[N],a,b;
void addmod(ll &a,ll b)
{
    a+=b;
    if(b >= 0)a%=mod;
    else
    {
        a+=mod*mod;
        a%=mod;
    }
}
void calsum()
{
    for(int i = 1 ;i <= N-5;i++)s[i]=s[i-1]+i;
}
struct IT
{
    int n;
    ll st[4*N],cnt[4*N],lazy[4*N];
    void start(int _n = 0)
    {
        n=_n;
    }
    void push(int id,int l,int mid,int r)
    {
        ll add=cnt[id];
        ll sub=lazy[id];
        addmod(st[id<<1 ],(s[mid]-s[l-1])*add);
        addmod(st[id<<1],(mid-l+1)*sub);
        addmod(st[id<<1|1],(s[r]-s[mid])*add);
        addmod(st[id<<1|1],(r-mid)*sub);
        addmod(cnt[id<<1],add);
        addmod(cnt[id<<1|1],add);
        addmod(lazy[id<<1|1],sub);
        addmod(lazy[id<<1],sub);
        cnt[id]=0;
        lazy[id]=0;
        return;
    }
    void upd(int id,int l,int r,int u,int v,ll a,ll val)
    {
        if(l > v || r < u || l > r)return ;
        if(l >= u && r <= v)
        {
            addmod(st[id],(r-l+1)*val);
            addmod(st[id],(s[r]-s[l-1])*a);
            addmod(cnt[id],a);
            addmod(lazy[id],val);
            return;
        }
        int m=(l+r)>>1;
        push(id,l,m,r);
        upd(id<<1,l,m,u,v,a,val);
        upd(id<<1|1,m+1,r,u,v,a,val);
        st[id]=0;
        addmod(st[id],st[id<<1]+st[id<<1|1]);
    }
    ll get(int id,int l,int r,int u,int v)
    {
        if(l > v || r < u || l > r)return 0;
        if(l >= u && r <= v)return st[id];
        int m=(l+r)>>1;
        push(id,l,m,r);
        ll left=get(id<<1,l,m,u,v);
        ll right=get(id<<1|1,m+1,r,u,v);
        ll ans=0;
        addmod(ans,left+right);
        return ans;
    }
    void upd(int u,int v,ll a,ll val) {
        upd(1,1,n,u,v,a,val);
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
    calsum();
    cin >> n >> q;
    tree.start(n);
    while(q--)
    {
        cin >> type >> x >> y;
        if(type == 1)
        {
            cin >> a >> b;
            tree.upd(x,y,a,-x*a+b);
        }
        else cout << tree.get(x,y) << endl;
    }
}
