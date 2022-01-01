//CODE IS WRITTEN BY 13MINUSONE
#include<bits/stdc++.h>
using namespace std;
#define task "keoco"
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
int n,d[25];
map<ll,int>mp;
ll a[25],s=0,s0=0;
void solve(int pos,int limit)
{
    if(pos == limit+1)
    {
        ll s1=0,s2=0;
        bool te=true;
        Fore(i,1,limit)
        {
            if(d[i] == 1)
            {
                te=false;
                s1+=a[i];
            }
            if(d[i] == 2)
            {
                s2+=a[i];
                te=false;
            }
        }
        if(te == false){
            mp[s1-s2]++;
        }
        return;
    }
    for(int i = 1 ; i <= 3;i++)
    {
        d[pos]=i;
        solve(pos+1,limit);
        d[pos]=0;
    }
}
void solve2(int pos,int start,int limit)
{
    if(pos == limit+1)
    {
        ll s1=0,s2=0;
        bool te=true;
        Fore(i,start,limit)
            if(d[i] == 1)
            {
                te=false;
                s1+=a[i];
            }
            else if(d[i] == 2)
            {
                s2+=a[i];
                te=false;
            }
        ll sub=s2-s1;
        auto x=mp.find(sub);
        if(sub!=0)s+=x->se;
        else if (te == false )s0+=(x->se+1);
        return;
    }
    for(int i = 1 ; i <= 3;i++)
    {
        d[pos]=i;
        solve2(pos+1,start,limit);
        d[pos]=0;
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
    cin >> n;
    for(int i = 1; i <= n ; i++)scanf("%lld",&a[i]);
    int m=n/2;
    solve(1,m);
    solve2(m+1,m+1,n);
    cout <<s/2+s0+(mp.find(0)->se)/2;
}
