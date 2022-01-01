/*
    You are watching a brute force code
        CODE IS WRITTEN BY 13MINUSONE
*/
#include<bits/stdc++.h>
using namespace std;
#define task "MEDIAN"
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
int n;
ll x,a[N],f[N],st[2*N];
vector<ll>vec;
void update(int i,int val)
{
    for(;i<=n;i+=( (i) & (-i) ))
        st[i]+=val;
}
ll get(int i)
{
    ll s=0;
    for(;i>0;i-=((i) & (-i) ) )
        s+=st[i];
    return s;
}
void nhap()
{
    cin >> n >> x;
    f[0]=0;
    for(int i =1 ;i <= n ; i++)
    {
        cin >> a[i];
        f[i]=f[i-1]+( (a[i]>=x)?1:-1);
        vec.push_back(f[i]);
    }
    vec.push_back(0);
    sort(all(vec));
    vec.resize(unique(all(vec))-vec.begin());
    int k=0;
    ll ans=0;
    k=lower_bound(all(vec),0)-vec.begin()+1;
    update(k,1);
    for(int i = 1;  i <= n ;i++)
    {
        k=lower_bound(all(vec),f[i])-vec.begin()+1;
        ans+=get(k);
        update(k,1);
    }
    cout << ans;
}
int main()
{

    fastio();
     inti();
    nhap();
}




