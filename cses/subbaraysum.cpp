#include<bits/stdc++.h>
using namespace std;
#define task "select"
#define ll long long
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll maxsize = 200000;
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
struct node{
    ll l, r, g,s;
}st[maxsize*4+5];
 ll a[maxsize+5];
 node sum(node a,node b)
 {
     ll lmax=max(a.l,a.s+b.l);
     ll rmax=max(b.r,a.r+b.s);
     ll gmax=max({a.g,b.g,a.r+b.l});
     ll smax=a.s+b.s;
     node t;
     t.l=lmax;
     t.r=rmax;
     t.g=gmax;
     t.s=smax;
     return t;
 }
 void build(int id,int l,int r)
 {
     if(l==r)
     {
         st[id]={max(0ll,a[l]),max(0ll,a[l]),max(0ll,a[l]),a[l]};
         return;
     }
     int mid=(l+r)/2;
     build(id<<1,l,mid);
     build(id<<1|1,mid+1,r);
     st[id]=sum(st[id<<1],st[id<<1|1]);
 }
 void upd(int id,int l,int r,int x,ll val)
 {
     if(x<l||x>r)return;
     if(l==x&&r==x)
     {
         st[id]={max(0ll,val),max(0ll,val),max(0ll,val),val};
        return;
     }
     int mid=(l+r)/2;

     upd(id<<1,l,mid,x,val);
     upd(id<<1|1,mid+1,r,x,val);
     st[id]=sum(st[id<<1],st[id<<1|1]);
     return ;

 }

void nhap()
{
    ll n , m,l,r;
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }
    build(1,1,n);
    for(int i = 1 ; i <= m ; i++)
    {
        cin >> l >> r;
        upd(1,1,n,l,r);
        cout << st[1].g << endl;
    }

}
int main()
{

    fastio();
    // inti();
    nhap();
}



