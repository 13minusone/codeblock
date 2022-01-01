/*2021/09/27 16:46:51*/
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
#define task "TG01TB"
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
#define all(x) x.begin(),x.end()
#define endl '\n'
typedef long long ll ;
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll N = 2e5 +5;
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
ii a[N];
ll b[2*N];
ll x,m,n,k,y;
ll get(int i,int o)
{
    if(a[o].first<=b[i]&&b[i]<=a[o].second)return 0;
    else return min(abs(a[o].first-b[i]),abs(a[o].second-b[i]));
}
void nhap()
{
    cin >> m >> n >> k;
    for(int i = 1 ; i <= k ; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    ll su=0;
    for(int i = 1; i <= m ;i++)
    {
        for(int j = 1; j <= 2*n ;j++)
        {
            cin >> b[j];
        }
        sort(b+1,b+1+2*n);
        for(int j = 1; j <=2*n-1;j+=2)
        {
            ll maxx=2*mod;
            for(int o=1;o<= k ;o++)
            {
                maxx=min(maxx,(ll)get(j,o)+get(j+1,o));

            }
            su+=maxx;
        }
    }
    cout << su << endl;
}
int main()
{

    fastio();
    inti();
    nhap();
}




