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
template<class T> void minimize(T &A, T B)
{
    A=min(A,B);
}
template<class T> void maximize(T &A, T B)
{
    A=max(A,B);
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
ll mu10(ll s)
{
    ll f=1;
    for(int i = 1 ;i<=s;i++)
    {
        f*=10;
    }
    return f;
}
void nhap()
{
    int t;
    ll s,n;
    string xau;
    cin >> t;
    while(t--)
    {
        cin >> s >> n;
        int g=log10(s);
        int f=log10(s-n+1);
        ll m10=mu10(f);
        if(s-100>n)
        {
            cout << s-n+1 << " ";
            for(int i = 1 ; i< n ; i++)
            {
                cout << 1 <<" ";
            }
        }
        else
        {
            int i=0;
            if(n<=10&&s>=n*10)
            {
                for(int i = 1 ; i <= n-1; i++)
                {
                    cout << 10 << " ";
                }
                cout << s-10*(n-1) << " ";
            }
            else
            {
              ll i=s/10;
              ll h=n-i;
              for(int j = 1 ; j<=h;j++)
              {
                  cout << 1 << " ";
              }
              if(s-h*1>=10)
              {
                  for(int j = 1 ; j <=i-h;j++)
              {
                  cout << 10 << " ";
              }
              }
              else
              {
                  cout << s- h*1 << " ";
              }
            }

        }
        cout << endl;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}




