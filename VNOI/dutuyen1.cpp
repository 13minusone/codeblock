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
void operator -= (ii &a,ii b)
{
    a.fi-=b.fi;
    a.se-=b.se;
}
bool clr(ii a , ii b , ii c)
{
    c-=b;
    b-=a;
    return b.fi*c.se > b.se * c.fi;
}
ii a[4005];
bool check[4005];
bool cmp(ii a,ii b)
{
    if(a.fi!=b.fi)return a.fi < b.fi;
    else return a.se < b.se;
}
void nhap()
{
    int n,x,y;
    cin >> n ;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a+1,a+1+n,cmp);
    ll hull[4005],ans=0;
    while(n>2)
    {
        int k = 1 ;
        for(int i =1 ; i <= n; i++)
        {
            check[i] = false;
            while(k>2 && clr(a[hull[k-2]],a[hull[k-1]],a[i]))k--;
            hull[k]=i;
            k++;
        }
        int t=k+1;
        for(int i = n ; i>=1 ;i--)
        {
            while(k > t && clr(a[hull[k-2]],a[hull[k-1]],a[i]))k--;
            hull[k] = i ;
            k++;
        }
        for(int i = 1 ; i < k ;i++)
        {
            check[hull[i]] = true;
        }
        int m = 1 ;
        for(int i = 1 ; i <=n ; i++)
        {
            if(!check[i])
            {
                a[m] = a[i];
                m++;
            }
        }
        n=m-1;
        ans++;
    }
    cout << ans;
}
int main()
{

    fastio();
    // inti();
    nhap();
}




