/*
    You are watching a brute force code
        CODE IS WRITTEN BY 13MINUSONE
*/
#include<bits/stdc++.h>
using namespace std;
#define task "c9"
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
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }
const ll N = 1e5 + 5;
const ll mod =1e9+7;
const ll base = 311;
const int block = 488;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void inti()
{
        if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
}
int t,a[N];
ll k;
string d,o;
void add(ll &s,ll b)
{
    s+=b;
    if(s>=mod)s-=mod;
}
string  doi(ll k)
{
    k--;
    string s="";
    while(k!=0)
    {
        s=char( (k%10)+'0')+s;
        k/=10;
    }
    return s;
}
ll dp[20][9*18+1][9*9*18+1];
ll dp_digit(int pos,int modulo1,int modulo2,bool state)
{
    if(pos == SZ(o))
       if(a[modulo1] == 0 && a[modulo2] == 0)return 1;
       else return 0;
    if(state && dp[pos][modulo1][modulo2]!=-1)
        return dp[pos][modulo1][modulo2];
    ll res = 0;
    int limit=(state ? 9: o[pos]-'0');
    for(int i = 0 ; i <= limit ; i++)
    {
        res+=dp_digit( pos+1, modulo1+i , modulo2+i*i , state|(i <limit) );
    }
    if(state)dp[pos][modulo1][modulo2] = res;
    return res;
}
void nhap()
{
    cin >> t;
    memset(dp,-1,sizeof dp);
    a[0]=1;a[1]=1;
    for(int i =2 ; i*i  <= 1500;i++)
    {
        if(a[i] == 0)
        {
            for(ll j = i*i ; j <= 1500 ; j+=i)a[j]=1;
        }
    }
    while(t--)
   {
    cin >> k  >> d;
    string h=doi(k);
    //cout << h << endl;
    o=d;
    ll ans=dp_digit(0,0,0,0);
    o=h;
    cout << dp_digit(0,0,0,0) << " ";
    cout << ans << endl;
   }
}
int main()
{

    fastio();
     inti();
    nhap();
}



