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
typedef long long ll ;
typedef pair<ll,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B)
{
    A=min(A,B);
}
template<class T> void maximize(T &A, T B)
{
    A=max(A,B);
}
const ll N = 30000;
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
ii a[N+5];
struct queries
{
    int x,y,id;
    ll z;
} que[200005];
bool cmp(queries a,queries b)
{
    return (a.z>b.z);
}
ll x,y,z;

vector<ll>lazy;
int n;
void segment(int _n)
{
    n=_n;
    lazy.assign(4*n+5,0);
}
void upd(int id,int l,int r,int u,int val)
{
    if(l > u|| r < u  )return ;
    if(l==r)
    {
        lazy[id]=val;
        return;
    }
    int m=(l+r)/2;
    upd(id<<1,l,m,u,val);
    upd(id<<1|1,m+1,r,u,val);
    lazy[id]=lazy[id*2]+lazy[id*2+1];
}
ll get(int id,int l,int r,int u,int v)
{
    if(l > v || r < u)return 0;
    if(l>=u&&r<=v)return lazy[id];
    int m=(l+r)/2;
    return (get(id<<1,l,m,u,v)+get(id<<1|1,m+1,r,u,v));
}
ll ans[2000005];
void nhap()
{
    int q;
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i].first ;
        a[i].second=i;
    }
    sort(a+1,a+1+n,greater<ii>());
    a[0]=ii(0,0);
    cin >> q;
    segment(n);
    for(int i = 1 ; i <= q ; i++)
    {
        cin >> x >> y >> z;
        que[i].x=x;
        que[i].y=y;
        que[i].z=z;
        que[i].id=i;
    }
    sort(que+1,que+1+n,cmp);
    int j=1;
    for(int i=1; j<=q;)
    {
        if(a[i].first>que[j].z)
        {
            upd(1,1,n,a[i].second,1);
            i++;
        }
        else
        {
            ans[que[j].id]=get(1,1,n,que[j].x,que[j].y);
            j++;
        }
    }
    for(int i = 1 ; i <=q ; i++)
    {
        cout << ans[i] << endl;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}




