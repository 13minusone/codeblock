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
const ll N = 50000 + 5;
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
int n;
ll hasht[N],rhasht[N],powe[N];
string s;
ll gethash(int l,int r)
{
    return (hasht[r] - hasht[l-1] * powe[r-l+1] + mod * mod )%mod;
}
ll getrhash(int l,int r)
{
    return (rhasht[l] -  rhasht[r+1]*powe[r-l+1] + mod * mod )%mod;
}
bool oke(int m)
{
    for(int i = 1 ;i <=n-m+1; i++)
    {
        if(gethash(i,i+m-1)==getrhash(i,i+m-1))return true;
    }
    return false;
}
void nhap()
{
    cin >> n;
    cin >> s;
    s = " "+s;
    powe[0]=1;
    for(int i = 1;  i <= n ; i++)
    {
        powe[i]=(powe[i-1] * base)%mod;
        hasht[i]=(hasht[i-1]*base+s[i] - 'a' + 1)%mod;
    }
    rhasht[n+1]=0;
    for(int i = n ; i >= 1 ; i--)
    {
        rhasht[i]=(rhasht[i+1]*base + s[i]- 'a' + 1)%mod;
    }
    int maxx=0;
    int l = 1,r=n+1;
    while(l+1 < r)
    {
        int mid=(l+r)/2;
        if(oke(mid))
        {
            maximize(maxx,mid);
            l=mid;
        }
        else
        {
            r=mid;
        }
    }
    cout << maxx << endl;
}
int main()
{

    fastio();
    // inti();
    nhap();
}




