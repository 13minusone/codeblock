#include<bits/stdc++.h>
using namespace std;
#define task "shortestroutes"
#define ll long long
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
typedef pair<ll,ll> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll maxsize = 100000;
const ll maxx = 10000000000000000;
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
ll n,m,x,y,z;
ll d[maxsize+5];
vector<ii>a[maxsize+3];
void dijkstra(int u)
{

    priority_queue<ii,vector<ii>,greater<ii>>pq;
    pq.push({0,1});
    d[1]=0;
    while(!pq.empty())
    {
        int u=pq.top().second;
        ll gt=pq.top().first;
        pq.pop();
        if(d[u]!=gt)continue;
        for(ii i :a[u])
        {

            if(d[i.second]>gt+i.first)
            {
                d[i.second]=gt+i.first;
                pq.push({d[i.second],i.second});
            }
        }
    }
}

void nhap()
{

    cin >> n >> m;
    for(int i = 1 ; i <= m ;i++)
    {
        cin >> x >> y >> z;
        a[x].push_back({z,y});

    }
    for(int i = 1 ; i <=n ;i++)
    {
        d[i]=maxx;
    }
    dijkstra(1);
    //cout << maxx << endl;
    for(int i = 1 ; i <= n ; i++)
    {
        cout << d[i] << " ";
    }
}
int main()
{

    fastio();
    //inti();
    nhap();
}


