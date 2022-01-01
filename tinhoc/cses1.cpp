#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INT_MAX 100005
ll m,n,arr[INT_MAX];
struct node
{
    ll  val;
    ll t;
};
node st[4*INT_MAX];
void down(int id)
{
    ll v = st[id].t;
    st[id*2].val+=v;
    st[id*2].t+=v;
    st[id*2+1].val+=v;
    st[id*2+1].t+=v;
    st[id].t=0;
    return;
}
void build(int id,int l,int r )
{
    if( l == r)
    {
        st[id].val=arr[l];
        return;
    }

    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id].val=max(st[id*2].val,st[id*2+1].val);
}
void update(int id,int l,int  r, int i,int v,ll res )
{
    if(l > v|| i > r )
    {
        return ;
    }
    if(l >= i && v >= r )
    {
        st[id].val+=res;
        st[id].t +=res;
        return;
    }
    int mid=(l+r)/2;
    down(id);
    update(id*2, l, mid,i, v,res);
    update(id*2+1,mid+1,r,i,v,res);
    st[id].val=max(st[id*2].val,st[id*2+1].val);
}
ll getmaxx(int id,int l, int r,int u)
{




        if(l == u && r==u)
        {
            return st[id].val;

        }
        int mid=(l+r)/2;
        down(id);
        if(mid>u)
        {
          return  getmaxx(id*2,l,mid, u);
        }
        else
        {

            return getmaxx(id*2+1,mid+1,r,u);
        }

}
void inti()
{
    freopen("qumax.inp","r",stdin);
    freopen("qumax.out","w",stdout);
}
void nhap()
{

    cin>>n>>m;
    fu(i,1,n,1)
    {
        cin>>arr[i];
    }
    build(1,1,n);
    fu(i,1,m,1)
    {
        int g,h,r,l;
        cin >> g;
        if(g==1)
        {
            cin >>  h >> r >> l;
            update(1,1,n,h,r,l);
        }
        else
        {
            cin >> h ;
            //cout << 1 <<endl;
            //continue;
            cout << getmaxx(1,1,n,h)<<'\n';
        }
    }
}
int main()
{
    IOS
inti();
    nhap();

}


