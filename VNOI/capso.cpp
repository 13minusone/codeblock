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
void inti()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
void nhap()
{
    ll n,s=0;
    cin >> n;
    for(int i = 2 ; i <= sqrt(n); i++ )
    {
        if(n%i==0)
        {
            if((n-i)%i==0)
            {
                if(n-i!=i)
                {

                    s+=2;
                }
                else
                {
                    s++;
                }
            }
            if(n/i!=i)
            {
                ll o=n/i;
            if((n-o)%o==0)
            {
                if(n-o!=o)
                {

                    s+=2;
                }
                else
                {
                    s++;
                }
            }
            }
        }
    }
    cout << s+2;
}
int main()
{

    fastio();
    // inti();
    nhap();
}
