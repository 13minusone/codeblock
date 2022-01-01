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
template<class X, class Y>
bool minimize(X &x, const Y &y)
{
    X eps = 1e-9;
    if (x > y + eps)
    {
        x = y;
        return true;
    }
    else return false;
}
template<class X, class Y>
bool maximize(X &x, const Y &y)
{
    X eps = 1e-9;
    if (x + eps < y)
    {
        x = y;
        return true;
    }
    else return false;
}
template<class T>
T Abs(const T &x)
{
    return (x < 0 ? -x : x);
}
const ll N = 1e9 + 5;
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
ll n;
map<int,int>f;
vector<ll>vec;
ll o=1e6;
void sang(ll m)
{
    f[1]=1;
    for(ll i = 2 ; i <= min(m,o) ; i++)
    {
        if(f.count(i) == 0)
        {
            vec.push_back(i);
            for(ll j = i*i; j<= m; j+=i)
            {
                f[j]=1;
            }
        }
    }
}
ll tim(ll m)
{
    ll s=0;
    while(m != 0)
    {
        if(m>o)
        {
            ll p=m;
            while(true)
            {
                if(f.count(p)==0){
                    if(m-p>1)
                    {
                        m=p;
                        s++;
                        break;
                    }
                }
                p--;
            }
        }
        else
        {
            if(f.count(m) == 0)
            {
                //cout << m << endl;
                s++;
                return s;
            }
            int k = upper_bound(all(vec),m)-vec.begin();
            k--;
            if(m-vec[k] > 1)
            {
                s++;
                m-=vec[k];
            }
            else
            {
                k--;
                s++;
                m-=vec[k];
            }
        }
        //cout << m << endl;
    }
}
void nhap()
{
    cin >> n;
    sang(n);
    if(n==1)cout << -1 <<" " << -1;
    else
    {
        cout << tim(n) << " "<< n/2 <<endl;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}




