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
const ll N = 1e5 + 5;
const ll mod =1e9+9;
const ll base = 311;
const int block = 488;
int t;
ll n;
void solve()
{
     if(n%2==0){
            n--;
            cout<<n/2<<" "<<n-n/2<<" "<<1<<"\n";
        }
        else{
            n--;
            int p = n/2;
            if(p%2)
            cout<<n/2 - 2<<" "<<n/2 + 2<<" "<<1<<"\n";
            else{
                cout<<p-1<<" "<<p+1<<" "<<1<<"\n";
            }
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
    while(t--)
    {
        cin >> n;
        solve();
    }
}