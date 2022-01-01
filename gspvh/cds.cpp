//CODE IS WRITTEN BY 13MINUSONE
#include<bits/stdc++.h>
using namespace std;
#define task "cds"
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
const int N = 7;
const ll INF = 1e18;
char s[31][7];
int n = 0, k, len;
ll res, check[6];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
     cin >> k;
    while (cin >> s[n++]);
    len = strlen(s[0]);
    for (int i = 0; i < 6; i++)
        check[i] = 0;
    For( i,0,len)
    {
        For(x,0,k)
        {
            bool tr = 1;
            For(t,0,n)
            {
                if (s[t][i] == char(x + int('a')))
                {
                    tr = 0;
                    break;
                }
            }
            if (tr)
                check[i]++;
        }
    }
    res = 1;
    for (int i = 0; i < len; i++)
        res *= check[i];
    cout << res;
    return 0;
}
