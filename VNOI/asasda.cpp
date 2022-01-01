#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a),_b=(b);i<_b;++i)

using namespace std;
const int maxn = 200001;
typedef long long ll;
ll a[maxn];
int n,q;
void enter()
{
    cin>>n>>q;
    _for(i,1,n+1) cin>>a[i];
}
struct node
{
    ll val,T;
};
node seg[maxn*4];
void push_seg(int st,int l,int r)
{
    ll t = seg[st].T;
    seg[st].T = 0;
    if (l<r)
    {
        int mid=(l+r)>>1;
        seg[st*2].val += (ll(mid - l+1)*t);
        seg[st*2+1].val += (ll(r - mid)*t);
        seg[st*2].T += t;
        seg[st*2+1].T += t;
    }
}
void update_seg(int l,int r,int u,int v,int st,ll val)
{
    if (u<=l && r<=v)
    {
        seg[st].val += (ll(r - l +1)*val);
        seg[st].T += val;
    }
    else if (l>v || r<u) return;
    else
    {
        push_seg(st, l, r);
        int mid = (l+r)>>1;
        update_seg(l,mid,u,v,st*2, val);
        update_seg(mid+1,r,u,v,st*2+1,val);
        seg[st].val = seg[st*2].val + seg[st*2+1].val;
    }
}
ll _get_seg(int l,int r,int u,int v,int st)
{
    if (u<=l && r<=v) return seg[st].val;
    else if (l>v || r<u) return 0;
    else
    {
        push_seg(st, l ,r);
        int mid = (l+r)>>1;
        return _get_seg(l, mid, u, v, st*2) + _get_seg(mid+1, r, u, v, st*2+1);
    }
}
node IT[maxn*4];
#define SUM_RANGE(i,j) ((i+j)*(j-i+1)/2)
void push_IT(int st,int l,int r)
{
    ll t = IT[st].T;
    IT[st].T = 0;
    if (l<r)
    {
        int mid = (l+r)>>1;
        IT[st*2].val += (SUM_RANGE(ll(l), ll(mid))*t);
        IT[st*2+1].val += (SUM_RANGE(ll(mid+1), ll(r))*t);
        IT[st*2].T += t;
        IT[st*2+1].T += t;
    }
}
void update_IT(int l,int r,int u,int v,int st,ll val)
{
    if (u<=l && r<=v)
    {
        IT[st].val += (SUM_RANGE(ll(l), ll(r))*val);
        IT[st].T += val;
    }
    else if (l>v || r<u) return;
    else
    {
        push_IT(st, l, r);
        int mid = (l+r)>>1;
        update_IT(l,mid,u,v,st*2, val);
        update_IT(mid+1,r,u,v,st*2+1,val);
        IT[st].val = IT[st*2].val + IT[st*2+1].val;
    }
}
ll _get_IT(int l,int r,int u,int v,int st)
{
    if (u<=l && r<=v) return IT[st].val;
    else if (l>v || r<u) return 0;
    else
    {
        push_IT(st, l ,r);
        int mid = (l+r)>>1;
        return _get_IT(l, mid, u, v, st*2) + _get_IT(mid + 1, r, u, v, st*2+1);
    }
}
ll pre[maxn];
ll query(int l,int r)
{
    cout << _get_seg(1,n,l,r, 1) << " "<< _get_IT(1,n, l, r,1) << endl;
    return pre[r] - pre[l-1] - _get_seg(1,n,l,r, 1) + _get_IT(1,n, l, r,1);
}
void solve()
{
    _for(i,1,n+1)
    {
        pre[i] = pre[i-1] + a[i];
    }
    int l,r,tv;
    _for(i,0,q)
    {
        cin>>tv>>l>>r;
        if (tv==1)
        {
            update_seg(1, n, l, r, 1, l-1);
            update_IT(1, n, l, r, 1, 1);
        }
        else
        {
            cout<<query(l,r)<<"\n";
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    enter();
    solve();
}
