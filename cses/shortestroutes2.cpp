#include<bits/stdc++.h>
using namespace std;
#define task "shortestroutes"
#define ll long long
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
typedef pair<ll,ll> ii;
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
const ll maxsize = 500;
const ll maxx = 1000000000000;
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
ll n,m,x,y,z,q;
vector<vll>a(500+5,vector<ll>(505,maxx));
void nhap()
{

    cin >> n >> m >> q;
    for(int i = 1 ; i <= n ; i++)
    {
        a[i][i]=0;
    }
    for(int i = 1 ; i <= m ; i++)
    {
        cin >> x >> y >> z;
        minimize(a[x][y],z);
        minimize(a[y][x],z);
    }
    for(int x = 1 ; x <= n ; x++)
    {
        for(int y = 1 ; y <= n ; y++)
        {

                for(int k = 1 ; k <= n ; k++)
                {
                a[y][k]=min(a[y][k],a[y][x]+a[x][k]);
                }

        }
    }
    for(int i = 1 ; i <= q; i++)
    {
        cin >> x >> y;
        ll o=(min(a[x][y],a[y][x])==maxx) ? (ll)-1 : min(a[x][y],a[y][x]) ;
        cout << o << endl;
    }

}
int main()
{

    fastio();
    //inti();
    nhap();
}



