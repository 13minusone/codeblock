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
#define task "couples"
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
int sub ,m,n;
ll high;
vector<ii>bhigh,blow,ghigh,glow,truyvet;
void nhap()
{
    cin >> sub;
    cin >> m;
    for(int i = 1; i <= m ; i++)
    {
        cin >> high;
        if(high < 0)blow.push_back(ii(abs(high),i));
        else bhigh.push_back(ii(high,i));
    }
    cin >> n;
     for(int i = 1; i <= n ; i++)
    {
        cin >> high;
        if(high < 0)glow.push_back(ii(abs(high),i));
        else ghigh.push_back(ii(high,i));
    }
    int s=0;
    sort(all(bhigh));
    sort(all(blow));
    sort(all(glow));
    sort(all(ghigh));
    int j=0;
    if(SZ(bhigh)!=0)
    {
        for(ii  v : glow)
        if(v.fi > bhigh[j].fi){
            truyvet.push_back(ii(bhigh[j].se,v.se));
            s++;
            j++;
            if(j > SZ(bhigh) -1 )break;
    }
    }
    j=0;
    if(SZ(ghigh)!=0)
    {
        for(ii  v : blow)
        if(v.fi > ghigh[j].fi)
        {
            truyvet.push_back(ii(v.se,ghigh[j].se));
            s++;
            j++;
            if(j > SZ(ghigh)-1)break;

        }
    }
    cout << s << endl;
    for(ii v : truyvet)cout << v.fi << " "<< v.se << endl;
}
int main()
{

    fastio();
    // inti();
    nhap();
}




