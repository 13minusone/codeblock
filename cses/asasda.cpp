#include<bits/stdc++.h>
using namespace std;
#define task "thi"
#define pb push_back
#define ll long long
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define sz(x) s.size()
#define getbit(x,i) (((x)>>(i))&1)
#define turnoff(x,i) ((x)&(~(1<<i)))
#define CNT(x) __builtin_popcount(x)
const int mod = int(1e9)+7;
typedef pair<int, int> ii;
void init()
{
    if (fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
}
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int n, d, a[1005], f[202][202], g[202][202];
void read()
{
    cin >> n >> d;
}
bool check(int b[], int dem)
{
    for(int i=1; i<=dem/2; i++)
    {
        if (abs(b[i]-b[i+dem/2])>d) return false;
    }
    return true;
}
void sub1()
{
    int b[22], ans=0;
    for(int i=0; i<2*n; i++) cin >> a[i];
    for(int mask=1; mask< (1<<(2*n)); mask++)
    {
        int cnt=CNT(mask);
        if (cnt%2==1) continue;
        int dem=0;
        for(int i=0; i<2*n; i++)
        {
            if (getbit(mask,i)) b[++dem] = a[i];
        }
        if (check(b,dem)) ans=max(ans, dem/2);
    }
    cout << ans;
}
void sub2()
{
    int ans=0;
    for(int i=1; i<=2*n; i++) cin >> a[i];
    for(int x=1; x<=2*n; x++)
    {
        memset(f, 0, sizeof f);
        for(int i=1; i<=x; i++)
        {
            for(int j=x+1; j<=2*n; j++)
            {
                if (abs(a[i]-a[j])<=d) f[i][j]=f[i-1][j-1]+1;
                else f[i][j]=max(f[i-1][j], f[i][j-1]);
                ans=max(ans, f[i][j]);
            }
        }
    }
    cout << ans;
}
void sol()
{
    if (n<=10) sub1();
    else if (n<=100) sub2();
}
int main()
{
    fastio();
    init();
    read();
    sol();
}
