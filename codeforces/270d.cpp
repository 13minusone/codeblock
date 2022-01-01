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
ll a[2005][2005];
void nhap()
{
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 1 ; i<=n ; i++)
    {
        for(int j = 1 ; j<= n ; j++)
        {
            if(i==j)
            {
                a[i][j]!=0;
                cout << "NO" ;
                return;
            }
            if()
        }
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}



