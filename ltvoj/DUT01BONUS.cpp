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
#define task "DUT01BONUS"
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
const ll N = 1e6 + 5;
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
int n,m,x,q,y,z,d;
vector<ll>a[N];
void nhap()
{
    cin >> n >> m >> q;
    for(int j = 1; j <= m ; j++)a[0].push_back(0);
    for(int i = 1 ;i <= n ; i++)
    {
        a[i].push_back(0);
        for(int j = 1; j <= m; j++)
        {
            cin >> x;
            a[i].push_back(x);
        }
    }
    for(int i = 1; i <= n ; i++)
    {
        ll s=0;
        for(int j = 1 ; j <= m ; j++)
        {
            s+=a[i][j];
            a[i][j]=a[i-1][j]+s;
        }
    }
    while(q--)
    {
        cin >> x >> y >> z >> d;
        cout << a[z][d]+a[x-1][y-1] - a[z][y-1]-a[x-1][d] << endl;
    }

}
int main()
{

    fastio();
    inti();
    nhap();
}




