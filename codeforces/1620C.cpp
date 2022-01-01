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
int a[2005],cnt[2005];
string s,h;
int t,n,k,num=0,cnt[2005][2005],sum[2005];
ll x;
vector<ll>vec;
void solve(int pos)
{
    for(int i = 0;i<= a[num];i++)cnt[num][i]=1;
    for(int i = num-1;i>= 1 ; i--)
    {

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
        memset()
        cin >> n >> k >> x;
        cin >> s;
        h="";
        int sizee = SZ(s);
        For(i,0,sizee)
        {
            if(s[i] == '*')
            {
                int sum=1;
                while(s[i] == 0)
                {
                    sum+=k;
                    i++;
                    if(i == sizee)break;
                }
                a[++num]=sum;
                h+='*';
            }
            else h+='a';
        }
        solve();
    }
}
