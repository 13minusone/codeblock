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
const ll N = 1e5 + 5;
const ll mod =1e9+9;
const ll base = 311;
const int block = 488;
int t,n;
string s,d;
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
        cin >> s >>  d;
        int diff=0,same=0,s1=0;
        for(int i = 0 ;i < n ;i++)
        {
            if(s[i] != d[i])diff++;
            else{
                if(s[i] == '1')s1++;
                same++;
            }
        }
        if(s1 == 0 )cout << -1;
        else cout << min((diff%4 == 0 ? diff : int(diff/4)+2),same) ;
        cout << endl;
    }
}
