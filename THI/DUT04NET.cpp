//CODE IS WRITTEN BY 13MINUSONE
#include<bits/stdc++.h>
using namespace std;
#define task "DUT04NET"
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
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b) : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b) : 0); }
const ll N = 1e5 + 5;
const ll mod =1e9+9;
const ll base = 311;
const int block = 488;
int n , m,cha[N],x,y;
int root(int u)
{
    return (cha[u] < 0 ? u : ( cha[u] = root(cha[u]) ));
}
void join(int x,int y)
{
    x=root(x);
    y=root(y);
    if(x == y)return ;
    if(cha[y] < cha[x])swap(x,y);
    cha[x]+=cha[y];
    cha[y]=x;
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
    cin >> n >> m;
    memset(cha,-1,sizeof cha);
    Fore(i,1,m)
    {
        cin >> x >> y;
        join(x,y);
    }
    int minn=0;
    Fore(i,1,n)
    {
        if(cha[i] <0)
        {
            minimize(minn,cha[i]);
        }
    }
    cout << -minn;
}
