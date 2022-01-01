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
bool minimize(X &x, const Y &y)
{
    X eps = 1e-9;
    if (x > y + eps)
    {
        x = y;
        return true;
    }
    else return false;
}
template<class X, class Y>
bool maximize(X &x, const Y &y)
{
    X eps = 1e-9;
    if (x + eps < y)
    {
        x = y;
        return true;
    }
    else return false;
}
template<class T>
T Abs(const T &x)
{
    return (x < 0 ? -x : x);
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

int t,n,m;
string s;
ii sol()
{
    int l=0,r=0;
    int mirow=0,micol=0,marow=0,macol=0;
    ii ans=ii(1,1);
    for(char i : s)
    {
        if(i == 'L')l--;
        if(i == 'U')r++;
        if(i == 'D')r--;
        if(i == 'R')l++;
        marow = max(marow, r);
        macol = max(macol, l);
        micol = min(micol, l);
        mirow = min(mirow, r);
        if (macol - micol +1 > m || marow - mirow +1> n) break;
        ans = ii(abs(marow)+1, abs(micol)+1);
    }
    return ans;
}
void nhap()
{

    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        cin >> s;
        ii o=sol();
        cout << o.fi <<  " " << o.se << endl;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}




