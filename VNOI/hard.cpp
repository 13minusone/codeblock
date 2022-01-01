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
set<ll>a;
void nhap()
{
    int n,type;
    ll x;
    cin >> n;
    a.insert(2e18);
    while(n--)
    {
        cin >> type >> x;
        if(type==1)
        {
            if(a.count(x))a.erase(x);
            else a.insert(x);
        }
        else
        {
            if(a.size()<=1||!a.count(1))
            {
                cout << -1 << endl;
            }
            else{
                ll l=1,res=1;
                while(l<x)
                {
                    set<ll>::iterator it =a.upper_bound(l+1);
                    ll t=min(x,*it - 1);
                    ll dis=*(--it);
                    ll ct=(t-l+dis-1)/dis;
                    l+=ct*dis;
                    res+=ct;
                }
                cout << res << endl;
            }
        }
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}




