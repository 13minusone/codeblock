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
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll N = 2e6;
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
ll dd[N+5],n,a[22];
void sang()
{
    dd[1]=1;
    for(int i = 2 ; i *i <= N; i++)
    {
        if(dd[i]==0)
        {
            for(ll j = i * i ; j<= N;j+=i)dd[j]=1;
        }
    }
}
void nhap()
{
    cin >> n ;
    for(int i = 1; i <= n ; i++)cin >> a[i];
    sang();
    int maxx=0;
    for(int i = 0 ; i < mu2(n) ; i++)
    {
        int sum1=0,sum2=0;
        for(int j = 0 ; j < 20 ; j++)
        {
            if(getbit(i,j)==1)sum1+=a[j+1];
            else sum2+=a[j+1];
        }
        if(dd[abs(sum1-sum2)]==0)maxx=max(maxx,abs(sum1-sum2));
    }
    cout << maxx ;
}
int main()
{

    fastio();
    // inti();
    nhap();
}




