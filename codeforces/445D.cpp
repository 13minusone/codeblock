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
const int bl = 320;
vector<int>a;
int x,n,q,cnt[bl+5][N],k,y,type;
void upd(int l,int r)
{
    int x=a[l],y=a[r];
    int lb=l/bl;
    int rb=r/bl;
    if(lb == rb)
    {
        a.erase(a.begin()+r);
        a.insert(a.begin()+l ,y);
        return;
    }
    for(int i = lb+1;i < rb;i++)
    {
        int frontt=(i*bl)-1,backk=(i+1)*bl-1;
        cnt[i][a[frontt]]++;
        cnt[i][a[backk]]--;
    }
    cnt[lb][y]++;
    cnt[lb][a[(lb+1)*bl-1]]--;
    cnt[rb][y]--;
    cnt[rb][a[rb*bl-1]]++;
    a.erase(a.begin()+r);
    a.insert(a.begin()+l,y);
}
int query(int l,int r,int k)
{
    int lb=l/bl;
    int rb=r/bl;
    int ans=0;
    if(lb == rb)
    {
        Fore(i,l,r)if(a[i] == k)ans++;
        return ans;
    }
    for(int i =lb+1;i <rb;i++)ans+=cnt[i][k];
    for(int i = l; i <= min(n-1,(lb+1)*bl-1);i++)
        if(a[i]==k)ans++;
    Fore(i,rb*bl,r)if(a[i]==k)ans++;
    return ans;
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
    a.eb(0);
    Fore(i,1,n)
    {
        cin >> x;
        a.eb(x);
        cnt[i/bl][x]++;
    }
    cin >> q;
    int lastans=0;
    while(q--)
    {
        cin >>  type >> x >> y;
        x = (x + lastans - 1 + n)%n + 1;
        y = (y + lastans - 1 + n)%n + 1;
        if (x > y) swap(x, y);
        if (type==1) upd(x, y);
        else
        {
            cin >> k;
            k = (k + lastans - 1 + n)%n + 1;
            lastans = query(x, y, k);
            cout << lastans << "\n";
        }
    }
}
