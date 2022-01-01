#include<bits/stdc++.h>

using namespace std;
#define task "select"
#define ll long long
#define SZ(c) (ll)c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
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
const ll maxsize = 1000005;
const int base = 311;
const ll mod =1e9+9;
int n;
ll hasht[maxsize],powb[maxsize+5];
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
ll geth(int i,int j)
{
    return (hasht[j]-hasht[i-1]*powb[j-i+1]+mod*mod)%mod;
}
void inti()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
void nhap()
{
    string s,t;
    cin >>s ;
    n=SZ(s);
    s=" "+s;
    powb[0]=1;
    for(int i = 1 ; i <= n ; i++)
    {
        hasht[i]=(hasht[i-1]*base+s[i])%mod;
        powb[i]=(powb[i-1]*base)%mod;
    }
    cin >> t;
    ll hashin=0;
    for(int i = 0; i <SZ(t) ; i++ )
    {
        hashin=(hashin*base+t[i])%mod;
    }
    for(int i = 1; i<=n-SZ(t)+1 ; i++)
    {
        if(hashin==geth(i,i+SZ(t)-1))
        {
            cout << i<< " ";
        }
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}



