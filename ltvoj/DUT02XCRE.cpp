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
#define task "DUT02XCRE"
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
const ll mod =1e9+9;
const ll base = 311;
const int block = 488;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void inti()
{
        if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
}
const int N=3e4+1;
struct canh
{
    int x, w,d;
    canh(const int &x, const int &w, const int &d): x(x), w(w), d(d) {}
};
int s,e;
int n,m;
set<int> a[N];
int id,d;
queue<canh> qu;
bitset<N> bit[N];


void jump(int u,int t,int d)
{
    if(u < 0 || n <= u || bit[u][t]) return;
    bit[u][t] = 1;
    if(u == e)
    {
        cout << d;
        exit(0);
    }
    qu.push({u, t, d});
}
void nhap()
{
     cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        cin >> id >> d;
        if(i==0) s=id;
        else if(i==1) e=id;
        a[id].insert(d);
    }
    if(s==e)
    {
        cout << 0 ;
    }
    else
    {
        for(int t: a[s])
        {
            qu.push({s, t, 0});
            bit[s][t]=1;
        }
        a[s].clear();
        while(!qu.empty())
        {
            auto [x, w, d] = qu.front();
            qu.pop();
            for(int new_w: a[x])
                if(!bit[x][new_w])
                {
                    bit[x][new_w] = 1;
                    qu.push({x, new_w, d});
                }
            a[x].clear();
            jump(x - w, w, d + 1);
            jump(x + w, w, d + 1);
        }
        cout << -1;
    }
}
int main()
{

    fastio();
     inti();
    nhap();
}
