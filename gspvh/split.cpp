//CODE IS WRITTEN BY 13MINUSONE
#include<bits/stdc++.h>
using namespace std;
#define task "split"
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
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b) : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b) : 0); }
const ll N = 1e5 + 5;
const ll mod =998244353;
const ll base = 311;
const int block = 488;
int n;
ll ans=0;
string s;
void add(ll &a,ll b)
{
    a+=b;
    if(a>=mod)a-=mod;
}
void solve(int pos,ll pre)
{
    if(pos == n)
    {
        add(ans,1);
        return;
    }
    if(s[pos] == '0')return;
    ll sum=0;
    For(i,pos,n)
    {
        sum*=10;
        sum+=(s[i]-'0');
        if(sum > pre)
        {
            if(i+1!=n){
                if(s[i+1]!='0')solve(i+1,sum);
            }else add(ans,1);
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
    cin >> s;
    n=SZ(s);
    if(n<=1000)
    {
        solve(0,-1);
    }
    cout << ans;
}
