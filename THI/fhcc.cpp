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
template<class T> void minimize(T &A, T B)
{
    A=min(A,B);
}
template<class T> void maximize(T &A, T B)
{
    A=max(A,B);
}
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
ll hi[55],a[55],maxx[55];
vector<int>vec[55];
void dfs(int u,int v)
{
    //maxx[u]=0;
    for(int i :vec[u])
    {
        if(i==v)continue;
        dfs(i,u);
        maxx[u]=max(maxx[u],hi[i]);
    }
    hi[u]=a[u]+maxx[u];

}
int x,y;
int n;
vector<ll>c;
void nhap()
{
    int t;
    cin>>t;
    for(int p=1; p<= t; p++)
    {

        cin >> n;
        for(int i = 1 ; i <= n ; i++)
        {
            vec[i].clear();
            hi[i]=0;
            maxx[i]=0;
            cin >> a[i];
        }
        for(int i = 1 ; i < n ; i++)
        {
            cin >> x >> y;
            vec[x].push_back(y);
            vec[y].push_back(x);
        }
        dfs(1,-1);
        ll s=0;
         c.clear();
         if(n==1)
         {
              cout <<"Case #"<<p <<": "<< hi[1] <<endl;
             continue;
         }
        if(vec[1].size()==1)
        {
            s=s+hi[vec[1][0]]+a[1];
        }
        if(vec[1].size()>=2)
        {
            for(int i :vec[1])
            {
                c.push_back(hi[i]);
            }
            sort(all(c));
            s=s+c[SZ(vec[1])-1]+c[SZ(vec[1])-2]+a[1];
        }
        cout <<"Case #"<<p <<": "<< s <<endl;
    }
}
int main()
{

    fastio();
    inti();
    nhap();
}




