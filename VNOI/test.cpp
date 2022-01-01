/*
🛸　　　 　🌎　°　　🌓　•　　.°•　　　🚀 ✯
　　　★　*　　　　　°　　　　🛰 　°·　　                           🪐
.　　　•　° ★　•  ☄
______________________________________________________
    You are watching a brute force code
        CODE IS WRITTEN BY 13MINUSONE
*/
#include<bits/stdc++.h>
using namespace std;
#define task "c"
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
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void inti()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
int n,m;
ii a[20];
struct iii
{
    ll s;
    vector<int>d;
};
iii d[20];
bool check[20];
void nhap()
{
    cin >> n >> m;
    for(int i = 1; i <= n ;i++)
    {
        cin >> a[i].fi;
        a[i].se=i;
    }
    sort(a+1,a+1+n);
    memset(check,true,sizeof check);
    int s=1;
    for(int i = 1 ; i <= n ; i++)
    {
        if(check[i] == false)continue;
        if(d[s].s+a[i].fi > m)s++;
        d[s].s+=a[i].fi;
        d[s].d.push_back(a[i].se);
        check[i]=false;
        for(int j = n ; j >= 1 ; j--)
        {
            if(check[j] == false)continue;
            if(d[s].s+a[j].fi <= m)
            {
                d[s].s+=a[j].fi;
                d[s].d.push_back(a[j].se);
                check[j]=false;
            }
        }
    }
    cout << s << endl;
    for(int i = 1 ; i <= s;i++)
    {
        cout << SZ(d[i].d) << " ";
        for(int j : d[i].d)cout << j << " ";
        cout << endl;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}




