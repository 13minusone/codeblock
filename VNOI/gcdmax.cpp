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
const ll N = 1e6;
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
ll gcdpre[N+5],a[N+5],u;
void nhap()
{
    int n;
    cin >> n ;

    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
        if(i==1)
        {
            gcdpre[1]=a[1];
            u=a[1];
        }
        else
        {
            if(a[i]%u==0)
            {
                gcdpre[i]=u;
            }
            else
            {
                u=__gcd(a[i],u);
                gcdpre[i]=u;
            }
        }
    }
     u=a[n];
   ll maxx=gcdpre[n-1];
    for(int i = n-1 ; i >= 2 ; i--)
    {
        if(gcdpre[i-1]%u==0)
        {
            maxx=max(maxx,u);
        }
        else
        {
            maxx=max(maxx,__gcd(gcdpre[i-1],u));
        }
        u=__gcd(u,a[i]);
    }
    maxx=max(maxx,u);
    cout << maxx << endl;

}
int main()
{

    fastio();
    // inti();
    nhap();
}




