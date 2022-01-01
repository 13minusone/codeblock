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
const ll N = 2e5 + 5;
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
ll st[4*N],a[N],lazy[4*N],n,q,s[N],cnt[4*N];
int type,x,y;
void build(int id,int l ,int r)
{
    if(l == r){
        st[id]=a[l];
        return;
    }
    int m = (l+r) >> 1;
    build(id<<1 , l , m);
    build(id<<1|1,m+1,r);
}
void push(int id,int l ,int r)
{
    int t = lazy[id];
    int num=cnt[id];
    int m=(l+r) >> 1;
    lazy[id<<1]+=t;
    st[id<<1]+=(m-l+1)*t;
    lazy[id<<1|1]+=t;
    st[id<<1|1]+=(r-m)*t;
    lazy[id]=0;
}
void upd(int id, int l , int r,int u ,int v,int val)
{
    if(l > r || l > v ||  r < u)return;
    if(l >= u && r <= v)
    {
        lazy[id]+=val;
        st[id]+=(s[r]-s[l-1]-(r-l+1)*val);
        cnt[id]+=1;
        return;
    }
    int m=(l+r) >> 1;
    push(id,l,r);
    upd(id<<1,l,m,u,v,val);
    upd(id<<1|1,m+1,r,u,v,val);
    st[id]=st[id<<1]+st[id<<1|1];
}
ll get(int id,int l,int r,int u,int v)
{
    if(l > r || l > v || r < u)return 0;
    else{
        return st[id];
    }
    int m=(l+r)>>1;
    push(id,l,r);
    return get(id<<1,l,m,u,v)+get(id<<1|1,m,r,u,v);
}
void nhap()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n ; i++)
    {
        s[i]=s[i-1]+i;
    }
    build(1,1,n);
    cin >> q;
    while(q--)
    {
        cin >> type >> x >> y;
        if(type == 1)upd(1,1,n,x,y,y-x+1);
        else cout << get(1,1,n,x,y) << endl;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}




