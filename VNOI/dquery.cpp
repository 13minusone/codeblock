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
const ll N = 2e5 + 5;
const ll mod =1e9+9;
const ll base = 311;
const int block = 400;
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
int n,q,a[N],x,y;
ll ans[N],s=0,cnt[N*10];
struct query
{
    int L,R,ID;

};
bool cmp(query a,query b)
{
    if(a.L/block != b.L/block)
        return a.L/block < b.L/block;
    return a.R < b.R;
}
vector<query>vec;
void change(int i,int val)
{
    s-=(cnt[a[i]]*cnt[a[i]]*a[i]);
    cnt[ a[i] ]+=val;
    s+=(cnt[a[i]]*cnt[a[i]]*a[i]);
}
void nhap()
{
    cin >> n >> q;
    for(int i = 0; i < n ;i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < q ; i++)
    {
        cin >> x >> y;
        x--,y--;
        vec.push_back({x,y,i});
    }
    sort(all(vec),cmp);
    int TL=0,TR=-1;
    for(query i : vec)
    {
        while(TL > i.L)
            TL--,change(TL,1);
        while(TL < i.L)
            change(TL,-1),TL++;
        while(TR < i.R)
            TR++,change(TR,1);
        while(TR > i.R)
            change(TR,-1),TR--;
        ans[i.ID]=s;
    }
    for(int i = 0 ; i < q; i++)
        cout << ans[i] <<endl;
}
int main()
{

    fastio();
     inti();
    nhap();
}



