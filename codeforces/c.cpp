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
const ll mod =998244353;
const ll base = 311;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

ll a[2*N+5],s[3];
ll gt[2*N+5],chap[2*N+5];
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
ll check(int k, int n)
{
    if (k>n) return 0;
    return gt[n]*chap[n-k]%mod*chap[k]%mod;
}
int t,n;
vector<ll>vec;
void solve()
{

        sort(all(vec));
        ll j=1;
        s[1]=0;
        s[2]=0;
        s[j]++;
        for(int i = n-2 ; i>=0;i--)
        {
            if(vec[i]!=vec[i+1])
            {
                j++;
                if(j>2)break;

            }
            else
            {
                s[j]++;
            }

        }
        //cout << vec[n-2] << " "<< s[2] << endl;
    ll su=0;
    if (a[n]==a[n-1]) cout<<gt[n]<<endl;
    else if (a[n]!=a[n-1]+1) cout<<0<<endl;
        else{
        for (int i=1;i<=n;++i){
            su+=(a[i]==a[n]-1);
        }
        ll ans=1ll*su*check(su+1,n)%mod*gt[su]%mod*gt[n-su-1]%mod;
        cout<<ans<<endl;
        }

}
void nhap()
{
    cin >> t;
    gt[0]=1;
    gt[1]=1;
    for(int i = 2 ; i <= N ; i++)
    {
            gt[i]=((gt[i-1]%mod)*(i%mod))%mod;
    }
    for (int i=0;i<N;++i){
        chap[i]=powe(gt[i],mod-2);
    }
    while(t--)
    {
        vec.clear();
        cin >> n;
        for(int i = 1 ; i <= n ; i++)
        {
            cin >> a[i];
            vec.push_back(a[i]);
        }
        sort(a+1,a+1+n);
        solve();
    }
}
int main()
{
    fastio();
    nhap();
}

