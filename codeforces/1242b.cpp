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
typedef long long ll ;
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll maxsize = 100000;
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
int x,y,cha[maxsize+5],n,m;
map<ii,int>d;
set<int>s;

void dfs(int u)
{
    vector<int>vec;
    if(s.find(u)!=s.end())
    {
        s.erase(u);
    }
    for(int i : s)
    {
        if(d.count(ii(u,i))==0)
        {
            vec.push_back(i);
        }
    }
    for(int i : vec)
    {
        s.erase(i);
    }
    for(int i : vec)
    {
        dfs(i);
    }
}
void nhap()
{
    cin >> n >> m;
    for(int i = 1 ; i <= m ; i++)
    {
        cin >> x >> y;
        d[make_pair(x,y)]=1;
        d[make_pair(y,x)]=1;
    }
    for(int i = 1 ; i <= n ; i++)
    {
        s.insert(i);
    }
    int ans=0;
    for(int i = 1 ; i<= n ; i++)
    {
        if(s.find(i)!=s.end())
        {
            ans++;
            dfs(i);
        }

    }
    cout << ans-1;
}
int main()
{

    fastio();
    // inti();
    nhap();
}




