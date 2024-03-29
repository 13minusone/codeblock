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
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b) : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b) : 0); }
const ll N = 2e5 + 5;
const ll mod =1e9+9;
const ll base = 311;
const int block = 488;
int t,cnt[N][35],l,r;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    memset(cnt,0,sizeof cnt);
    for(int i = 1 ; i <N ; i++)
    {
        for(int j = 0 ; j < 32 ;j++)
        {
            if( getbit(i,j) == 0){
                cnt[i][j]=cnt[i-1][j]+1;
            }
            else cnt[i][j]=cnt[i-1][j];
        }
    }
    cin >> t;
    while(t--)
    {
        cin >> l >> r;
        int minn=mod;
        for(int i = 0 ; i <32;i++)
        {
            minimize(minn,cnt[r][i]-cnt[l-1][i]);
        }
        cout << minn << endl;
    }
}
