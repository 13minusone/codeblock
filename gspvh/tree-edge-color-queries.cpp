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
#define task "tree-edge-color-queries"
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
template<class T> void minimize(T &A, T B)
{
    A=min(A,B);
}
template<class T> void maximize(T &A, T B)
{
    A=max(A,B);
}
const ll N = 1e5;
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
int t,u,v,c,n;
map<int,int>dd[3*N+5];
struct node
{
    int u,v,c;
    node(int x=0,int y=0,int z=0)
    {
        u=x;
        v=y;
        c=z;
    }
};
vector<node>vec;
void nhap()
{
    cin >> t;
    cin >> n;
    vec.push_back(node(0,0,0));
    for(int i = 1 ; i < n ; i++)
    {
        cin >> u >> v >> c;
        vec.push_back(node(u,v,c));
        dd[u][0]++;
        dd[v][0]++;
    }
    ll ans=1;
    for(int i = 1 ; i <n;i++)
    {
        int x=vec[i].u,y=vec[i].v,z=vec[i].c;
        dd[x][0]--;
        dd[y][0]--;
        if(dd[x][0]>0)
        {
            ans++;
        }
        if(dd[y][0]>0)ans++;
        if(dd[y][z]>0)ans--;
        if(dd[x][z]>0)ans--;
        dd[x][z]++;
        dd[y][z]++;
    }
    cout <<ans << " ";
    int q,p,e;
    cin >> q;
    while(q--)
    {
        cin >> p >> e;
        if(vec[p].c==e)
        {
            cout << ans << " ";
            continue;
        }
        int x=vec[p].u,y=vec[p].v,z=vec[p].c;
        dd[x][z]--;
        dd[y][z]--;
        if(dd[x][e]>0)
        {
            ans--;
        }
        if(dd[y][e]>0)ans--;
        if(dd[y][z]>0)ans++;
        if(dd[x][z]>0)ans++;
        dd[x][e]++;
        dd[y][e]++;
        vec[p].c=e;
        cout << ans << " ";

    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}




