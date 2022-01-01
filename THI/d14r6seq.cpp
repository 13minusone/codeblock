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
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b) : 0); }
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b) : 0); }
const ll N = 1e5 + 5;
const ll mod =1e9+9;
const ll base = 311;
const int block = 488;
int n,a[N],cnt[N],maxx=0;
vector<int>vec,val[N];
int tim(int d,int s)
{
    int last = a[val[s][0]+d];
    if(val[s].back()+d > n || a[val[s].back() + d] !=last)return d;
    bool oke=true;
    for(int i : val[s])
    {
        if(i + d > n || a[i+d] != last)
        {
            oke=false;
            break;
        }
    }
    if(oke)return tim(d+1,s);
    return d;
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
    for(int i = 1 ; i <= n ;i++){
            cin >>a[i];
            vec.push_back(a[i]);
    }
    sort(all(vec));
    vec.resize(unique(all(vec))-vec.begin());
    for(int i = 1 ; i <= n ; i++)
    {
        a[i]=lower_bound(all(vec),a[i])-vec.begin();
        val[a[i]].push_back(i);
        cnt[a[i]]++;
        maximize(maxx,cnt[a[i]]);
    }
    int len=0,l=0;
    for(int i = 1;  i <= n ; i++)if(cnt[a[i]] == maxx)
    {
        if(val[a[i]].back()+len <= n)
        {
            ll d = tim(1,a[i]);
            cnt[a[i]]=0;
            if(d >= len)
            {
                maximize(l,val[a[i]].back());
                len=d;
            }
        }
    }
     cout << l << " " << l+len-1;

}
