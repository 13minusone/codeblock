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
const ll N = 3e5+5;
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
int hi[N][33],ho[N][33],s=0,n,p,u,v,sum[N][33];
vector<int>edge[N];
void countin(int u,int v)
{
    hi[u][0]=1;
    for(int i : edge[u])
    {
        if(i==v)continue;
        countin(i,u);
        for(int j = 0 ; j < p ; j++)hi[u][j + 1 == p ? 0 : j+1]+=hi[i][j];
    }

}
void countout(int u ,int v)
{
    for(int i :edge[u])
    {
        if(i==v)continue;
        for(int j = 0 ; j < p ; j++)sum[u][j]+=hi[i][j];
    }
    for(int i:edge[u])
    {
        if(i==v)continue;
        ho[i][1]=1;
        for(int j = 0 ; j < p ; j++)
        {
            ho[i][j + 1 == p ? 0 : j+1]+=ho[u][j];
            ho[i][j + 2 >= p ? j+2-p :  j+2] +=sum[u][j]-hi[i][j];
        }
        countout(i,u);
    }
}
void nhap()
{
    cin >> n >> p;
    for(int i = 1;  i < n ; i++)
    {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    countin(1,-1);
    countout(1,-1);
    for(int i = 1; i <= n ; i++){
            if(p==1){
                    cout << n << " ";
            continue;
            }
            cout << hi[i][0]+ho[i][0] << " ";
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}





