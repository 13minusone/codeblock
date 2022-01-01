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
const ll maxsize = 200000;
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
struct nde
{
    ll x,y,z;
} a[maxsize+5];
ll f[maxsize+5],d[maxsize+5];
bool cmp (nde a,nde b)
{
    return a.x<b.x;
}
ll  maxx=0,h=0,n;
void nhap()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i].x >> a[i].y >> a[i].z ;
    }
    sort(a+1,a+n+1,cmp);
    for(int i= 1 ; i <= n ; i++)
    {
        f[i]=1;
        d[i]=a[i].z;
        for(int j = 1 ; j < i ; j++)
        {
            if(a[i].x>a[j].x&&a[i].y >a[j].y)
            {
                f[i]=max(f[i],f[j]+1);
                d[i]=max(d[i],d[j]+a[i].z);
            }

        }
        maxx=max(maxx,f[i]);
        h=max(h,d[i]);
    }
    cout <<  maxx<< " "<< h << endl;
}
int main()
{

    fastio();
    // inti();
    nhap();
}



