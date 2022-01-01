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
#define task "gianseq"
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
const ll mod =1e18+9;
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
ll f[2005];
ll a[2005];
int n,k;
bool check(ll r,int n,int k)
{
    f[1]=0;
    for(int i = 2 ; i <= n ; i++)
    {
        ll minn=1e18;
        for(int j = i - 1 ; j >=1;j--)
        {
          if(abs(a[i]-a[j])<=ll(r*(i-j)))
            {
                minimize(minn,(ll)f[j]+(i-j-1));
            }
        }
        minn=min((ll)i-1,minn);
        f[i]=minn;
    }
    if(f[n]<=k)return true;
    ll ans=k+1;
    for(int  i = 1 ; i <= n ; i++)
    {
        ans=min(ans,f[i]+n-i);
    }
    return (ans<=k);
}
void nhap()
{

    cin >> n >> k;
    for(int i = 1 ;i <= n ; i++)
    {
        cin >> a[i];
    }
    check(4,n,k);
    ll l=0,r=1e18,maxx=mod;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(check(mid,n,k)==true)
        {
            maxx=min(maxx,mid);
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    cout <<maxx << endl;
}
int main()
{

    fastio();
    inti();
    nhap();
}




