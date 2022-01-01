#include<bits/stdc++.h>
using namespace std;
#define task "select"
#define ll long long
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
typedef pair<ll,ll> ii;
typedef vector<ll> vll;
typedef vector<ii> vii;
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
bool check(ll  a, ll b)
{
    if(a*b%2==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
ii a[6005];
vll b;
int f[7000];
int n;
void nhap()
{
    cin  >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i].first >> a[i].second ;
    }
    sort(a+1,a+1+n);
    for(int i = 1 ; i <= n ; i++)
    {
        b.clear();
        for(int j =1; j<= n ; j++)
        {
            if(i==j)continue;
            ll h=(a[i].first-a[j].first)*(a[i].first-a[j].first)+(a[i].second-a[j].second)*(a[i].second-a[j].second);
            float p=sqrt(h);
            if(p*p==h)
            {
                b.push_back((int)sqrt(h));
                f[SZ(b)-1]= j
            }

        }
        for(int o = 0 ; o<SZ(b)-1; o++)
        {
            for(int j = o+1; j<SZ(b); j++)
            {
                if(check(b[o],b[j])==true)
                {
                    for
                }
            }
        }
    }


}
int main()
{

    fastio();
    // inti();
    nhap();
}



