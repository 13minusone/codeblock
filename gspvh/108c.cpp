#include<bits/stdc++.h>
using namespace std;
#define task "triangle"
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
const ll mod = 2147483648;
long long  l[230005],a[230000];
long long  su=0;
void nhap()
{
    long  n,m,v,s;
    cin >> n >> m >> s >> v;
    a[1]=s;
    for(int  i = 1 ; i <= m ; i++)
    {
        cin >> l[i];
        if(i>=2)
        {
            a[i] = ((((a[i - 1] % mod)) * (1103515245 % mod)) + (12345 % mod)) % mod;

        }
        if(l[i]>0)su++;
    }
    for(int i = m+1; i<=n; i++)
    {
        if(i>=2)
        {
            a[i] = ((((a[i - 1] % mod)) * (1103515245 % mod)) + (12345 % mod)) % mod;
            l[i]=2*(a[i]%v)-v+1;
            if(l[i]>0)su++;
        }
        else
        {
            l[i]=2*(a[i]%v)-v+1;
            if(l[i]>0)su++;
        }
    }
    cout <<su*(su-1)*(su-2)/6 << endl;

}
int main()
{

    fastio();
    // inti();
    nhap();
}



