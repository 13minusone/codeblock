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
#define EPSILON numeric_limits<double>::epsilon()
typedef long long ll ;
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll N = 1e5;
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
int n;
bool ss(double A, double B)
{
    double khac = A-B;
    return (khac<EPSILON) && (-khac<EPSILON);
}

ll tinh(ll a[],ll b[],ll c[])
{
    double g[n];
    for(int i=0; i<n; i++)g[i] = (a[i]*1.0)/b[i];
    sort(g, g+n);
    ll cnt[n+5], left = 0;
    ll tcnt = 1;
    for (int i=1; i<n; i++)
    {
        if (ss(g[i], g[i-1]))
            tcnt++;
        else
        {
            cnt[left++] = tcnt;
            tcnt = 1;
        }
    }
    cnt[left++] = tcnt;
    ll tong1 = 0;
    for (int i=0; i<left; i++){
            tong1 += cnt[i];
    tong1%=mod;
    }
    ll tong2 = 0;
    ll tm[n];
    for (int i=0; i<left; i++){
        tm[i] = cnt[i]*(tong1-cnt[i]);
        tm[i]%=mod;
        tong2 += tm[i];
        tong2%=mod;
    }
    tong2/=2;
    ll tong3 = 0;
    for (int i=0; i<left; i++){
            tong3 += cnt[i]*(tong2-tm[i]);
    tong3%=mod;
    }
    tong3 /= 3;

    return tong3;
}
ll a[3*N+5],b[3*N+5],c[3*N+5];
void nhap()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    cout << tinh(a,b,c);
}
int main()
{

    fastio();
    // inti();
    nhap();
}




