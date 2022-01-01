/*
    You are watching a brute force code
        CODE IS WRITTEN BY 13MINUSONE
*/
#include<bits/stdc++.h>
using namespace std;
#define task "c9"
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
#define all(x) x.begin(),x.end()
#define endl '\n'
#define fi first
#define se second
typedef long long ll ;
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
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
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }
const ll N = 1e5 + 5;
const ll mod =1e9+9;
const ll base = 311;
const int block = 488;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void inti()
{
        if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
}
ll nextt[2*N],cnt[2*N];
int n,q,a[2*N],type,pos,val;
void update(int pos )
{
    if(pos + a[pos] >= n || pos/block < (pos+a[pos])/block)
    {
        nextt[pos]=pos+a[pos];
        cnt[pos]=1;
    }
    else
    {
        nextt[pos] = nextt[pos+a[pos]];
        cnt[pos]=cnt[pos+a[pos]]+1;
    }
}
ii query(int pos)
{
    ll s=0,ans=0;
    while(pos <=n )
    {
        s+=cnt[pos];
        ans=pos;
        pos=nextt[pos] ;
    }
    while(true)
    {
        if(ans+a[ans]>n)break;
        else ans+=a[ans];
    }
    return ii(s,ans);
}
void nhap()
{
    cin >> n >> q;
    for(int i  =1 ; i <= n ; i++)
    {
        cin >> a[i];
    }
    memset(cnt,0,sizeof cnt);
    for(int i = n ; i >=1 ; i--)
    {
        update(i);
    }
    while(q--)
    {
        cin >> type >> pos ;
        if(type == 1)
        {
            ii ans=query(pos);
            cout << ans.se << " " << ans.fi << endl;
        }
        else {
                cin >> val;
        a[pos]=val;
        for(int i = pos ; i >=0 && i/block == pos/block;i--)update(i);
        }
    }
}
int main()
{

    fastio();
     inti();
    nhap();
}




