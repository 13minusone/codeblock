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
ll x,y;
void nhap()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> x >> y;
        if(__gcd(x,y)!=1)
        {
            ll u=__gcd(x,y);
            x=x/u;
            y=y/u;
        }
        while(y%2==0)
        {
            y/=2;
        }
        while(y%5==0)
        {
            y/=5;
        }
        if(y==1)
        {
            cout << "Yes" <<endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}




