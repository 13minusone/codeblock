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
ll x,y,z,mu10[20];
ll tinh(ll x)
{
    ll s=0;
    while(x!=0)
    {
        s++;
        x/=10;
    }
    return s;
}
void sub()
{
    ll s=0;
    while(s<=z)
    {
        ll k=tinh(x);
        ll o=mu10[k];
        ll p=o-x;
        p/=y;
        p++;
        if(s+p*k<z)
        {
            s+=p*k;
            x=x+p*y;
        }
        else
        {
            if(s+p*k==z)
            {
                cout << x+p*y;
            }
            else
            {

            }
        }

    }
}
void nhap()
{
    cin >>x >>y >> z;
    mu10[0]=1;
    for(int i = 1; i <= 19;i++)
    {
        mu10[i]=mu10[i-1]*10;
    }
    sub();

}
int main()
{

    fastio();
    // inti();
    nhap();
}




