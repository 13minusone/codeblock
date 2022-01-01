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
string k;
int d,a[500];
ll dp[16][300][2];
ll n,num=0;
ll doi(string s)
{
    ll sum =0;
    for(char c  : s)
    {
        sum=sum*10+(c-'0');
    }
    return sum;
}
set<ll>snt;
ll dp_digit(int pos,int modulo,ll sum,bool state)
{
    if(pos >= SZ(k))
       if(a[modulo] ==0)
       {
            set<ll>::iterator it = snt.lower_bound(n-2*sum);
           if(it!=snt.end())
               if(*it == n-2*sum)num++;
           it = snt.lower_bound(n-sum);
           if(it!=snt.end())
           {
               if(*it==n-sum)
                    if(*it %2==0)num++;
           }
            snt.insert(sum);
            return 1;
       }
       else return 0;
    if(dp[pos][modulo][state]!=-1)
        return dp[pos][modulo][state];
    ll res = 0;
    int limit=(state ? k[pos]-'0': 9);
    for(int i = 0 ; i <= limit ; i++)
    {
        res+=dp_digit(pos+1,(modulo+i),sum*10+i,state&(i == limit));
    }
    dp[pos][modulo][state] = res;
    return res;
}
void nhap()
{
    cin >> k  ;
    for(int i = 2 ; i * i<= 200;i++)
    {
        if(!a[i])
        for(int j = i *i ;j <=200;j+=i)a[j]=1;
    }
    n=doi(k);
    //cout << n << endl;
    memset(dp,-1,sizeof dp);
    cout <<dp_digit(0,0,0,1);
    //add(ans,mod-1);
    cout << num*2;
}
int main()
{

    fastio();
     inti();
    nhap();
}



