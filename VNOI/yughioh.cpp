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
int n,x;
ll a[N+5],check[N+5];
void snt(ll n)
{
    check[1]=1;
    for(int i = 2 ; i * i<=n;i++)
    {
        if(check[i]==0)
        {
            for(int j = i * i ; j <= n ; j+=i)
            {
                check[j]=1;
            }
        }
    }
}
ll f[N+5],s=0;
vector<int>vec;
void nhap()
{
    cin >> n >> x;
    memset(f,0,sizeof f);
    snt(x);
    f[0]=0;
    for(int i = 1 ;i <= n ; i++)
    {
        cin >> a[i];
        if(a[i]<=1||a[i]>x)
        {
            f[i]=f[i-1];
            continue;
        }
        if(check[a[i]]==0)
        {
            f[i]=f[i-1]+1;
           s++;
        }
        else
        {
            f[i]=f[i-1];
        }
        //cout << i << " "<< f[i] << endl;

    }
   // cout << s << endl;
    ll minn=1000000000;
    for(int i = 1 ; i <=n-s+1 ; i++)
    {
        //cout << i << " "<< f[i+s-1]-f[i-1]  << endl;
       minn=min(minn,s-(f[i+s-1]-f[i-1]));
    }
    cout << minn << endl;
}
int main()
{

    fastio();
    // inti();
    nhap();
}




