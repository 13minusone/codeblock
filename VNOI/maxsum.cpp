/*
    You are watching a brute force code
        CODE IS WRITTEN BY 13MINUSONE A.K.A PVM
*/
#include<bits/stdc++.h>
using namespace std;
#define task "maxsum"
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
const ll maxsize = 400000;
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
ll n,m,sub;
ll a[maxsize+5],pre[maxsize+5],l,r,b;
ll st[maxsize*4+5],maxx[maxsize*4+5],sm=0;
ii sum[maxsize*4+5],minn[maxsize*4+5];
struct nod
{
    ll l,r,m,s;
};
ii p;
void buildpre(int id,int l,int r)
{

    if(l==r)
    {
        sum[id].first=pre[l];
        sum[id].second=l;
        minn[id].first=pre[l-1];
        minn[id].second=l;
        return;
    }
    int m=(l+r)/2;
    buildpre(id*2,l,m);
    buildpre(id*2+1,m+1,r);
    if(sum[id*2+1].first>sum[id*2].first)
    {
        sum[id].first=sum[id*2+1].first;
        sum[id].second=sum[id*2+1].second;
        minn[id].first=minn[id*2].first;
        minn[id].second=minn[id*2].second;
    }
    else
    {
        sum[id].first=sum[id*2].first;
        sum[id].second=sum[id*2].second;
         minn[id].first=minn[id*2+1].first;
        minn[id].second=minn[id*2+1].second;
    }
}
nod  getpre(int id,int l,int r,int u,int v)
{
    if(l>v||r<u)
    {
        return ;
    }
    if(l>=u&&r<=v)
    {
        ll x=sum[id].first,y=sum[id].second,h=minn[id].first,k=minn[id].second;
        nod o;
        o.l=h;
        o.r=k;
        o.s=x;
        o.m=y;
        return o ;
    }
    int m=(l+r)/2;
    nod p=getpre(id*2,l,m,u,v);
    nod k =getpre(id*2+1,m+1,r,u,v);
    ll s1=p.s-p.m;
    ll s=k.s-k.m;
    ll o=k.s-p.m;
    if(s1>s)
    {
        if(o>s1)
        {
            nod neww;
            neww.s=k.s;
            neww.m=p.m;
            neww.l=p.l;
            neww.r=k.r;
        }

    }

}
void build(int id,int l,int r)
{
    if(l==r)
    {
        st[id]=a[l];
        maxx[id]=a[l];
        return;
    }
    int m=(l+r)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    st[id]=min(st[id*2],st[id*2+1]);
    maxx[id]=max(maxx[id*2],maxx[id*2+1]);
}
void  get(int id,int l,int r,int u,int v,int x)
{
    if(l>v||r<u)
    {
        return ;
    }
    if(l>=u&&r<=v)
    {
        if(st[id]>=x)
        {
            cout << l << " "<< r << endl;
            getpre(1,1,n,l,r);
            return ;
        }
    }
    int m=(l+r)/2;
    if(maxx[id*2]>=x&&maxx[id*2+1]>=x)
    {
        get(id*2,l,m,u,v,x);
        get(id*2+1,m+1,r,u,v,x);
    }
    else if(maxx[id*2]>=x)
    {
         get(id*2,l,m,u,v,x);
    }
    else
    {
         get(id*2+1,m+1,r,u,v,x);
    }
}
ll get3(int id,int l,int r,int u,int v,int x)
{

    if(l>v||r<u)
    {
        return 0;
    }
    if(l>=u&&r<=v)
    {
        if(st[id]>=x)
        {
            ll k=pre[r];
            if(k-pre[l-1]>sm)
            {
                sm=k-pre[l-1];
                p.first=l;
                p.second=r;
            }
            return k-pre[l-1];
        }
    }
    int m=(l+r)/2;
    if(maxx[id*2]>=x&&maxx[id*2+1]>=x)
    {
        return max(get3(id*2,l,m,u,v,x),get3(id*2+1,m+1,r,u,v,x));
    }
    else if(maxx[id*2]>=x)
    {
        return get3(id*2,l,m,u,v,x);
    }
    else
    {
        return get3(id*2+1,m+1,r,u,v,x);
    }
}
void nhap()
{
    cin >> sub;
    cin >> n >> m;
    pre[0]=0;
    for(int i = 1 ; i<= n ; i++)
    {
        cin >> a[i];
        pre[i]=pre[i-1]+a[i];
    }
    build(1,1,n);
    buildpre(1,1,n);
    for(int i = 1 ; i<= m ; i++)
    {
        cin >> l >> r >> b;
        sm=0;
        if(sub==1||sub==2)
         {
             get(1,1,n,l,r,b) ;
         }
         else
         {
             if(sub==3)
             {
                get3(1,1,n,l,r,b);
             }
             else
             {
                 sm=0;
             }
         }
         if(sm!=0)
         {
             cout << p.first << " "<< p.second << endl;
         }
         else
         {
             cout << 0 << endl;
         }
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}



