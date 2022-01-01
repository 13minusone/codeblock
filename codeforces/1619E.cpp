//CODE IS WRITTEN BY 13MINUSONE
#include<bits/stdc++.h>
using namespace std;
#define task "c9"
#define SZ(c) (c).size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define __builtin_popcount __builtin_popcountll
#define all(x) (x).begin(),(x).end()
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define fi first
#define se second
#define For(i,l,r) for(int i = l ; i < r ;i++)
#define Fore(i,l,r) for(int i = l ; i <= r ; i++)
#define Ford(i,l,r) for(int i = l ; i >= r ; i--)
typedef long long ll ;
typedef pair<int,int> ii;
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
const ll N = 2e5 + 5;
const ll mod =1e9+9;
const ll base = 311;
const int block = 488;
int t,a[N],f[N],sum[N];
ll solve()
{
    for(int i = 1 ; i<= n ;i++)f[i]=f[i-1]+a[i];
    int j=1;
    bool te=true;
    for(int i = 0 ; i <=n ; i++)
    {
        int s=0;
        while(a[j] <i )j++;
        if(te==false || sum[i] < f[min(i+1,j)])
        {
            cout << -1 << " ";
            te=false;
        }
        else

    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> t;
    for(int i = 1; i <= n ; i++)sum[i]=sum[i-1]+i;
    while(t--)
    {
        cin >> n;
        for(int i = 1; i <= n ; i++)
            cin >> a[i];
        sort(a+1,a+1+n);
        solve();
        cout << endl;
    }

}
