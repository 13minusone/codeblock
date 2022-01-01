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
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }
const ll N = 1e5 + 5;
const ll mod =1e12+9;
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
int n,m,st,se,k;
ll d[N][10];
vector<ii>edge[N];
struct iii
{
    ll fi;
    int se,rd;
    iii(ll _fi = 0 , int k=0 ,int n=0)
    {
        fi=_fi;
        se=k;
        rd=n;
    }
    bool operator < (const iii &a)const{
        return fi > a.fi;
    }
};
bool cmp(iii a , iii b)
{
    return a.fi < b.fi;
}
void dijkstra(int u)
{
    priority_queue<iii,vector<iii>>pq;
    pq.push(iii(0,0,u));
    d[u][0]=0;
    while(!pq.empty())
    {
        int x=pq.top().rd;
        ll y = pq.top().fi;
        int cnt = pq.top().se;
        pq.pop();
        if( y >  d[x][cnt])continue;
        for(ii v : edge[x])
        {
            //cout << d[v.fi] << endl;
            if(d[x][cnt] + v.se < d[v.fi][cnt])
            {
                d[v.fi][cnt]=d[x][cnt]+v.se;
                pq.push(iii(d[v.fi][cnt],cnt,v.fi));
            }
            if(cnt < k && d[v.fi][cnt+1] > d[x][cnt])
            {
                d[v.fi][cnt+1] = d[x][cnt];
                pq.push(iii(d[v.fi][cnt+1],cnt+1,v.fi));
            }

        }
    }
}
int u ,v;
ll z;
vector<ii>canh;
void nhap()
{
    cin >> n >> m >> k >> st >> se;
    for(int i = 1 ; i <= m ; i++)
    {
        cin >> u >> v >> z;
        canh.push_back(ii(u,v));
        edge[u].push_back(ii(v,z));
        edge[v].push_back(ii(u,z));
    }
    for(int j = 0 ; j <= k ; j++)for(int i = 1 ; i <= n ; i++)d[i][j]=mod;
    dijkstra(st);
    ll minn=mod;
    for(int i = 1 ; i <= k ; i++)
    {
        minimize(minn,d[se][i]);
    }
    cout << minn;

}
int main()
{

    fastio();
    // inti();
    nhap();
}




