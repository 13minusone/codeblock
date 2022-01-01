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
const ll mod =998244353;
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
int a[2*N+5],s[3];
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
vector<ll>vec;
void nhap()
{
    int t,n;
    cin >> t;
    gt[1]=1;
     for(int i = 2 ; i <= N ; i++)
     {
            gt[i]=((gt[i-1]%mod)*(i%mod))%mod;
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

        sort(all(vec));
        ll j=1;
        s[j]++;
        for(int i = n-2 ; i>=0;i--)
        {
            if(vec[i]!=vec[i+1])
            {
                j++;
                if(j>2)break;
                s[j]++;
            }
            else
            {
                s[j]++;
            }

        }
        cout << vec[n-1] << " " << s[0] << endl;

    }
}
int main()
{

    fastio();
    //inti();
    nhap();
} 
