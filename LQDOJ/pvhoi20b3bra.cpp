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
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll N = 1e6+6;
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
    //freopen(task".out","w",stdout);
}
int cnt[N],n,q,x;
string s;
int st[4*N],lazy[4*N];
void build(int id,int l,int r)
{
    if(l==r)
    {
        st[id]=cnt[l];
        return;
    }
    int mid=(l+r)>>1;
    build(id<<1,l,mid);build(id<<1|1,mid+1,r);
    st[id]=min(st[id<<1],st[id<<1|1]);
}
void push(int id)
{
    int t=lazy[id];
    lazy[id<<1]+=t;
    st[id<<1]+=t;
    lazy[id<<1|1]+=t;
    st[id<<1|1]+=t;
    lazy[id]=0;
}
void upd(int id,int l,int r,int u,int v,int val)
{
    if(l > r || r < u || l > v )return ;
    if(l >= u && r <= v)
    {
        st[id]+=val;
        lazy[id]+=val;
        return;
    }
    int mid=(l+r)>>1;
    push(id);
    upd(id<<1,l,mid,u,v,val);
    upd(id<<1|1,mid+1,r,u,v,val);
    st[id]=min(st[id<<1],st[id<<1|1]);
}
ll getm(int id,int l,int r,int x)
{
    if(l > x)return x;
    if(l==r){
        if(st[id]>=2)return l;
        else return x;
    }
    int mid=(l+r)>>1;
    push(id);
    if(st[id<<1|1]>=2)
    {
        return min((ll)mid+1,getm(id<<1,l,mid,x));
    }
    else
    {
        return getm(id<<1|1,mid+1,r,x);
    }
}
priority_queue<int,vector<int>,greater<int>>close;
void nhap()
{
    cin >> n >> q;
    cin >> s;
    int sum=0;
    s=' '+s;
    for(int i = 1; i <=n ; i++)
    {
        if(s[i]==')')close.push(i);
        if(s[i]=='(')cnt[i]=cnt[i-1]+1;
        else cnt[i]=cnt[i-1]-1;
    }
    build(1,1,n);
    while(q--)
    {
        cin >> x;
        if(s[x]=='(')
        {
            close.push(x);
            s[x]=')';
            while(s[close.top()]=='(')close.pop();
            s[close.top()]='(';
            cout << close.top() << " ";
            upd(1,1,n,close.top(),x-1,2);
            close.pop();
        }
        else
        {
            upd(1,1,n,x,n,2);
            int h=getm(1,1,n,x);
            cout << h << " ";
            close.push(h);
            upd(1,1,n,h,n,-2);
            s[x]='(';
            s[h]=')';

        }
    }

}
int main()
{

    fastio();
    //inti();
    nhap();
}
