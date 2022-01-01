/*
    You are watching a brute force code
        CODE IS WRITTEN BY 13MINUSONE
*/
#include<bits/stdc++.h>
using namespace std;
#define task "mst"
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
const ll maxsize = 500000;
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
struct node
{
    int x,y,z,id;
}a[maxsize+5];
int cha[maxsize+5];
struct Dsu
{
    ll root(int i)
    {
        if(cha[i]==i)
        {
            return i;
        }
        else
        {
            return cha[i]=root(cha[i]);
        }
    }
    bool join(int u,int v)
    {
        u=root(u),v=root(v);
        if(u==v)return true;
        cha[v]=u;
        return false;
    }
}dsu;
vector<node>vec;
bool cmp(node a,node b)
{
    return a.z<b.z;
}
ll kt[maxsize+5],cnt=0,num[maxsize+5],low[maxsize+5];
vector<ii>ed[maxsize+5];
void dfs(int u,int pre)
{
    num[u]=low[u]=++cnt;
    for(ii i : ed[u])
    {
        if(i.second==pre)continue ;
        if( num[i.first]==0)
        {
            dfs(i.first,i.second);
            low[u]=min(low[u],low[i.first]);
            if(low[i.first]==num[i.first])
            {
                kt[i.second]=3;
            }
        }
        else
        {
            low[u]=min(low[u],num[i.first]);
        }
    }
}
void sol(vector<node> &vec)
{
    if(vec.empty())return;
    for(int i = 0 ; i<SZ(vec);i++)
    {
        vec[i].x=dsu.root(vec[i].x);
        vec[i].y=dsu.root(vec[i].y);
        ed[vec[i].x].clear();ed[vec[i].y].clear();
        num[vec[i].x]=num[vec[i].y]=0;
    }
    for(int i  = 0 ; i < SZ(vec); i++)
    {
        if(vec[i].x==vec[i].y)
        {
            kt[vec[i].id]=1;
        }
        else
        {
            kt[vec[i].id]=2;
            ed[vec[i].x].push_back({vec[i].y,vec[i].id});
            ed[vec[i].y].push_back({vec[i].x,vec[i].id});
        }
    }
    for(int i = 0 ; i < SZ(vec);i++)
    {
        if(num[vec[i].x]==0)
        {
            dfs(vec[i].x,-1);
        }
    }
    for(int i = 0 ; i < SZ(vec);i++)
    {
            dsu.join(vec[i].x,vec[i].y);
    }
    vec.clear();
}
int n,m,t;
void nhap()
{
    cin >> t;
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
    {
        cha[i]=i;
    }
    for(int i = 1 ; i <= m ; i++)
    {
        cin >> a[i].x >> a[i].y >> a[i].z ;
         a[i].id=i;
    }
    sort(a+1,a+1+m,cmp);
    for(int i = 1 ; i <= m ; i++)
    {
        if(!vec.empty()&&vec.back().z==a[i].z)
        {
            //cout << i << endl;
            vec.push_back(a[i]);
        }
        else
        {
            sol(vec);
            //cout << i << endl;
            vec.push_back(a[i]);
        }

    }
    sol(vec);
    for(int i = 1 ; i <= m ; i++)
    {
        //cout << i << " " << kt[i] << endl;
        if(kt[i]==1||kt[i]==2)cout << "No" << " ";
        if (kt[i]==3)cout << "Yes" << " ";
    }
}
int main()
{

    fastio();
     //inti();
    nhap();
}



