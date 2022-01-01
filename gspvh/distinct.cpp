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
#define task "distinct"
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
typedef pair<ii,int> iii;
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
int n,m;
map<int,int>last[250005],a[250005],f[250005];
void nhap()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= m ; j++)
        {
            cin >> a[i][j];
        }
    }
    ll maxx=1;
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= m ; j++)
        {
            for(int k = j ; k <= m ; k++)
            {
                ll s=k-j+1;
                if (s == k)
                {
                    maximize(f[s][k],last[s][a[i][s]]);
                }
                else
                {
                    maximize(f[s][k], max(max(f[s][k-1], f[s+1][k]), max(last[s][a[i][k]], last[k][a[i][s]])));
                    if(a[i][s] == a[i][k]) f[s][k] = i;
                }
                 maximize(maxx,(ll)(i - f[s][k]) * (k - s + 1));
            }
        }
        for (int j = 1 ; j <= m ; j++)
        {
            last[j][a[i][j]] = i;
        }
    }
    cout << maxx << endl;
}
int main()
{

    fastio();
     //inti();
    nhap();
}

