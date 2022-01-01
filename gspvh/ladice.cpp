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
#define task "ladice"
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
ll cha[3*N+5];
ll root(int u)
{
    if(cha[u]<=0)return u;
    else return cha[u]=root(cha[u]);
}
bool join(int u,int v)
{
    u=root(u),v=root(v);
    if(u==v)
    {
        if(cha[u]<0)
        {
            ++cha[u];
            return true;
        }
        return false;
    }
    int dem=cha[v]+cha[u]+1;
    if(dem>0)return false;
    cha[v]=u;
    cha[u]=dem;
    return true;
}
void nhap()
{
    int n,m,u,v;
    cin >> n >> m;
    for(int i = 1 ; i <= m ; i++)cha[i]=-1;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> u >> v;
        if(!join(u,v)) cout <<"No" << endl;
        else cout <<  "Yes" << endl;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}




