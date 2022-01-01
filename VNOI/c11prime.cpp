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
#define ll long long
#define __builtin_popcount __builtin_popcountll
#define all(x) x.begin(),x.end()
#define endl '\n'
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
vector<ll>vec;
map<ll,int>check;
void snt(ll n)
{
    // memset(check,true,sizeof check);
    for(unsigned ll i = 2; i <= n; i++)
    {
        if (check[i]==0)
        {
            vec.push_back(i);
            for (unsigned ll j = i*i; j <= n; j+=i)
            {
                check[ j] = 1;
            }
        }
    }
}
void nhap()
{
    ll n,t=0,dem=0,bien=0;
    cin >> n;
    for(ll i = 2 ; i * i<=n ; i++)
    {
        if(n%i==0)
        {
            if(bien==0)
            {
                t=i;
                dem++;
                bien=i;
            }
            else
            {
                //cout << 1 << endl;
                if(t*bien==i)
                {

                    t*=bien;
                    dem++;
                }
                else
                {
                    cout << 0 << endl;
                    return ;
                }
            }
        }
    }
    if(bien!=0)
    {
        cout << bien << " "<< dem <<endl;
    }
    else
    {
        cout << n << " "<< 1 << endl;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}




