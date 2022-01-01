#include<bits/stdc++.h>
using namespace std;
#define task ""
#define ll long long
#define SZ(c) c.size()
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll maxsize = 100000;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 ll a,n,b,h,k;
ll powe(ll a, ll n,ll k)
{
    if(n==0)return 1;
    if(n==1)
    {
        return a;
    }
    if(n&1)
    {
        return (((((powe(a,n/2,k)%k)*(powe(a,n/2,k)%k)%k)%k)*(a%k))%k);
    }
    else
    {
        return (((powe(a,n/2,k)%k)*(powe(a,n/2,k)%k))%k);
    }
}
void inti()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
void solve()
{

    cin >> a >> n >> b >> h >> k;
    ll f=powe(a,n,k);
    ll g=powe(b,h,k);
    ll p=powe(f,g,k);
    p%=k;
    cout <<p << endl;
}
void nhap()
{
    ll t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}
int main()
{

    fastio();
    // inti();
    nhap();

}



