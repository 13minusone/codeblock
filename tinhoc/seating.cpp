#include<bits/stdc++.h>
using namespace std;
#define task "seating"
#define ll long long
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
typedef pair<int,int> ii;
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
const ll maxsize = 500000;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void inti()
{
    freopen(task".in","r",stdin);
    freopen(task".out","w",stdout);
}
struct node
{
    int s,t;
} st[maxsize*4+5];
void lazy(int id,int l,int r)
{
    int k=st[id].t;
    int mid=(l+r)/2;
    st[id<<1].s=k*(mid-l+1);
    st[id<<1|1].s=k*(r-mid);
    st[id<<1|1].t=st[id<<1].t=k;
    st[id].t=0;
}
void build(int id,int l,int r)
{
    if(l==r)
    {
        st[id].s=1;
        st[id].t=1;
        return;
    }
    int m=(l+r)/2;
    build(id<<1,l,m);
    build(id<<1|1,m+1,r);
    st[id].s=st[id<<1].s+st[id<<1|1].s;

}
void upd(int id,int l,int r,int u)
{
    if(r-l+1-st[id].s==u)
    {
        st[id].s=0;
        st[id].t=0;
        return ;
    }
    if(r-l+1-st[id].s<u)
    {
        return;
    }
    else
    {
        int mid=(l+r)/2;
        int g=mid-l+1-st[(id<<1)].s;
        lazy(id,l,r);
        if(g!=0)
        {
            if(g>=u)
            {
                upd(id<<1,l,mid,u);
            }
            else
            {
                upd((id<<1),l,mid,g);
                upd((id<<1|1),mid+1,r,u-g);
            }
        }
        else
        {
            upd((id<<1|1),mid+1,r,u);
        }
        st[id].s=st[id<<1].s+st[id<<1|1].s;
    }

}
void xoa(int id,int l,int r,int u,int v)
{
    if(l>v||r<u)return;
    if(l>=u&&r<=v)
    {
        st[id].s=1;
        st[id].t=1;
        return;
    }
    lazy(id,l,r);
    int mid=(l+r)/2;
    xoa(id<<1,l,mid,u,v);
    xoa(id<<1|1,mid+1,r,u,v);
    st[id].s=st[id<<1].s+st[id<<1|1].s;
}
char c;
int l,r,s=0,n,m;
void nhap()
{
    cin >> n >> m;
    build(1,1,n);
    for(int i = 1; i<= m ; i++)
    {
        cin >> c >> l;
        if(c=='A')
        {
            cout << st[1].s << endl;
            if(st[1].s>=l)
            {
                upd(1,1,n,l);
            }
            else
            {
                s++;
            }
        }
        else
        {
            cin >> r;
            xoa(1,1,n,l,r);
        }
    }
    cout << s;
}
int main()
{

    fastio();
     //inti();
    nhap();
}



