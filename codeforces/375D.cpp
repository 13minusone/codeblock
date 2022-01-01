//CODE IS WRITTEN BY 13MINUSONE
#include<bits/stdc++.h>
using namespace std;
#define task "c9"
#define SZ(c) (c).size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define __builtin_popcount __builtin_popcountll
#define all(x) (x).begin(),(x).end()
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define fi first
#define se second
#define For(i,l,r) for(int i = l ; i < r ;i++)
#define Fore(i,l,r) for(int i = l ; i <= r ; i++)
#define Ford(i,l,r) for(int i = l ; i >= r ; i--)
typedef long long ll ;
typedef pair<int,int> ii;
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
const ll N = 1e5 + 5;
const ll mod =1e9+9;
const ll base = 311;
const int block = 320;
vector<int>edge[N];
int n,q,x,y,sta[N],fin[N],cnt[N],s,a[N],node[N],f[N],ans[N];
struct data
{
    int id, l, r, val;
    data(int _id=0,int _l=0,int _r=0,int _val =0)
    {
        id=_id;
        l=_l;
        r=_r;
        val=_val;
    }
};
bool cmp(data a,data b)
{
    if(a.l/block != b.l/block)return a.l/block < b.l/block;

    return a.r < b.r;
}
vector<data>vec;
void dfs(int u,int pre)
{
    sta[u]=++s;
    node[s]=u;
    for(auto v : edge[u])if(v!=pre){
        dfs(v,u);
    }
    fin[u]=s;
}
void add(int x)
{
    cnt[a[node[x]]]++;
    f[cnt[a[node[x]]]]++;
}
void sub(int x)
{
    f[cnt[a[node[x]]]]--;
    cnt[a[node[x]]]--;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> q;
    Fore(i,1,n)cin >> a[i];
    For(i,1,n)
    {
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    dfs(1,-1);
    Fore(i,1,q)
    {
        cin >> x >> y;
        vec.push_back(data(i,sta[x],fin[x],y));
    }
    sort(all(vec),cmp);
    int ml=0,mr=-1;
    for(auto i : vec)
    {
        while(ml <i.l)sub(ml),ml++;
        while(ml >i.l)ml--,add(ml);
        while(mr >i.r)sub(mr),mr--;
        while(mr <i.r)mr++,add(mr);
        ans[i.id]=f[i.val];
    }
    Fore(i,1,q) cout << ans[i] << '\n';
}
