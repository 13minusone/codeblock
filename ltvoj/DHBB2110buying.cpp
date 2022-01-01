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
#define task "DHBB2110buying"
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
const ll N = 1e5;
const ll mod =1e15+9;
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
ll a[3005],b[3005],c[3005];
ll f[3005][3005][2];
void nhap()
{
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    memset(f,mod,sizeof f);
    f[0][0][0]=0;

    ll res=mod;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0; j <= i ; j++)
        {
            for(int k = 0 ; k < 2 ;k++)
            {
                minimize(f[i+1][j][1],f[i][j][k]+a[i+1]);
                if(k==0)minimize(f[i+1][j][0],f[i][j][0]+b[i+1]-(i-j));
                minimize(f[i+1][j+1][k],f[i][j][k]+c[i+1]-j);
                if(i==n-1)minimize(res,min(f[i+1][j+1][k],f[i+1][j][k]));

            }

        }

    }
    cout << res << endl;

}
int main()
{

    fastio();
    inti();
    nhap();
}




