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
int n , m;
ii a[3005];
int f[3005][3005],maxx=0;
void nhap()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    f[0][0]=0;
    f[0][1]=0;
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <m+a[i].first ; j++)
        {
            f[i][j]=max(f[i-1][j],f[i][j]);
            if(j<a[i].first)continue;
            f[i][j]=max(f[i][j],f[i-1][j-a[i].first]+a[i].second);
            maxx=max(maxx,f[i][j]);
        }
    }
    cout << maxx << endl;
}
int main()
{

    fastio();
    // inti();
    nhap();
}



