#include<bits/stdc++.h>
using namespace std;
#define task "select"
#define ll long long
#define SZ(c) c.size()
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
const ll maxsize = 100000;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;

    return gcd(b % a, a);
}

void inti()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
int dem=0;
ll chat(int a,int b,ll x)
{

    ll l=1;
    ll c;
    c=(a*b)/gcd(a,b);
    ll r;
    r=max(a,b)*x;
    ll m,g;
    while(l<r)
    {
         m=l+(r-l)/2;
         g=m/a+m/b-m/c;
        if(g>=x)
        {
            r=m;
        }
        else
        {
            l=m+1;
        }

    }
    return l;
}
void nhap()
{
    int t;
    ll a,b,c,s=0;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> c;
        cout << chat(a,b,c) << endl;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}



