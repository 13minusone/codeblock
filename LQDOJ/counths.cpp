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
ll a[8];
bool check(ll s)
{
    for(int i = 1 ; i<= 7 ; i++)
        {
            if(s<a[i])
            {
                return false;
                break;
            }
            if(a[i]<0)
            {
                return false;
                break;
            }
        }
        return true;
}
void nhap()
{
    int t;
    ll x;
    cin >> t;
    while(t--)
    {
        ll s=0;
        for(int i = 1 ; i<= 7 ; i++)
        {
            cin >> x;
            a[i]=x;
            if(i<=3)s+=x;
            else if(i<=6)s-=x;
            else s+=x;
        }
        if(!check(s)) cout << -1 << endl;
        else cout << s << endl;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}




