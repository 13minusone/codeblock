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
const ll maxsize = 200005;
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
ll st[maxsize*4];
void update(int id ,int l,int r,int x,ll val)
{
    if(l>x||r<x)return ;
    if(l==r&&l==x)
    {
        st[id]=max(st[id],val);
        return ;
    }
    int m=(l+r)/2;
    update(id<<1,l,m,x,val);
    update(id<<1|1,m+1,r,x,val);
    st[id]=max(st[id<<1],st[id<<1|1]);
}
ll get(int id,int l,int r,int u,int v)
{
    if(l>v||r<u)return 0;
    if(l>=u&&r<=v)
    {
        return st[id];
    }
    int m=(l+r)/2;
    return max(get(id<<1,l,m,u,v),get(id<<1|1,m+1,r,u,v));
}
ll h[maxsize],a[maxsize],maxx=0,n;
void nhap()
{
    cin >> n;
    for(int i = 1; i <= n ; i++)
    {
        cin >> h[i];
    }
    for(int i = 1; i <= n ; i++)
    {
        cin >> a[i];
    }
    for(int i = 1 ; i<= n ; i++)
    {
        ll k=get(1,1,n,1,max(h[i]-1,0LL))+a[i];
        update(1,1,n,h[i],k);
    }
    cout << st[1] << endl;
}
int main()
{

    fastio();
    // inti();
    nhap();
}



