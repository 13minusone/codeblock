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
typedef pair<ll,int> ii;
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
priority_queue<ii,vector<ii>,greater<ii>>q;
ll a[N+5],b[N+5],d[N+5];
void nhap()
{
    int n,k;
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> b[i];
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    for(int i =1; i<=n;i++)
    {
        q.push({a[i]+b[1],1});
    }
    ll s;
    while(k>0)
    {
       ii v=q.top();
       q.pop();
       ll x=v.first;
       int y=v.second;
       cout << x << " ";
       if(y<n)
       {
           q.push({x-b[y]+b[y+1],y+1});
       }

       k--;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}




