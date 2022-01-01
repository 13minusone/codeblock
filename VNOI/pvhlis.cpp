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
typedef long long ll ;
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll N = 220797;
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
ll dp[N+5][4],a[N+5];
void nhap()
{
    int n;
    cin >> n;
    for(int i = 1;  i <= n ; i++)
    {
        cin >> a[i];
    }
    ll maxx=0;
    for(int i = 1 ; i<= n ; i++)
    {
        ll max1=0,max2=0,max3=0;
        for(int j = i - 1 ; j >=1 ; j--)
        {
            if(a[j] < a[i])
            {
                max1=max(max1,dp[j][1]);
                max3=max(max3,dp[j][3]);
            }
            if(a[j] + a[i] < 0 )maximize(max2,dp[j][1]);
            if(a[j] > a[i])maximize(max2,dp[j][2]);
            if(-a[j] < a[i])maximize(max3,dp[j][2]);
        }
        dp[i][1]=max1+1;
        dp[i][2]=max2+1;
        dp[i][3]=max3+1;
        maxx=max(maxx,max({dp[i][1] , dp[i][2] , dp[i][3]}));
    }
    cout <<maxx;
}
int main()
{

    fastio();
    // inti();
    nhap();
}




