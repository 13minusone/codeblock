//CODE IS WRITTEN BY 13MINUSONE
#include<bits/stdc++.h>
using namespace std;
#define task "DUT04SHAKE"
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
int n;
char s[N];
signed main()
{
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    scanf("%d",&n);
    scanf("%s",&s);
    int up=0;
    ll sum=0;
    for(int i = 0; i < n ;i++)
    {
        if(s[i] == '>')up++;
        else sum+=up;
    }
    printf("%lld",sum);
}
