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
ll a[25][25],f[mu2(21)];
void nhap()
{
    ll n;
    cin >> n;
    for(int  i = 0 ; i < n ; ++i)
    {
        for(int j = 0 ; j < n ; ++j)
        {
            cin >> a[i][j];
        }
    }
    for(int  i = 0 ; i<mu2(n);i++)
    {
        int d=__builtin_popcount(i);
        for(int j = 0 ;j <n ; j++)
        {
            if(getbit(i,j))
            {
                maximize(f[i],f[turnoff(i,j)]+a[d-1][j]);
            }
        }

    }
    cout << f[mu2(n)-1] ;
}
int main()
{

    fastio();
    inti();
    nhap();
}


