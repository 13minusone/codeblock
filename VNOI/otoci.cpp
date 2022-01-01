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
typedef long long ll ;
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll N = 30000;
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
ll cha[N+5],a[N+5],dd[N*10+5],hi[N+5],up[N+5][20],Log=18;
ll sta[N+5],fin[N+5],cnt=0,sum[N*10+5];
vector<int>ed[N+5];
ll root(int u)
{
    if(u==cha[u])return u;
    else return cha[u]=root(cha[u]);
}
bool check(int u,int v)
{
    u=root(u),v=root(v);
    if(u==v)return false;
    cha[v]=u;
    return true;
}
void dfs(int u,int v)
{
    cnt++;
    sta[u]=cnt;
   // cout <<u<< " "<< cnt << endl;
    for(int i : ed[u])
    {
        if(i==v)continue;
        hi[i]=hi[u]+1;
        up[i][0]=u;
        dfs(i,u);
    }
    fin[u]=cnt;
    //cout << cnt << endl;;
}
struct IT
{
    vector<ll>st,lazy;
    int n;
    void segment(int _n)
    {
        n=_n;
        lazy.assign(4*n+5,0);
    }
    void upd(int id,int l,int r,int x,int val)
    {
        if(l > r|| r < x || l > x )return ;
        if(l==r){
            lazy[id]+=val;
            return;
        }
        int m=(l+r)/2;
        upd(id<<1,l,m,x,val);
        upd(id<<1|1,m+1,r,x,val);
        lazy[id]=lazy[id*2]+lazy[id*2+1];
    }
    ll get(int id,int l,int r,int u,int v)
    {
        if(l > v|| r < u)return 0;
        if(l>=u&&r<=v)return lazy[id];
        int m=(l+r)/2;
        return get(id<<1,l,m,u,v)+get(id<<1|1,m+1,r,u,v);
    }
    void upd(int x,int c)
    {
        upd(1,1,n,x,c);
    }
    ll get(int l,int r)
    {
        return get(1,1,n,l,r);
    }
};
int lca(int u,int v)
{
    //if(u==v)return u;
    if(hi[u]<hi[v])swap(u,v);
    for(int i = Log ; i >= 0 ; i--)
    {
        if(hi[up[u][i]]>=hi[v]) u=up[u][i];
    }
    if(u==v)return u;
    for(int i = Log; i>=0 ; i--)
    {
        if(up[u][i]!=up[v][i])
        {
            u=up[u][i];
            v=up[v][i];
        }
    }
    return up[u][0];
}
struct queries
{
    string s;
    int u, v;
};
queries que[N*10+5];
void nhap()
{
    int n,q;
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        cha[i]=i;
    }
    cin >> q;
    string s;
    int u,v;
    memset(dd,0,sizeof dd);
    for(int i = 1 ; i <= q ; i++){
        cin >> s >> u >> v;
        que[i].s=s;
        que[i].u=u;
        que[i].v=v;
        if(s=="excursion"){
            u=root(u),v=root(v);
            if(u==v)dd[i]=1;
        }
        else if(s=="bridge"){
                if(check(u,v)==true){
                    ed[u].push_back(v);
                    ed[v].push_back(u);
                    dd[i]=1;
                }
            }
            else{
                dd[i]=a[u];
                a[u]=v;
            }
        }
    //hi[1]=1;
    for(int i = 1 ; i <= n ; i++)
    {
        if(sta[i]==0)dfs(i,-1);
    }
    up[1][0]=1;
    for(int i = 1 ; i <= Log ; i++) for(int j = 1 ; j <= n ; j++) up[j][i]=up[ up[j][i-1] ][i-1];
    //cout << lca(2,3) << endl;
    IT tree;
    tree.segment(n);
    //cout <<cnt << endl;
    for(int i = 1 ; i <= n ; i++){
            tree.upd(sta[i],a[i]);
            tree.upd(fin[i]+1,-a[i]);
    }
    for(int i = q ; i >=1; i--){
        if(que[i].s=="excursion"){
            if(dd[i]==1){
                int f;
                f=lca(que[i].u,que[i].v);
                sum[i]=tree.get(1,sta[que[i].u])+tree.get(1,sta[que[i].v])-2*tree.get(1,sta[f])+a[f];
            }
        }
        else{
            if(que[i].s=="penguins")
            {
                tree.upd(sta[que[i].u],dd[i]-que[i].v);
                tree.upd(fin[que[i].u]+1,-dd[i]+que[i].v);
                a[que[i].u]=dd[i];
            }
        }
    }
    for(int i = 1 ; i <= q; i++){
        if(que[i].s=="excursion"){
            if(dd[i]==0)cout << "impossible" << endl;
            else cout << sum[i] << endl;
        }
        else{
            if(que[i].s=="bridge"){
                if(dd[i]==1)cout << "yes" <<endl;
                else cout << "no" << endl;
            }
        }
    }

}
int main()
{

    fastio();
    // inti();
    nhap();
}




