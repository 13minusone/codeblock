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
const ll mod =1e15;
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
ll a[305],f[305][305][610];
ll tinh(int l,int r,int k)
{
    if(k == 0)return 0;
    if(l > r)return -mod;
    ll &best=f[l][r][k];
    if(best !=-1)return best;
    best=max(tinh(l,r-1,k),tinh(l+1,r,k));
    if(l<=r-1)
    {
    maximize(best,max(tinh(l+2,r,k-1)+abs(a[l]-a[l+1]),max(tinh(l,r-2,k-1)+abs(a[r]-a[r-1]),tinh(l+1,r-1,k-1)+abs(a[l]-a[r]))));
    }
    return best;
}
void nhap()
{
    int n,k;
    cin  >> n >> k;
    for(int i = 1 ; i <= n ; i++)
    {
        cin>>a[i];
    }
    memset(f,255,sizeof (f));
    cout << tinh(1,n,k);
}
int main()
{

    fastio();
    // inti();
    nhap();
}




