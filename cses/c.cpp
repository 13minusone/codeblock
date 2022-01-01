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
#define ll long long
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll maxsize = 100000;
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
int t;
void nhap()
{
    cin >> t;
    while(t--)
    {
    ll n;
    cin >> n;
    ll a=sqrt(n),b;
    b=a;
    if (a*a==n)
    {
        cout << a << " " << 1 << endl;
        continue;
    }else
    {
        a=n-a*a;
    if (a>=b+1){
        cout << b+1 << " "<< 2*(b+1)-a  <<endl;
    }
    else{
        cout << a << " "<< b+1 <<endl;
    }
    }
    }
}
int main()
{
    fastio();
    //init();
    nhap();
}



