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

struct node
{
    ll x,y,z,id;
    Node(int u,int v,int c,int i)
    {
        x=u;
        y=v;
        z=c;
        id=i;
    }
};
vector<node>ed[N+5];
bool cmp(node a,node b)
{
    if(a.x==b.x)return a.y<b.y;
    else return a.x < b.x;
}
ii cha[N+5];
    int n,m;

void truyvet()
{
    vector<int>ds;
    int k=n;
    while(k>1)
    {
        ds.push_back(cha[k].second);
        k=cha[k].first;
    }
    for(int i : ds)cout << i << " ";
}
void solve()
{
    priority_queue<node,vector<node>,cmp>pq;
    pq.push(Node(0,0,1,0));
    while(!pq.empty())
    {
        int x=pq.top().x;
        int y=pq.top().y;
        int id=pq.top().id;
        int z=pq.top().z;
        pq.pop();
        if(x==n)
        {
            truyvet();
            return;
        }
        for(node i : ed[z])
        {
            if(cha[i.y].first==0)
            {
                pq.push(Node(x+1,i.z,i.y,i.id));
                cha[i.y]=ii(z,i.id);
            }
        }
    }

}
void nhap()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> x >> y >> z;
        ed[x].push_back(node(0,y,x,i));
        ed[y].push_back(node(0,x,z,i));
    }
    solve();


}
int main()
{

    fastio();
    // inti();
    nhap();
}




