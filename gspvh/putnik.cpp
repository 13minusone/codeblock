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
const ll N = 1e5;
const ll mod =1e10+9;
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
int a[1505][1505],n,s[1505];
void nhap()
{
    cin >> n;
    for(int i = 1; i <= n ; i++)
    {
        for(int j = 1; j <= n ; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 2 ; i <= n ; i++)
    {
        s[i]=s[i-1]+a[i][i-1];
    }
    int sum=0,maxx=mod;
    for(int i = 1; i < n ; i++)
    {
        sum=0;
        sum+=s[i];
        sum+=a[1][i+1];
        sum+=(s[n]-s[i+1]);
        //cout << i << " " << sum << endl;
        maxx=min(maxx,sum);
    }
    maxx=min(maxx,s[n]);
    cout << maxx ;

}
int main()
{

    fastio();
    // inti();
    nhap();
}




