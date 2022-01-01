#include<bits/stdc++.h>
using namespace std;
#define task "SUM214SEMAX"
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
void nhap()
{
    ll n,a[maxsize+5],maxx1=-1,maxx=-1;
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
        if(maxx<a[i])
        {
            maxx1=maxx;
            maxx=a[i];
        }
        else
        {
            if(maxx!=a[i])
            {
                maxx1=max(maxx1,a[i]);
            }
        }
    }
    if(maxx1==-1)
    {
        cout << "0" ;
        return;
    }
    cout << maxx1 << endl;

    for(int  i = 1 ; i <= n ; i++)
    {
        if(a[i]==maxx1)
        {
            cout << i << " ";
        }
    }
}
int main()
{

    fastio();
     inti();
    nhap();
}



