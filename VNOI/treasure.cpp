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
template<class T> void minimize(T &A, T B)
{
    A=min(A,B);
}
template<class T> void maximize(T &A, T B)
{
    A=max(A,B);
}
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
ll f[100][96005],a[100],s[100];
void nhap()
{
    int n;
    cin >> n;
    memset(f,100000,sizeof f);
    for(int i = 0 ; i <= 1000;i++)f[0][i]=0;
        for(int i = 1; i <= n ; i++)
        {

            cin >> a[i];
            s[i]=s[i-1]+a[i];
            for(int j = 0 ; j <= s[i] ; j++)
            {
                f[i][j]=f[i-1][j]+a[i];
                f[i][j]=min(f[i][j],min(f[i-1][abs(j-a[i])],f[i-1][j+a[i]]));
                cout << i << " "<< j << " " <<f[i][j] << endl;
            }

        }

        cout << f[n][0] << endl;
}
int main()
{

    fastio();
    // inti();
    nhap();
}




