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
#define task "permute"
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
const ll mod =1e9+7;
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
int a[N+5],s=0,l,r;
ll gt[N+5],chap[N+5];
ll powe(ll a,ll n)
{
    ll ret = 1;
    while (n)
    {
        if (n & 1)
        {
            ret *= a;
            ret %= mod;
        }
        a *= a;
        a %= mod;
        n /= 2;
    }
    return ret%mod;
}
void nhap()
{
    int t,n;
    cin >> n;
    cin >> t;

    for(int i = 1 ; i <= t; i++)
    {
        cin >> l >> r;
       a[l]++;
       a[r+1]--;
    }
    int maxx=0,su=0;
    for(int i = 1; i <= n;i++)
    {
        a[i]+=a[i-1];
        if(a[i]>0)
        {
            su++;
        }
    }
    //cout << su << endl;
    gt[0]=1;
    gt[1]=1;
    for(int i = 2 ; i <= n ; i++)
    {
        gt[i]=((gt[i-1]%mod)*(i%mod))%mod;
    }
    if(su==0)
    {
        cout << gt[n] << endl;
        return ;
    }

    //cout << su << endl;
    for(int i = 1; i<= su ; i++)
    {
        ll c=( ( gt[su-i] % mod ) * ( gt[i] % mod )) %mod;
        chap[i]=((gt[su]%mod)*(powe(c,mod-2)%mod))%mod;
    }
    //cout << chap[10] << endl;
    for(int i = 1 ; i <= su; i++)
    {
        if(i%2==0)
        {
            maxx=(maxx%mod-(chap[i]*gt[n-i])%mod+mod)%mod;
        }
        else
        {
            maxx=(maxx%mod+(chap[i]*gt[n-i])%mod)%mod;
        }
        //cout << i << " "<< maxx << endl;
    }
    //cout << maxx << endl;
    ll ans;
    //cout << gt[n] << endl;
    ans=(gt[n]%mod-maxx%mod+mod)%mod;
    cout << ans << endl;

}
int main()
{

    fastio();
    // inti();
    nhap();
}






