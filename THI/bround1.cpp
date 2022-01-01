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
#define task "bround1"
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
int a[55][55];
bool check(int n,int m,int sl,int sr)
{
     if(sr>(m+n-1)*1000||sl>(m+n-1)*1000||(m+n-1)>sl||(m+n-1)>sr)
    {
    return false;
    }
    return true;
}
void solve(int n,int m,ll sl,ll sr,int p)
{
    if(check(n,m,sl,sr)==false){
        cout <<"Case #"<<p<<": Impossible" << endl;
        return ;
    }
    cout <<"Case #"<<p<<": Possible" << endl;
    ll k=sl-n;
    memset(a,0,sizeof a);
    int h=k/(m-1) ;
    a[1][1]=k-(h*(m-2));
    for(int i = 2 ; i < m ; i++) a[1][i]=h;
    for(int i = 1 ; i <= n ; i++) a[i][m]=1;
    k=sr-n;    h=(k/(m-1));
    a[n][1]=k-(h*(m-2));
    for(int i = 2 ;i <m;i++)   a[n][i]=h;
    for(int i = 1 ; i <= n;i++){
    for(int j = 1 ; j <= m ; j++){
        if(a[i][j]==0)a[i][j]=1000;
        cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
void solve1(int n,int m,int sl,int sr,int p)
{
    if(check(n,m,sl,sr)==false){
        cout <<"Case #"<<p<<": Impossible" << endl;
        return ;
    }
    cout <<"Case #"<<p<<": Possible" << endl;
    ll k=sr-n;
    memset(a,0,sizeof a);
    int h=k/(m-1) ;
    a[n][1]=k-(h*(m-2));
    for(int i = 2 ; i < m ; i++) a[n][i]=h;
    for(int i = 1 ; i <= n ; i++) a[i][m]=1;
    k=sl-n;    h=(k/(m-1));
    a[1][1]=k-(h*(m-2));
    for(int i = 2 ;i <m;i++)   a[1][i]=h;
    for(int i = 1 ; i <= n;i++){
    for(int j = 1 ; j <= m ; j++){
        if(a[i][j]==0)a[i][j]=1000;
        cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
void nhap()
{
    int t,n,m;
    ll sl,sr;
    cin >> t;
    for(int i = 1 ;i <= t; i++)
    {
        cin >> n >> m >> sl >> sr;
        if(sl<=sr)solve(n,m,sl,sr,i);
        else solve1(n,m,sl,sr,i);
    }
}
int main()
{

    fastio();
     inti();
    nhap();
}




