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
unsigned ll  gcd(unsigned ll  a, unsigned ll  b) {
  while (b != 0)  {
    unsigned ll  t = b;
    b = a % b;
    a = t;
  }
  return a;
}
unsigned ll a[120],s=1;
ll x;
void nhap()
{
    int n;
    cin >> n;
    if(n<=1)
    {
        cout << 1;
        return;
    }
    cin >> a[1] >> a[2];
    s=a[1]*a[2];
    if(a[1]*a[2]==0)
    {
        cout << "impossible";
        return;
    }
    unsigned ll u=gcd(a[1],a[2]),o;
    o=s/u;
    if(s>=o)
    {
        s/=o;
    }
    for(int i = 3 ; i<= n ; i++)
    {
        cin >> a[i];
        if(a[i]==0)
        {
            cout << "impossible";
            return;
        }
        s*=a[i];
        if(o%a[i]!=0)
        {
            u=gcd(o,a[i]);
            ll p=o;
            o=(o*a[i])/u;
            if(s>=o/p)
            {
                s/=(o/p);
            }
        }

    }
    //cout << u << endl;
    cout << s;
}
int main()
{

    fastio();
    // inti();
    nhap();
}
