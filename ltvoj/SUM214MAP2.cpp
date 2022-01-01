#include<bits/stdc++.h>
using namespace std;
#define task "SUM214MAP2"
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
    ll k,n,l;
    cin >> k >> n;

    k=k+(n-1)-1;
    l=k+1;
    ll f=0;
     if(k%2==0)
    {
        f=(k+1)*(k/2);
    }
    else
    {
        f=(k+1)*(k/2)+(k/2+1);
    }
   // cout << f << endl;
    cout << f+n;
}
int main()
{

    fastio();
    inti();
    nhap();
}



