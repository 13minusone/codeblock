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
const ll maxsize = 200000;
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
vector<int>a[maxsize+5];
ll x,y,n,s=0,cha[maxsize+5];
void dfs(int u,int v)
{
    for(int i : a[u])
    {
        if(i==v) continue;
        dfs(i,u);
        if(cha[i]==0&&cha[u]==0)
        {
            s++;
        cha[i]=1;
        cha[u]=1;

        }

    }
}
void nhap()
{
    cin >> n;
    for(int i = 1 ; i < n ; i++)
    {
        cin >> x >> y ;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1,0);
    cout << s << endl;

}
int main()
{

    fastio();
    // inti();
    nhap();
}



