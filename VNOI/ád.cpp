#include<bits/stdc++.h>
using namespace std;
#define task "maxsum"
#define pb push_back
#define ll long long
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define sz(x) s.size()
#define getbit(x,i) (((x)>>(i))&1)
#define turnoff(x,i) ((x)&(~(1<<i)))
const int mod = int(1e9)+7;
const ll oo=1e18;
typedef pair<int, int> ii;
void init()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int sub, n, q;
ll a[int(4e5)+2], trace[int(4e5)+2], f[int(4e5)+2];
void read()
{
    cin >> sub;
    cin >> n >> q;
    for(int i=1; i<=n; i++) cin >> a[i];
}
void sub2()
{
    int l, r;
    ll b;
    while(q--)
    {
        cin >> l >> r >> b;
        for(int i=l-1; i<=r; i++)
        {
            trace[i]=i;
            f[i]=0;
        }
        for(int i=l; i<=r; i++)
        {
            if (a[i]<b) f[i]=-oo;
            else
            {
                if (f[i-1]>0)
                {
                    trace[i]=trace[i-1];
                    f[i]=f[i-1]+a[i];
                }
                else
                {
                    f[i]=a[i];
                    trace[i]=i;
                }
            }
        }
        int leftt=-1, rightt=-1;
        ll ans=-oo;
        for(int i=l; i<=r; i++)
        {
            if (ans<f[i])
            {
                ans=f[i];
                leftt=trace[i];
                rightt=i;
            }
        }
        if (ans==-oo) cout << 0;
        else cout << leftt << " " << rightt;
        cout << "\n";
    }
}
void sol()
{
    if (sub<=2) sub2();
}
int main()
{
    fastio();
    init();
    read();
    sol();
}
