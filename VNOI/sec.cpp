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
const ll N = 5e5 + 5;
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
int trie[N][3],fin[N],d[N],a[N],b,cnt = 0 ;
void them(int b)
{
    int u=0;d[0]++;
    for(int i = 0 ; i < b ; i++)
    {
        if(trie[u][ a[i] ] == 0)trie[u][a[i]]= ++cnt;
        u=trie[u][ a[i] ];
        d[u]++;
    }
    fin[u]++;
    //cout << cnt << endl;
}
int findd(int b)
{
    bool te=true;
    int u=0,ans=0;
    for(int j = 0 ; j < b ;j++)
    {
        if(trie[u][a[j]]!=0){
            u=trie[u][a[j]];
            ans+=fin[u];
            //cout << fin[u] << endl;
        }
        else
        {
            te=false;
            break;
        }
    }
    if(te==true)ans+=d[u]-fin[u];
    return ans;
}
void nhap()
{
    cin >> n >> m;
    //memset(trie,0,sizeof trie);
    //cout << trie[0][1] << endl;
    for(int i = 1; i <= n ; i++)
    {
        cin >> b;
        for(int j= 0 ; j< b ; j++)cin >> a[j];
        them(b);
        //cout << i << " "<< trie[0][1] << endl;
    }
    for(int i = 1 ; i <= m ; i++)
    {
        cin >> b;
        for(int j= 0 ; j< b ; j++)cin >> a[j];
        cout << findd(b) << endl;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}



