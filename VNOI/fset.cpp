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
#define pb push_back
typedef long long ll ;
typedef pair<ll,ll> ii;
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
const ll N = 1e6;
const ll mod =1e18;
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
int f[N+5],o[N+5];
ll tach(int n)
{
    int x=2;
    ll m=1;
    while(n>1)
    {
        int f=0;
        if(n%x==0)
        {
            while(n%x==0)f++,n/=x;
            if(f&1)m*=x;
        }
        if(o[n]!=0)return m*o[n];
        if(x>sqrt(n))return m*n;
        x++;
    }
    return m;
}
void nhap()
{
    int n,m;
    cin >> n >> m;
    ll res=1;
    for(int i = 1 ; i <= n ; i++)
    {
        //cout << tach(i) <<endl;
        int h=tach(i);
        o[i]=h;
        f[h]++;
    }
    for(int i = 1 ; i <= n ; i++)
    {
        res=(res*(f[i]+1))%m;
    }
    cout << res;
}
int main()
{

    fastio();
    // inti();
    nhap();
}




