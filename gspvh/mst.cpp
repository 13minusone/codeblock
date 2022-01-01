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
#define task "mst"
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
int cha[maxsize+5],d[maxsize+5];
struct DSU
{
    int root(int u)
    {
        if(cha[u]==u)return u;
        return cha[u]=root(cha[u]);
    }
    bool join(int u,int v)
    {
        u=root(u),v=root(v);
        if(u==v)return false;
        cha[u]=v;
        return true;
    }
};
struct mi
{
    int x,y,z,id;
    mi(int _u = 0, int _v = 0, int _val = 0, int _id = 0)
    {
        x = _u;
        y = _v;
        z= _val;
        id = _id;
    }
};
vector<mi>ed;
bool cmp(mi a,mi b)
{
    return a.z<b.z;
}
void nhap()
{
    int t,n,m,x,y,z;
    cin >> t;
    cin >> n >> m;
    ed.resize(m);
    for(int i = 0 ; i < m ; i++)
    {
        cin >> x>> y >> z;
        ed[i]=mi(x,y,z,i+1);
    }
    sort(all(ed),cmp);
    for(int i = 1 ; i <= n ; i++)
    {
        cha[i]=i;
    }
    DSU it;
    for(int i = 0 ; i <m;i++)
    {
        int u=ed[i].x;
        int v=ed[i].y;
        if(it.join(u,v)==true)
        {
           cout <<ed[i].id<<" ";
           n--;
        }
        if(n==1)
        {
            break;
        }
    }

}
int main()
{

    fastio();
    // inti();
    nhap();
}




