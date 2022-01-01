#include<bits/stdc++.h>
using namespace std;
#define task "SUM216MUSR"
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
const ll maxsize = 1000000;
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
ll a[maxsize+5],st[4*maxsize+5];
void build(int id,int l ,int r)
{
    if(l==r)
    {
        st[id]=a[l];
        return;
    }
    int m=(l+r)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    st[id]=st[id*2]+st[id*2+1];
}
ll sum(int id,int l,int r,int x,int y)
{
    if(l>=x&&r<=y )
    {
        return st[id];
    }
    if(r<x||l>y)
    {
        return 0;
    }
    int m=(l+r)/2;
    return (sum(id*2,l,m,x,y)+sum(id*2+1,m+1,r,x,y));
}
void nhap()
{
    ll n,k,x,y,maxx=0,s=0;
    cin >> n >> k;
    for(int i = 1 ; i<= n ; i++)
    {
        cin >> x >> y;
        a[y]+=x;
        maxx=max(maxx,y);
    }
    build(1,1,maxx);
    for(int i = 1 ; i<= maxx ; i++)
    {
        s=max(s,sum(1,1,maxx,max((ll)0,i-k),min((ll)maxx,i+k)));
    }
    cout << s << endl;

}
int main()
{

    fastio();
    inti();
    nhap();
}



