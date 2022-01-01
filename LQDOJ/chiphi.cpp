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
int n;
ll x,a[N+5],k,dd[N+5];
unsigned long long s=0;
void nhap()
{
    cin >> n >> x;

    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
        k=x;
        if(i>1)
        {
            if(a[i]>x-a[i-1])
            {
            s+=a[i]-(x-a[i-1]);
            a[i]=x-a[i-1];
            dd[i]=1;
            }
        }
        //cout << i << " "<< s << endl;
    }
    for(int i = 2 ; i <= n ; i++)
    {
        if(a[i]+a[i-1]<x)
        {
            if(dd[i]==1)
            {
                s-=(x-a[i]-a[i-1]);
                a[i]+=(x-a[i]-a[i-1]);
            }
        }
    }
    cout << s << endl;
}
int main()
{

    fastio();
    // inti();
    nhap();
}




