#include<bits/stdc++.h>
#define name "one4ever"
#define maxn 10
#define oo LLONG_MAX
#define fo(i,a,b) for(ll i=a;i<=b;++i)
#define CONST
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define e endl
using namespace std;
typedef unsigned long long ll;
template<class T> void MIN(T &A, T B) {A=min(A,B);}
template<class T> void MAX(T &A, T B) {A=max(A,B);}
template<class T> void SUM(T &A, T B) {A=A+B;}
template<class T> void HIEU(T &A, T B) {A=A-B;}
ll t,a,b,mod,k;
ll f[maxn][maxn],m[maxn][maxn],res;

ll mul_num(ll a, ll n)
{
    ll res=a, ans=0;
    while(n)
    {
        if(n%2!=0)
        {
            ans=(ans+res)%mod;
        }
        res=(res+res)%mod;
        n/=2;
    }
    return ans;
}


void mul_matrix(ll u[maxn][maxn],ll v[maxn][maxn])
{
    ll f1 = ((mul_num(u[1][1],v[1][1])%mod)+mul_num(u[1][2],v[2][1])%mod)%mod;
    ll f2 = ((mul_num(u[1][1],v[1][2])%mod)+mul_num(u[1][2],v[2][2])%mod)%mod;
    ll f3 = ((mul_num(u[2][1],v[1][1])%mod)+mul_num(u[2][2],v[2][1])%mod)%mod;
    ll f4 = ((mul_num(u[2][1],v[1][2])%mod)+mul_num(u[2][2],v[2][2])%mod)%mod;
    u[1][1] = f1;
    u[1][2] = f2;
    u[2][1] = f3;
    u[2][2] = f4;
}

void Pow(ll a, ll n)
{
    if(n==1) return;
    Pow(a,n/2);
    mul_matrix(f,f);
    if(n%2==1) mul_matrix(f,m);
}

void solve()
{
    a%=mod;
    b%=mod;
    if(k==1){
        cout<<b<<e;
        return;
    }
    f[1][1] = a;  m[1][1]=a;
    f[1][2] = 0;  m[1][2]=0;
    f[2][1] = b;  m[2][1]=b;
    f[2][2] = 1;  m[2][2]=1;
    Pow(a,k-1);
    res=(mul_num(b,f[1][1])%mod+f[2][1]%mod)%mod;
    cout<<res<<e;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);  cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>mod>>k;
        solve();
    }
}
