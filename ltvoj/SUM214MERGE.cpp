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
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll maxsize = 100000;
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
map<ll,ll>d;
void nhap()
{
    ll n , m;
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> d[i];
    }
    for(int i = 1 ;i <= m ;i++)
    {
        cin >> d[n+i];
    }
    sort(d+1,d+1+n);
    for(int  i = 1 ; i<=n+m;i++)
    {
        cout << d[i] << " ";
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}



