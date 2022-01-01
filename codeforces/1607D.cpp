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
const ll N = 2e5 + 5;
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
int t,a[N],n;
string s;
vector<int>nred,nblue;
void nhap()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 0 ; i < n ; i++)cin >> a[i];
        cin >> s;
        for(int i = 0 ; i < SZ(s) ; i++)
        {
            if(s[i]=='B')
            {
                nblue.push_back(a[i]);
            }
            else
            {
               nred.push_back(a[i]);
            }
        }
        sort(all(nblue));
        sort(all(nred),greater<int>());
        bool check = true;
        for(int i = 0 ; i <SZ(nblue);i++)
            if(nblue[i] >i )check&=true;
            else check&=false;
         for(int i=0; i<SZ(nred); i++)
            if(nred[i] <= (n-i) )check&=true;
            else check&=false;
        if(check)cout << "YES" << endl;
        else cout << "NO" << endl;
        nred.clear();
        nblue.clear();
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}




