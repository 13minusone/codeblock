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
const int block = 400;
int n,q,type;
ll x,y,val;
ll a[N];
multiset<ll>s[block + 5];
ll query(ll l , ll r,ll val)
{
    int lb=l/block;
    int rb=r/block;
    ll minn =mod;
    if(lb == rb)
    {
        Fore(i,l,r)
        if(a[i] >= val)minimize(minn,a[i]);

    return minn;
    }
    for(int i = lb+1;i < rb ; i++)
    {
        auto it = s[i].lower_bound(val);
        if(it!=s[i].end())
        {
            minn=min(minn,*it);
        }
    }
    for(int i = l ; i <= min(n,(lb+1)*block-1) ; i++)
    {
        if(a[i] >=val)minimize(minn,a[i]);
    }
    for(int i = rb*block ; i <= r ; i++)
    {
        if(a[i] >=val)minimize(minn,a[i]);
    }
    return minn;
}
signed main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);cout.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> q;
    Fore(i,1,n){
        scanf("%lld",&a[i]);
        s[i/block].insert(a[i]);
    }
    while(q--)
    {
        cin >> type >> x >> y;
        if(type == 1)
        {
            s[x/block].erase(a[x]);
            a[x]=y;
            s[x/block].insert(y);
        }
        else
        {
            cin >> val;
            ll o= query(x,y,val) ;
            cout << (o == mod ? -1 : o) << endl;
        }
    }
}
