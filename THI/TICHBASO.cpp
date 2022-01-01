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
#define task "TICHBASO"
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
const ll mod =1e18+9;
const ll base = 311;
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
int n,x,y,z,a[N];
ll max3=-mod,max2=-mod,max1=-mod,maxx=-mod;
void nhap()
{
    cin >> n;
    for(int i = 1; i <= n ;i++)cin >> a[i];
    cin >> x>> y >> z;
    for(int i = n ; i >= 1;i--)
    {
        if(n-i+1>=3)max1=max(max1,max2+a[i]*x);
        maxx=max(maxx,max1);
        if(n-i+1 >=2){
            max2=max(max2,a[i]*y+max3);
        max1=-mod;
        }
        if(max3 < a[i]*z)
        {
            max3=a[i]*z;
            max1=-mod;
            max2=-mod;
        }

        //cout << max1 << " "<< max2 << " "<< max3 << endl;
    }
    cout << maxx;
}
int main()
{

    fastio();
    inti();
    nhap();
}




