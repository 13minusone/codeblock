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
int a[1002][1002], row[1002][1002], col[1002][1002], f[1002][1002], n;
void sol()
{
    int ans=0;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin >> a[i][j];
            if (a[i][j]==a[i][j-1]) row[i][j]=row[i][j-1]+1;
            else row[i][j]=1;
            if (a[i][j]==a[i-1][j]) col[i][j]=col[i-1][j]+1;
            else col[i][j]=1;
            if (a[i][j]==a[i-1][j-1]) f[i][j]=min({f[i-1][j-1]+1,col[i][j], row[i][j]});
            else f[i][j]=1;
            //cout << i << " " << j << " " << f[i][j] << "\n";
            ans=max(ans, f[i][j]);
        }
    }
    cout << ans*ans;
}
int main()
{
    fastio();
    init();
    sol();
}
