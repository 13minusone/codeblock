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
ll solve(int n,ll l,ll r)
{
    ll s=0;
    if(l==r)return l;
    for(int i = 32 ; i >=0 ; i--)
    {
        ll o = 1LL<<i;
        if(getbit(n,i)==0)
        {

            if(s+o<=r)
            {
                s+=o;
            }
        }
        else
        {
            if(s+o<=l)
            {
                s+=o;
            }
        }
    }
    ll p=0;
    if(s<l)
    {
        for(int i = 0 ; i <= 32 ; i++)
        {
                if(getbit(s,i)==0)
                {
                    ll o = 1LL<<i;
                    if(s+o>=l)
                    {
                        if(s+p>=l)
                        {
                            return s+p;
                        }
                        s+=o;

                        return s;
                    }
                    p+=o;
                }
        }
    }
    return s;
}
void nhap()
{
    ll l,m,n,r;
    while(cin >> n>> l >> r)
    {
        //cout << n << l <<r << endl;
        cout << solve(n,l,r) << endl;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}




