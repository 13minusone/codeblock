#include<bits/stdc++.h>
using namespace std;

#define fu(i,a,b,c) for(int  i = a ; i <=b ;i+=c)
#define fd(i,a,b,c) for(int  i = a ; i >=b ;i-=c)

typedef long long ll;
const ll maxsize = 60000;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
ll st[maxsize*5+5];
ll n;
ll a[maxsize+1];
ll get(int id,int l ,int r,int u,int v)
{
    if(l > v || r < u )
    {
        return 0;
    }
    if(l >= u && r <= v)
    {
        return st[id];
    }
    int mid=(l+r)/2;
    return (get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v));
}
void update(int id,int l ,int r,int v)
{
    if(l > v || r < v)return;
    if(l==r )
    {
        st[id]++;
        return ;
    }
    int mid=(l+r)/2;

        update(id*2,l,mid,v);


    update(id*2+1,mid+1,r,v);

    st[id]=st[id*2]+st[id*2+1];
}
void nhap()
{
    cin >> n;
    ll maxx=0;
    fu(i,1,n,1)
    {
        cin >> a[i];
        maxx=max(maxx,a[i]);
    }
    ll d=0;
    update(1,1,maxx,a[n]);
    fd(i,n-1,1,1)
    {
        ll  t= get(1,1,maxx,1,a[i]-1);
        d=d+t;
        //cout << i << " " << t <<endl;
        update(1,1,maxx,a[i]);
    }
cout << d;
}
void inti()
{
    freopen(".inp","r",stdin);
    freopen(".our","w",stdout);
}
int main()
{
    fastio();
    nhap();
}
