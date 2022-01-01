/*
🛸　　　 　🌎　°　　🌓　•　　.°•　　　🚀 ✯
　　　★　*　　　　　°　　　　🛰 　°·　　                           🪐
.　　　•　° ★　•  ☄
______________________________________________________
    You are watching a brute force code
        CODE IS WRITTEN BY 13MINUSONE
        time : 18/10/2021
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
int n,m,test;
int b[1505],a[1505],maxx[1505],dp[1505];
void nhap()
{
    cin >> test;
    while(test--)
    {
        cin >> n >> m;
        for(int i = 1; i <= n ; i++)cin >> a[i];
        for(int j = 1 ;j <= m ; j++)cin >> b[j];
        int ans=0;
        memset(maxx,0,sizeof maxx);
        memset(dp,0,sizeof dp);
        for(int i = 1; i <= n ; i++)
        {
            for(int j = 1 ; j <= m ; j++)
            {
                int x=maxx[i];
                if(b[j]*2 <= a[i])maxx[i]=max(maxx[i],dp[j]);
                if(b[j]==a[i])
                {
                    dp[j]=x+1;
                    maximize(ans,dp[j]);
                }
            }
        }
        cout << ans << endl;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}




