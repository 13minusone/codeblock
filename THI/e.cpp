//CODE IS WRITTEN BY 13MINUSONE
#include<bits/stdc++.h>
using namespace std;
#define task "c9"
#define SZ(c) (c).size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define __builtin_popcount __builtin_popcountll
#define all(x) (x).begin(),(x).end()
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define fi first
#define se second
#define For(i,l,r) for(int i = l ; i < r ;i++)
#define Fore(i,l,r) for(int i = l ; i <= r ; i++)
#define Ford(i,l,r) for(int i = l ; i >= r ; i--)
typedef long long ll ;
typedef pair<int,int> ii;
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
const ll N = 1e5 + 5;
const ll mod =1e9+9;
const ll base = 311;
const int block = 488;
int a[500];
ll dp[17][300][2];
ll n;
vector<int>vec;
vector<ll>snt;
void doi(ll k)
{
    while(k!=0)
    {
        vec.push_back(k%10);
        k/=10;
    }
}
ll solve(int pos,int sum,ll num,int state)
{
    if(pos==-1)
    {
        if(!a[sum])
        {
            snt.push_back(num);
            return 1;
        }
        else return 0;
    }
    //if(state&&dp[pos][sum][state]!=-1)return dp[pos][sum][state];
    ll res=0;
    int limit=(state ? 9 : vec[pos]);
    for(int i = 0; i<= limit;i++)
    {
        res+=solve(pos-1,sum+i,num*10+i,state|(pos<limit));
    }
    if(state)dp[pos][sum][state]=res;
    return res;

}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    memset(dp,-1,sizeof dp);
    a[0]=a[1]=1;
    for(int i = 2 ; i * i<= 200;i++)
    {
        if(!a[i])
        for(int j = i *i ;j <=200;j+=i)a[j]=1;
    }
    cin >> n;
    doi(n);
    //for(int i : vec)cout << i;
    cout << solve(SZ(vec)-1,0,0,1);
    //cout << SZ(snt) << endl;
    ll s=0;
    //cout << n;
    for(ll i : snt)
    {
        //cout << i << endl;
        for(ll j : snt)
        {
            if( ll(i + 2*j) == n && i !=j)
            {
                s++;
                //cout << i << " " << j << endl;
            }
            //cout << i << " "<< j << endl;
        }
    }
    cout << s;
}
