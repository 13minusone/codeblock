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
#define task "1195"
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
#define all(x) x.begin(),x.end()
#define endl '\n'
typedef long long ll ;
typedef pair<ll,ll> ii;
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
const ll mod =1e15+9;
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
ll  n,m,u,v,c;
vector<ii>edge1[N+5],edgen[N+5];
ll h1[N+5],hn[N+5];
void dijsktra(ll f[],vector<ii>edge[],int s)
{
    for(int i = 1 ;i <=n ; i++)f[i]=1e15+9;
    f[s]=0;
    priority_queue<ii,vector<ii>,greater<ii>>pq;
    pq.push(ii(s,0));
    while(!pq.empty())
    {
       // cout << u << endl;
        //ll u=pq.top().first;
        ll du=pq.top().second;
        pq.pop();
        if(f[u]!=du)continue;
        for(ii i : edge[u])
        {
            //cout << i.first <<endl;
            if(f[i.first]>f[u]+i.second)
            {
                f[i.first]=f[u]+i.second;
                pq.push(ii(i.first,f[i.first]));
            }
        }
    }

}
struct canh
{
    ll u,v,c;
    canh(ll x,ll y,ll z)
    {
        u=x;
        v=y;
        c=z;
    }
};
vector<canh>cad;
void nhap()
{
    cin >> n >> m;
    for(int i = 1 ; i <= m ; i++)
    {
        cin >> u >> v >> c;
        //cout << u <<" "<< v <<" "<< c << endl;
//return;
        cad.push_back(canh(u,v,c));
        edge1[u].push_back(ii(v,c));
        edgen[v].push_back(ii(u,c));
    }
    dijsktra(h1,edge1,1);
    dijsktra(hn,edgen,n);
    //cout << h1[3] << endl;
  // return;
    ll s=1e15;
    for(int i = 0 ; i <m ; i++)
    {
        s=min(s,(h1[cad[i].u]+hn[cad[i].v]+cad[i].c/2));
        //cout << s << endl;
    }
    cout << s << endl;
}
int main()
{

    fastio();
    inti();
    nhap();
}

