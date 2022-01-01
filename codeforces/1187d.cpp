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
typedef long long ll ;
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll maxsize = 300000;
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
int n,t;
int a[maxsize+5],b[maxsize+5],st[maxsize*4+5];
vector<int>pos[maxsize+5];
void build(int id,int l,int r)
{
    if(l==r)
    {
        st[id]=mod;
        return;
    }
    int m=(l+r)/2;
    build(id*2,l,m);build(id*2+1,m+1,r);
    st[id]=min(st[id*2],st[id*2+1]);
}
void upd(int id,int l ,int r,int v,int val)
{
    if(l==r&&l==v)
    {
        st[id]=val;
        return ;
    }
    int m=(l+r)/2;
    if(m>=v)upd(id*2,l,m,v,val);
    else upd(id*2+1,m+1,r,v,val);
    st[id]=min(st[id*2],st[id*2+1]);
}
ll getm(int id,int l,int r,int u,int v)
{
    if(l>r||u>v||l>v||r<u)return mod;
    if(l>=u&&r<=v)return st[id];
    int m=(l+r)/2;
    return min(getm(id*2,l,m,u,v),getm(id*2+1,m+1,r,u,v));
}
bool ok;
void nhap()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1 ; i <= n ; i++){
                pos[i].clear();
        }
        for(int i = 1 ; i <= n ; i++)
        {
            cin >> a[i];
            pos[a[i]].push_back(i);
        }
        build(1,1,n);
        for(int i = 1 ; i <= n ; i++)
        {
            reverse(all(pos[i]));
            if(!pos[i].empty())upd(1,1,n,i,pos[i].back());
        }
        ok=true;
        for(int i = 1 ; i <= n ; i++)
        {
            cin >> b[i];
           if(ok==false)continue;
            if(pos[b[i]].empty())
            {
                ok=false;
                continue;
            }
            if(getm(1,1,n,1,b[i]-1)<pos[b[i]].back())
            {
                ok=false;
            }
            else
            {
                pos[b[i]].pop_back();
                upd(1,1,n,b[i],pos[b[i]].empty()?mod:pos[b[i]].back());
            }
        }
        if(ok==true)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }

    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}



